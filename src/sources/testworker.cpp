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

void TestWorker::requestUpdateTest(const int &testId, const QString &question, const QString &answer1, const QString &answer2, const QString &answer3, const QString &trueAnswer, const int &points)
{
    Test test;
    test.s_id = testId;
    test.answers.push_back(answer1);
    test.answers.push_back(answer2);
    test.answers.push_back(answer3);
    test.s_question = question;
    for(int i = 0; i < 3; i++)
    {
        if(test.answers[i] == trueAnswer)
        {
            test.s_trueIndex = i;
        }
    }
    test.s_points = points;
    m_processor->requestTestUpdate(test);
}
