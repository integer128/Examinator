#pragma once

#include <QVariantList>

#include "dbtypes.h"
#include "executor.h"

namespace db
{
class Selector
{
public:
    std::pair<DBTypes::DBResult, std::vector<QVariantList> > selectAll(const QString& tableName);
    std::pair<DBTypes::DBResult, std::vector<QVariantList> > select(const QString& tableName, const QString& login);

private:
    Executor m_executor;
    QString generateQuery(const QString& tableName) const;
};
}
