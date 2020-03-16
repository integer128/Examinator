#include "connectionmanager.h"

#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>
#include <QStandardPaths>
#include <QDir>

using namespace DBTypes;

namespace db
{
namespace
{
class DBCloser
{
public:
    void operator() (QSqlDatabase* db)
    {
        db->close();
        QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
        delete db;
    }
};
}

struct ConnectionManager::ConnectionManagerPrivate
{
    std::unique_ptr<QSqlDatabase, DBCloser> m_database;
    QString m_dbPath;
    DBState m_state { DBState::OK };
    bool m_isValid { true };

    bool setup();
    bool setupWorkspace();
    bool setupTables();
    void setIsValid(bool isValid);
};

ConnectionManager& ConnectionManager::instance()
{
    static ConnectionManager instance {};
    return instance;
}

QString ConnectionManager::databasePath() const
{
    return m_d->m_dbPath;
}

DBState ConnectionManager::state() const
{
    return m_d->m_state;
}

bool ConnectionManager::ConnectionManagerPrivate::setup()
{
    const QString driver { "QSQLITE" };

    if (!QSqlDatabase::isDriverAvailable(driver))
    {
        m_state = DBState::ERROR_NO_DRIVER;
        qWarning() << "Driver " << driver << " is not available.";
        return false;
    }

    if (!setupWorkspace())
    {
        m_state = DBState::ERROR_WORKSPACE;
        qCritical() << "Workspace setup failed!";
        return false;
    }

    auto* db = new QSqlDatabase { QSqlDatabase::addDatabase(driver) };
    m_database.reset(db);
    m_database->setDatabaseName(m_dbPath);

    qDebug() << "Database name: " << m_database->databaseName();

    if (!m_database->open())
    {
        m_state = DBState::ERROR_OPENING;
        qCritical() << "Error in opening DB " << m_database->databaseName()
                    << " reason: " <<  m_database->lastError().text();
        return false;
    }

    return setupTables();
}

bool ConnectionManager::ConnectionManagerPrivate::setupWorkspace()
{
    const QString databaseName { "ContactsDB" };

    const QString location { QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) };
    const QString fullPath { location + "/" + databaseName };

    m_dbPath = fullPath;

    QDir dbDirectory { location };
    if (!dbDirectory.exists())
    {
        const bool creationResult { dbDirectory.mkpath(location) };
        qWarning() << "DB directory not exist, creating result: " << creationResult;
    }
    qDebug() << "Data path: " << fullPath;

    return dbDirectory.exists();
}

bool ConnectionManager::ConnectionManagerPrivate::setupTables()
{
    bool result { true };

    std::vector<QSqlQuery> creationQueries =
    {
        QSqlQuery
        {
            "CREATE TABLE IF NOT EXISTS Contacts"
            "("
            "login TEXT,"
            "password TEXT,"
            "fio TEXT,"
            "number INTEGER,"
            "role INTEGER,"
            "UNIQUE(login, number)"
            ")"
        }
    };

    for (auto& query : creationQueries)
    {
        if (!query.exec())
        {
            result = false;
            m_state = DBState::ERROR_TABLES;
            qWarning() << "Table creation failed. Reason: " << query.lastError();
        }
        else
        {
            qWarning() << "Table successfully created! Query: \n" << query.lastQuery();
        }
    }

    return result;
}

void ConnectionManager::ConnectionManagerPrivate::setIsValid(bool isValid)
{
    m_isValid = isValid;
}

bool ConnectionManager::isValid() const
{
    return m_d->m_isValid && m_d->m_database->isValid();
}

ConnectionManager::ConnectionManager()
    : m_d { new ConnectionManagerPrivate {} }
{
    const bool setupResult { m_d->setup() };
    m_d->setIsValid(setupResult);
}

ConnectionManager::~ConnectionManager()
{

}
}
