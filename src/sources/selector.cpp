#include "selector.h"
#include "executor.h"

#include <QSqlQuery>
#include <QSqlRecord>

namespace database
{
DBVariantList Selector::selectAll(const QString &tableName)
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
            const QSqlRecord &resultRecord = resultQuery.record();
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

DBVariantList Selector::select(const QString &tableName, const QString &login)
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
            const QSqlRecord &record = resultQuery.record();
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
            const QSqlRecord &record = resultQuery.record();
            for(int i = 0; i < record.count(); ++i)
            {
                returnData.push_back(record.value(i));
            }
        }
    }
    return { result, returnData };
}

std::pair<DBResult, std::vector<Test> > Selector::selectQuestionsAndAnswers()
{
    QString query
    {
        "SELECT id, question, points, answers, true_answer "
        "FROM Questions, Answers "
        "WHERE id = test_id"
    };

    std::vector<Test> returnData;
    DBResult result;
    QSqlQuery resultQuery;
    std::tie(result, resultQuery) = m_executor.execute(query);

    if(result == DBResult::OK)
    {
        while (resultQuery.next())
        {
            const QSqlRecord &record = resultQuery.record();
            Test test;
            test.s_id = record.value(0).toInt();
            test.s_question = record.value(1).toString();
            test.s_points = record.value(2).toInt();

            QString answers = record.value(3).toString();
            QStringList answersList = answers.split(";");


            for(int i = 0; i < answersList.count(); ++i)
            {
                test.answers.push_back(answersList[i]);
            }

            test.s_trueIndex = answersList.indexOf(record.value(4).toString());
            returnData.push_back(test);
        }
    }
    return { result, returnData };
}

QString Selector::generateQuery(const QString &tableName) const
{
    QString query { "SELECT rowid, * FROM " + tableName };
    return query;
}
}
