#include "manipulator.h"
#include "dbmapper.h"

#include <QString>
#include <QVariant>

#include <sstream>

namespace database
{

std::pair<DBResult, int> Manipulator::insertRow(const QString& tableName,
                                                const QVariantList& rowData)
{
    const QString& query { generateInsertQuery(tableName, rowData.size()) };
    const std::pair<DBResult, QSqlQuery>& result
    {
        m_executor.execute(query, rowData)
    };

    return std::make_pair(result.first, result.second.lastInsertId().toInt());
}

void Manipulator::saveChanges(const TheoryData &data)
{
    const QString query
    {
        "UPDATE Theory SET "
        "text='" + data.theory + "',"
        "text_visible='" + QString::number(data.visible) + "'"
        " WHERE text_id='" + QString::number(data.theory_id, 10) +
        "';"
    };
    m_executor.execute(query);
}

QString Manipulator::generateBindString(size_t paramCount) const
{
    std::ostringstream bindings;
    std::fill_n(std::ostream_iterator<std::string>(bindings), paramCount, "?,");
    std::string bindString = bindings.str();
    bindString.pop_back(); // ","

    return QString::fromStdString(bindString);
}

QString Manipulator::generateInsertQuery(const QString& tableName,
                                         size_t paramCount) const
{
    QString query
    {
        "INSERT INTO " + tableName +
        " (" +
        tablesMapping.at(tableName) +
        ")" +
        " VALUES ("
    };

    query += generateBindString(paramCount);
    query += ")";

    return query;
}
}
