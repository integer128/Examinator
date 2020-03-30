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
    std::tie(resultState, result) = m_d->selector.selectAll(tableMapper.at(table));

    return std::make_pair(resultState, std::move(result));
}

DBVariantList Processor::requestUserData(DBTables table, const QString& login)
{
    std::vector<QVariantList> result;
    DBResult resultState;
    std::tie(resultState, result) = m_d->selector.select(tableMapper.at(table),
                                                         login);

    return std::make_pair(resultState, std::move(result));
}

DBVariant Processor::requestTheoryDataById(const int &id)
{
    std::vector<QVariant> result;
    DBResult resultState;
    std::tie(resultState, result) = m_d->selector.selectTheoryById(id);

    return std::make_pair(resultState, std::move(result));
}

std::vector<Test> Processor::requestTestQuestionsAndAnswers()
{
    std::vector<Test> result;
    DBResult resultState;
    std::tie(resultState, result) = m_d->selector.selectQuestionsAndAnswers();

    return result;
}

void Processor::requestSaveChanges(const TheoryData& data)
{
    m_d->manipulator.saveChanges(data);
}

void Processor::requestSaveResult(const int &userId, const int &points)
{
    DBResult resultState;
    int result;
    std::tie(resultState, result) = m_d->manipulator.insertRow(
                tableMapper.at(DBTables::Contacts_Answers),
                QVariantList { userId, points, QDateTime::currentDateTime() });
}

void Processor::requestTestUpdate(const Test &test)
{
    m_d->manipulator.updateTest(test);
}

void Processor::requestAddTest(const Test &test)
{
    m_d->manipulator.addTest(test);
}
}
