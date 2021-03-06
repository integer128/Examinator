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
    DBVariantList requestUserData(DBTables table, const QString &login);
    DBVariant requestTheoryDataById(const int &id);
    std::vector<Test> requestTestQuestionsAndAnswers();

    void requestSaveChanges(const TheoryData &data);
    void requestSaveResult(const int &userId, const int &points);
    void requestTestUpdate(const Test &test);
    void requestAddTest(const Test &test);

private:
    struct ProcessorPrivate;
    std::unique_ptr<ProcessorPrivate> m_d;
};
}
