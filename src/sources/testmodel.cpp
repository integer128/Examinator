#include "testmodel.h"

#include <algorithm>
#include <random>

TestModel::TestModel()
{

}

int TestModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_tests.size();
}

QVariant TestModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index))
    {
        return {};
    }

    const Test& test = m_tests.at(index.row());

    switch (role)
    {
    case Roles::TestId:     return QVariant::fromValue(test.s_id);
    case Roles::Question:   return QVariant::fromValue(test.s_question);
    case Roles::Points:     return QVariant::fromValue(test.s_points);
    case Roles::Answer1:    return test.answers.front();
    case Roles::Answer2:    return test.answers[2];
    case Roles::Answer3:    return test.answers[3];
    case Roles::TrueAnswer: return test.answers[test.s_trueAnswerIndex];
    default:                return {};

    }
}

QHash<int, QByteArray> TestModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Roles::TestId] =      "testid";
    roles[Roles::Question] =    "testquestion";
    roles[Roles::Points] =      "testpoint";
    roles[Roles::Answer1] =     "testanswer1";
    roles[Roles::Answer2] =     "testanswer2";
    roles[Roles::Answer3] =     "testanswer3";
    roles[Roles::TrueAnswer] =  "testtrueanswer";

    return roles;
}

void TestModel::updateTests()
{
    std::vector<Test> requestResult { m_worker.requestTests() };
    m_allTests = requestResult;
}

void TestModel::createVariant()
{
    std::vector<Test> temp { m_allTests };
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(temp.begin(), temp.end(), g);

    emit beginResetModel();

    for(int i = 0; i < 5; ++i)
    {
        m_tests.push_back(temp[i]);
    }

    emit endResetModel();
}
