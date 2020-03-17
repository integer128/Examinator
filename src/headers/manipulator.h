#pragma once

#include "executor.h"
#include "dbtypes.h"

namespace database
{
class Manipulator
{
public:
    std::pair<DBResult, int> insertRow(const QString& tableName,
                                       const QVariantList& rowData);

private:
    Executor m_executor;
    QString generateBindString(size_t paramCount) const;
    QString generateInsertQuery(const QString& tableName,
                                size_t paramCount) const;
    QString generateSetString(const QVector<QString>& columns,
                              const QVariantList& values) const;
};
}

