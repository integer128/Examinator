#pragma once

#include "dbtypes.h"
#include "executor.h"

namespace database
{
class Selector
{
public:
    DBPair selectAll(const QString& tableName);
    DBPair select(const QString& tableName, const QString& login);
    std::pair<DBResult, std::vector<QVariant>>
    selectTheoryById(const short& id);

private:
    Executor m_executor;
    QString generateQuery(const QString& tableName) const;
};
}
