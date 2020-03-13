#pragma once

#include "connectionmanager.h"
#include "dbtypes.h"

#include <utility>

#include <QSqlQuery>
#include <QVariantList>

class Executor
{
public:
    Executor();
    Q_DISABLE_COPY(Executor)

    std::pair<DBResult, QSqlQuery> execute(const QString &queryText, const QVariantList& args = {});

private:
    ConnectionManager& m_connectionManager;
};
