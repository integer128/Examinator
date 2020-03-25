#include "testworker.h"

TestWorker::TestWorker()
    : m_processor { new database::Processor {} }
{

}

std::vector<Test> TestWorker::requestTests()
{
    return m_processor->requestTestQuestionsAndAnswers();
}

void TestWorker::requestSaveResult(const int &userId, const int &points)
{
    m_processor->requestSaveResult(userId, points);
}
