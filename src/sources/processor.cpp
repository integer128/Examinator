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

std::pair<DBResult, std::vector<DBEntry> > Processor::requestTableData(DBTables table)
{
    const auto& result { m_d->selector.selectAll(TableMapper.at(table)) };
    return result;
}
