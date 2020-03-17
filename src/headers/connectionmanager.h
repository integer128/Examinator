#pragma once

#include <QObject>

#include <memory>

#include "dbtypes.h"

namespace database
{
class ConnectionManager
{
public:
    Q_DISABLE_COPY(ConnectionManager)
    ~ConnectionManager();

    static ConnectionManager& instance();

    QString databasePath() const;
    DBState state() const;

    bool isValid() const;

private:
    ConnectionManager();
    struct ConnectionManagerPrivate;
    std::unique_ptr<ConnectionManagerPrivate> m_d;
};
}
