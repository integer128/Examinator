#include "testmodel.h"

#include <algorithm>
#include <random>
#include <chrono>

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
        return QVariant{};
    }

    const Test& test = m_tests.at(index.row());

    switch (role)
    {
    case Roles::TestId:     return test.s_id;
    case Roles::Question:   return test.s_question;
    case Roles::Points:     return test.s_points;
    case Roles::Answer1:    return test.answers[0];
    case Roles::Answer2:    return test.answers[1];
    case Roles::Answer3:    return test.answers[2];
    case Roles::TrueAnswer: return test.answers[test.s_trueIndex];
    case Roles::Selected:   return test.s_selectedIndex;
    default:                return QVariant{};
    }
}

QHash<int, QByteArray> TestModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Roles::TestId]        = "testid";
    roles[Roles::Question]      = "testquestion";
    roles[Roles::Points]        = "testpoint";
    roles[Roles::Answer1]       = "testanswer1";
    roles[Roles::Answer2]       = "testanswer2";
    roles[Roles::Answer3]       = "testanswer3";
    roles[Roles::TrueAnswer]    = "testtrueanswer";
    roles[Roles::Selected]      = "selectedanswer";

    return roles;
}

bool TestModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(!index.isValid())
    {
        return false;
    }

    switch (role)
    {
    case TestId:     return false; //This property can't be set
    case Question:   m_tests[index.row()].s_question      = value.toString(); break;
    case Points:     m_tests[index.row()].s_points        = value.toInt();    break;
    case Answer1:    m_tests[index.row()].answers[0]      = value.toString(); break;
    case Answer2:    m_tests[index.row()].answers[1]      = value.toString(); break;
    case Answer3:    m_tests[index.row()].answers[2]      = value.toString(); break;
    case TrueAnswer: m_tests[index.row()].s_trueIndex     = value.toInt();    break;
    case Selected:   m_tests[index.row()].s_selectedIndex = value.toInt();    break;
    default:         return false;
    }

    emit dataChanged(index, index, QVector<int>() << role);

    return true;
}

Qt::ItemFlags TestModel::flags(const QModelIndex &index) const
{
    if(!index.isValid())
    {
        return Qt::ItemIsEnabled;
    }
    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}

void TestModel::updateTests()
{
    std::vector<Test> requestResult { m_worker.requestTests() };

    m_allTests.clear();
    for(auto v : requestResult)
    {
        m_allTests.push_back(v);
    }
}

void TestModel::saveResult(const int &userId, const int &points)
{
    m_worker.requestSaveResult(userId, points);
}

int TestModel::getTrueAnswers() const
{
    return m_trueAnswers;
}

void TestModel::setTrueAnswers(const int &trueAnswers)
{
    m_trueAnswers = trueAnswers;
}

int TestModel::getPoints() const
{
    return m_points;
}

void TestModel::setPoints(const int &points)
{
    if(m_points != points)
    {
        m_points = points;
    }

    emit PointsChanged();
}

void TestModel::createVariant()
{
    std::vector<Test> temp { m_allTests };
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine e(seed);

    std::shuffle(temp.begin(), temp.end(), e);

    emit beginResetModel();

    m_tests.clear();

    for(int i = 0; i < 5; ++i)
    {
        m_tests.push_back(temp[i]);
    }

    emit endResetModel();
}

void TestModel::calculatePoints(const int& userId)
{
    m_points = 0;
    m_trueAnswers = 0;

    for(auto v : m_tests)
    {
        if(v.s_selectedIndex == v.s_trueIndex)
        {
            m_trueAnswers += 1;
            m_points += v.s_points;
        }
    }

    emit TrueAnswersChanged();
    emit PointsChanged();

    saveResult(userId, m_points);
}
