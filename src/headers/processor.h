#pragma once

#include "dbtypes.h"

#include <memory>
#include <vector>

#include <QVariantList>

namespace db
{
class Processor
{
public:
    Processor();
    ~Processor();

    std::pair<DBTypes::DBResult, std::vector<QVariantList> > requestTableData(DBTypes::DBTables table);
    std::pair<DBTypes::DBResult, std::vector<QVariantList> > requestUserData(DBTypes::DBTables table, const QString& login);

private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;
};
}
