#pragma once

#include "dbtypes.h"
#include "executor.h"
#include "Types.h"

namespace database
{
class Selector
{
public:
    DBVariantList selectAll(const QString &tableName);
    DBVariantList select(const QString &tableName, const QString &login);
    DBVariant selectTheoryById(const int &id);
    std::pair<DBResult, std::vector<Test> > selectQuestionsAndAnswers();

private:
    Executor m_executor;
    QString generateQuery(const QString &tableName) const;
};
}
