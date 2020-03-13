#pragma once

#include "dbtypes.h"
#include "executor.h"

#include <QString>
#include <QVariantList>

#include <vector>

class Selector
{
public:
    std::pair<DBResult, std::vector<DBEntry> > selectAll(const QString& tableName);

    template<typename ...Args> std::pair<DBResult, std::vector<DBEntry> >
    select(const QString& tableName, Args ...arguments);

private:
    Executor m_executor;

    QString generateQuery(const QString& tableName) const;

    template<typename ...Arguments>
    QString generateQuery(const QString& tableName, Arguments...arguments) const;
};
