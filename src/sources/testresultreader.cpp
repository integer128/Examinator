#include "testresultreader.h"
#include "dbmapper.h"

#include <vector>

TestResultReader::TestResultReader()
    : m_processor { new database::Processor {} }
{

}

QList<TestResult> TestResultReader::requestTestResults()
{
    using namespace database;
    DBResult result;
    std::vector<QVariantList> list;

    std::tie(result, list) =
            m_processor->requestTableData(DBTables::Contacts_Answers);

    if(result == DBResult::OK)
    {
        return transform(list);
    }
    return QList<TestResult>();
}

QList<TestResult> TestResultReader::transform(const std::vector<QVariantList> &variant)
{
    QList<TestResult> target;

    std::transform(variant.begin(),variant.end(), std::back_inserter(target),
                   [](const QVariant& entry)
    {
        QSequentialIterable value = entry.value<QSequentialIterable>();
        return TestResult(value.at(1).toInt(),
                          value.at(2).toInt(),
                          value.at(3).toDateTime());
    });
    return target;
}
