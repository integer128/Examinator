#pragma once

#include "Types.h"
#include "testworker.h"

#include <QObject>
#include <QAbstractListModel>
#include <QString>

#include <vector>

class TestModel : public QAbstractListModel
{
    Q_OBJECT
public:
    TestModel();

    virtual int rowCount(const QModelIndex &parent = {}) const override;
    virtual QVariant data(const QModelIndex &index = {},
                          int role = Qt::DisplayRole) const override;

    virtual QHash<int, QByteArray> roleNames() const override;

private:
    enum Roles {
        TestId,
        Question,
        Points,
        Answer1,
        Answer2,
        Answer3,
        TrueAnswer
    };

    void updateTests();
    void createVariant();
    TestWorker m_worker;
    std::vector<Test> m_tests;
    std::vector<Test> m_allTests;
};
