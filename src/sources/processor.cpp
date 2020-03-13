#include "processor.h"
#include "selector.h"
#include "dbmapper.h"
#include "manipulator.h"

struct Processor::ProcessorPrivate
{
    Selector selector;
    Manipulator manipulator;
};

Processor::Processor()
    : m_d { new ProcessorPrivate {} }
{

}

Processor::~Processor()
{

}

template<typename ...Arguments>
std::pair<DBResult, std::vector<DBEntry> > Processor::requestTableData(DBTables table, Arguments ...arguments)
{
    //const auto& result { m_d->selector.selectAll(TableMapper.at(table)) };
    const auto& result { m_d->selector.select(TableMapper.at(table), arguments...) };
    return result;
}
