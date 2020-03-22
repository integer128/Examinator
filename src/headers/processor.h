#pragma once

#include "dbtypes.h"
#include "Types.h"

#include <memory>

namespace database
{
class Processor
{
public:
    Processor();
    ~Processor();

    DBVariantList requestTableData(DBTables table);
    DBVariantList requestUserData(DBTables table, const QString& login);
    DBVariant requestTheoryDataById(const int& id);

    void requestSaveChanges(const TheoryData &data);

private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;
};
}
