#pragma once

#include <memory>

#include <QObject>

#include "dbtypes.h"

namespace db
{
class ConnectionManager
{
public:
    Q_DISABLE_COPY(ConnectionManager)
    ~ConnectionManager();
    static ConnectionManager& instance();

    QString databasePath() const;
    DBTypes::DBState state() const;

    bool isValid() const;

private:
    ConnectionManager();
    struct ConnectionManagerPrivate;
    std::unique_ptr<ConnectionManagerPrivate> m_d;
};
}
