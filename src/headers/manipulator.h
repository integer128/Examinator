#pragma once

#include "executor.h"
#include "dbtypes.h"

class Manipulator
{
public:
    Manipulator();
    std::pair<DBResult, DBIndex> insertRow(const QString& tableName, const QVariantList& recordData);

private:
    Executor m_executor;
    QString generateBindString(size_t recordSize) const;
    QString generateInsertQuery(const QString& tableName, size_t recordSize) const;
};
