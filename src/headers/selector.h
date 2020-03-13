#pragma once

#include "dbtypes.h"
#include "executor.h"

#include <QString>
#include <QVariantList>

#include <vector>

#include "utility.h"

class Selector
{
public:
    std::pair<DBResult, std::vector<DBEntry> > selectAll(const QString& tableName);

    template<typename ...Args, typename ...Cond> std::pair<DBResult, std::vector<DBEntry> >
    select(const QString& tableName, Args ...arguments, Cond ...conditions);

private:
    Executor m_executor;

    QString generateQuery(const QString& tableName) const;

    template<typename ...T>
    QString generateQuery(const QString& tableName, T...t) const;

    template<typename ...Args, typename ...Conditions>
    QString generateQuery(const QString& tableName, Args ...args, Conditions ...conditions) const;
};
