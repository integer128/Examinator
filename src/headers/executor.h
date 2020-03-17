#pragma once

#include <QMap>
#include <QSqlQuery>

#include <connectionmanager.h>

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
