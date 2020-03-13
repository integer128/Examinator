#include "connectionmanager.h"
#include "dbtypes.h"

#include <QString>
#include <QSqlDatabase>
#include <QDebug>
#include <QStandardPaths>
#include <QDir>
#include <QSqlError>
#include <QSqlQuery>

#include <vector>

namespace
{
    class DBCloser
    {
    public:
        void operator()(QSqlDatabase* db)
        {
            db->close();
            QSqlDatabase::removeDatabase(QSqlDatabase::defaultConnection);
            delete db;
        }
    };
}

struct ConnectionManager::ConnectionManagerPrivate
{
    std::unique_ptr<QSqlDatabase, DBCloser> database;
    QString dbPath { "D:\\Repository\\Examinator\\src\\database\\examinator.db" };
    bool isValid { true };
    DBState state { DBState::OK };

    bool setup();
    bool setupWorkspace();
    bool setupTabels();
};

ConnectionManager &ConnectionManager::instance()
{
    static ConnectionManager instance;
    return instance;
}

bool ConnectionManager::isValid() const
{
    return m_d->isValid;
}

ConnectionManager::ConnectionManager()
    : m_d { new ConnectionManagerPrivate {} }
{
    const bool setupResult { m_d->setup() };
    m_d->isValid = setupResult;
}

ConnectionManager::~ConnectionManager()
{

}

bool ConnectionManager::ConnectionManagerPrivate::setup()
{
    const QString driver { "QSQLITE" };

    if(!QSqlDatabase::isDriverAvailable(driver))
    {
        state = DBState::ERROR_NO_DRIVER;
        qCritical() << "Driver" << driver << "is not available";
        return false;
    }

    if(!setupWorkspace())
    {
        state = DBState::ERROR_WORKSPACE;
        qCritical() << "Workspace setup failed!";
        return false;
    }

    database.reset(new QSqlDatabase { QSqlDatabase::addDatabase("QSQLITE") });
    database->setDatabaseName(dbPath);

    qDebug() << "Database name: " << database->databaseName();

    if(!database->open())
    {
        state = DBState::ERROR_OPENING;
        qCritical() << "Error in opening DB" << database->databaseName() << " reason " << database->lastError().text();
        return false;
    }
    return setupTabels();
}

bool ConnectionManager::ConnectionManagerPrivate::setupWorkspace()
{
    static const QString databaseName { "examinator" };
    const QString location { QStandardPaths::writableLocation(QStandardPaths::AppDataLocation) };
    const QString fullPath { location + "/" + databaseName };

    dbPath = fullPath;

    QDir dbDirectory { location };

    if(!dbDirectory.exists())
    {
        const bool creationResult { dbDirectory.mkpath(location) };
        qInfo() << "DB directory not exist, creating result: " << creationResult;
    }
    qDebug() << "Data path: " << fullPath;

    return dbDirectory.exists();
}

bool ConnectionManager::ConnectionManagerPrivate::setupTabels()
{
    bool result { true };

    std::vector<QSqlQuery> creationQueries {
        QSqlQuery {
            "CREATE TABLE IF NOT EXISTS users"
            "("
            "number INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
            "login VARCHAR UNIQUE NOT NULL,"
            "password VARCHAR NOT NULL,"
            "role INTEGER NOT NULL DEFAULT(1),"
            "last_exam DATETIME,"
            "fio VARCHAR"
            ")"
        },
        QSqlQuery {
            "CREATE TABLE IF NOT EXISTS theory"
            "("
            "text_id INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL UNIQUE,"
            "name VARCHAR NOT NULL,"
            "data VARCHAR NOT NULL"
            ")"
        }
    };

    for(auto& query : creationQueries)
    {
        if(query.exec())
        {
            result = false;
            state = DBState::ERROR_TABLES;
            qWarning() << "Table creation failed. Reason: " << query.lastError() << "; query: " << query.lastQuery();
        }
        else
        {
            qInfo() << "Talbe successfully created: query: \n" << query.lastQuery();
        }
    }
    return result;
}
