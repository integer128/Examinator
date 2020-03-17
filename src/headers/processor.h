#pragma once

#include "dbtypes.h"

#include <memory>

namespace database
{
class Processor
{
public:
    Processor();
    ~Processor();

    DBPair requestTableData(DBTables table);
    DBPair requestUserData(DBTables table, const QString& login);

private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;
};
}
