#include "selector.h"

#include <QSqlQuery>
#include <QSqlRecord>

std::pair<DBResult, std::vector<DBEntry> > Selector::selectAll(const QString &tableName)
{
    QString query { generateQuery(tableName) };

    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    std::vector<DBEntry> returnData;
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


template<typename ...Args, typename ...Cond>
std::pair<DBResult, std::vector<DBEntry> > Selector::select(const QString &tableName, Args ...arguments, Cond ...conditions)
{
    QString query;
    QString args[] = { utility::to_str(arguments)... };
    QString cond[] = { utility::to_str(conditions)... };

    if(cond->size() == 0) query = generateQuery(tableName, arguments...);
    if(args->size() == 0) query = generateQuery(tableName);

    query = generateQuery(tableName, arguments..., conditions...);

    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    std::vector<DBEntry> returnData;

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

template<typename ...T>
QString Selector::generateQuery(const QString &tableName, T ...t) const
{
    QString query { "SELECT " };
    QString tmp[] { utility::to_str(t)... };

    for(int i = 0; i <= tmp->size(); ++i)
    {
        query +=  tmp[i];
        if(i != tmp->size()) query += ",";
    }

    query += " FROM " + tableName;

    return query;
}

template<typename ...Args, typename ...Conditions>
QString Selector::generateQuery(const QString &tableName, Args ...args, Conditions ...conditions) const
{
    QString query { "SELECT " };
    QString arguments[] { utility::to_str(args)... };
    QString con[] { utility::to_str(conditions)... };

    //add arguments
    for(int i = 0; i < arguments->size(); ++i)
    {
        query += arguments[i];
        if(i != arguments->size()) query += ",";
    }

    query += " FROM " + tableName;

    //add conditions
    for(int i = 0; i < con->size(); ++i)
    {
        query += con[i];
        if(i != con->size()) query += " AND ";
    }

    return query;
}
