#pragma once

#include "connectionmanager.h"

#include <QSqlQuery>

namespace database
{
class Executor
{
public:
    Executor();
    Q_DISABLE_COPY(Executor)

    std::pair<DBResult, QSqlQuery> execute(const QString& queryText,
                                           const QVariantList& args = {});

private:
    ConnectionManager& m_connectionManager;
};
}
