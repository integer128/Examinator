#include "selector.h"
#include "utility.h"

#include <QSqlQuery>
#include <QSqlRecord>

std::pair<DBResult, std::vector<DBEntry> > Selector::selectAll(const QString &tableName)
{
    QString query { generateQuery(tableName) };

    DBResult result;
    QSqlQuery resultQuery;
    std::vector<DBEntry> returnData;
    std::tie(result, resultQuery) = m_executor.execute(query);

    if(result == DBResult::OK)
    {
        while(resultQuery.next())
        {
            const QSqlRecord& entryRecord { resultQuery.record() };
            QVariantList entryData;
            entryData.reserve(entryRecord.count());

            for(int i = 0; i < entryRecord.count(); ++i)
            {
                entryData.push_back(entryRecord.value(i));
            }

            returnData.emplace_back(std::move(entryData));
        }
    }
    return { result, returnData };
}


template<typename ...Args>
std::pair<DBResult, std::vector<DBEntry> > Selector::select(const QString &tableName, Args ...arguments)
{
    QString query;
    QString args[] = { utility::to_str(arguments)... };

    if(args->size() == 0)
    {
        query = generateQuery(tableName, arguments...);
    }
    else
    {
        query = generateQuery(tableName);
    }

    DBResult result;
    QSqlQuery resultQuery;
    std::vector<DBEntry> returnData;
    std::tie(result, resultQuery) = m_executor.execute(query);

    if(result == DBResult::OK)
    {
        while(resultQuery.next())
        {
            const QSqlRecord& entryRecord { resultQuery.record() };
            QVariantList entryData;
            entryData.reserve(entryRecord.count());

            for(int i = 0; i < entryRecord.count(); ++i)
            {
                entryData.push_back(entryRecord.value(i));
            }
            returnData.emplace_back(std::move(entryData));
        }
    }
    return { result, returnData };
}

QString Selector::generateQuery(const QString &tableName) const
{
    QString query { "SELECT rowid, * FROM " + tableName };
    return query;
}

template<typename ...Arguments>
QString Selector::generateQuery(const QString &tableName, Arguments ...arguments) const
{
    QString query { "SELECT " };
    QString tmp[] { utility::to_str(arguments)... };

    const int conditionIndex = tmp->indexOf(":");

    for(int i = 0; i < conditionIndex; ++i)
    {
        query += tmp[i];
        if(i != conditionIndex) query += ",";
    }

    query += " FROM " + tableName;

    if(conditionIndex)
    {
        query += " WHERE ";
        for(int i = conditionIndex + 1; i < tmp->size(); i++)
        {
            query += tmp[i];

            if(i != tmp->size()) query += " AND ";
        }
    }

    return query;
}
