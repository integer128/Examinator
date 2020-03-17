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

DBPair Processor::requestTableData(DBTables table)
{
    std::vector<QVariantList> result;
    DBResult resultState;
    std::tie(resultState, result)
            = m_d->selector.selectAll(tableMapper.at(table));

    return std::make_pair(resultState, std::move(result));
}

DBPair Processor::requestUserData(DBTables table, const QString& login)
{
    std::vector<QVariantList> result;
    DBResult resultState;
    std::tie(resultState, result )
            = m_d->selector.select(tableMapper.at(table), login);

    return std::make_pair(resultState, std::move(result));
}
}
