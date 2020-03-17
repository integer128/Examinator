#include "processor.h"
#include "manipulator.h"
#include "selector.h"
#include "dbmapper.h"

namespace database
{
struct Processor::ProcessorPrivate
{
    Manipulator manipulator;
    Selector selector;
};

Processor::Processor()
    : m_d { new ProcessorPrivate {} }
{

}

Processor::~Processor()
{

}

DBVariantList Processor::requestTableData(DBTables table)
{
    std::vector<QVariantList> result;
    DBResult resultState;
    std::tie(resultState, result)
            = m_d->selector.selectAll(tableMapper.at(table));

    return std::make_pair(resultState, std::move(result));
}

DBVariantList Processor::requestUserData(DBTables table, const QString& login)
{
    std::vector<QVariantList> result;
    DBResult resultState;
    std::tie(resultState, result )
            = m_d->selector.select(tableMapper.at(table), login);

    return std::make_pair(resultState, std::move(result));
}

DBVariant Processor::requestTheoryDataById(const short &id)
{
    std::vector<QVariant> result;
    DBResult resultState;
    std::tie(resultState, result) = m_d->selector.selectTheoryById(id);

    return std::make_pair(resultState, std::move(result));
}
}
