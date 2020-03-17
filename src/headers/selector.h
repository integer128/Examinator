#pragma once

#include "dbtypes.h"
#include "executor.h"

namespace database
{
class Selector
{
public:
    DBVariantList selectAll(const QString& tableName);
    DBVariantList select(const QString& tableName, const QString& login);
    DBVariant selectTheoryById(const short& id);

private:
    Executor m_executor;
    QString generateQuery(const QString& tableName) const;
};
}
