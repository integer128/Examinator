#include "selector.h"
#include "executor.h"

#include <QSqlQuery>
#include <QSqlRecord>
#include <QString>

namespace database
{
DBVariantList Selector::selectAll(const QString& tableName)
{
    QString query { generateQuery(tableName) };
    std::vector<QVariantList> returnData;
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    if (result == DBResult::OK)
    {
        while (resultQuery.next())
        {
            const QSqlRecord& resultRecord = resultQuery.record();
            QVariantList result;

            for (int i = 0; i < resultRecord.count(); ++i)
            {
                result.push_back(resultRecord.value(i));
            }
            returnData.push_back(std::move(result));
        }
    }
    return { result, returnData };
}

DBVariantList Selector::select(const QString& tableName, const QString& login)
{
    QString query
    {
        "SELECT * FROM " + tableName +
        " WHERE login='" + login + "';"
    };

    std::vector<QVariantList> returnData;
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    if(result == DBResult::OK)
    {
        while(resultQuery.next())
        {
            const QSqlRecord& record = resultQuery.record();
            QVariantList list;

            for(int i = 0; i < record.count(); ++i)
            {
                list.push_back(record.value(i));
            }
            returnData.push_back(std::move(list));
        }
    }
    return { result, returnData };
}

DBVariant Selector::selectTheoryById(const int &id)
{
    QString query
    {
      "SELECT * FROM Theory WHERE text_id='" +
       QString::number(id, 10) + "';"
    };

    std::vector<QVariant> returnData;
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    if(result == DBResult::OK)
    {
        while(resultQuery.next())
        {
            const QSqlRecord& record = resultQuery.record();
            for(int i = 0; i < record.count(); ++i)
            {
                returnData.push_back(record.value(i));
            }
        }
    }
    return { result, returnData };
}

QString Selector::generateQuery(const QString& tableName) const
{
    QString query = "SELECT rowid, * FROM " + tableName;
    return query;
}
}
