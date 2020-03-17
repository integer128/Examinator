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

private:
    Executor m_executor;
    QString generateQuery(const QString& tableName) const;
};
}
