#include "processor.h"
#include "manipulator.h"
#include "selector.h"
#include "dbmapper.h"

namespace db
{
struct Processor::ProcessorPrivate
{
    Manipulator manipulator;
    Selector selector;
};

db::Processor::Processor()
    : m_d { new ProcessorPrivate {} }
{

}

Processor::~Processor()
{

}

std::pair<DBTypes::DBResult, std::vector<QVariantList> > Processor::requestTableData(DBTypes::DBTables table)
{
    std::vector<QVariantList> result;
    DBTypes::DBResult resultState;
    std::tie(resultState, result) = m_d->selector.selectAll(tableMapper.at(table));

    return std::make_pair(resultState, std::move(result));
}

std::pair<DBTypes::DBResult, std::vector<QVariantList> > Processor::requestUserData(DBTypes::DBTables table, const QString& login)
{
    std::vector<QVariantList> result;
    DBTypes::DBResult resultState;
    std::tie(resultState, result ) = m_d->selector.select(tableMapper.at(table), login);

    return std::make_pair(resultState, std::move(result));
}
}
