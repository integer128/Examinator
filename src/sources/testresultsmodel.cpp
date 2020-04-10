#include "testresultsmodel.h"

TestResultsModel::TestResultsModel(QObject *parent)
{

}

int TestResultsModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return m_tr.size();
}

QVariant TestResultsModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() > rowCount(index))
    {
        return QVariant{};
    }

    const TestResult &test = m_tr.at(index.row());

    switch (role)
    {
    case Roles::IDT:    return test.s_id;
    case Roles::Date:   return test.s_date;
    case Roles::Result: return  test.s_result;
    default:            return QVariant {};
    }
}

QHash<int, QByteArray> TestResultsModel::roleNames() const
{
    QHash<int, QByteArray> roles;

    roles[Roles::IDT]       = "trid";
    roles[Roles::Date]      = "trdate";
    roles[Roles::Result]    = "trresult";

    return roles;
}

void TestResultsModel::updateTable()
{
    emit beginResetModel();

    m_tr.clear();
    m_tr = m_reader.requestTestResults();

    emit endResetModel();
}
