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
    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE void createVariant(); //create variant with random questions
    Q_INVOKABLE void updateData() { updateTests(); }

private:
    void updateTests();

    enum Roles {
        TestId,
        Question,
        Points,
        Answer1,
        Answer2,
        Answer3,
        TrueAnswer,
        Selected
    };

    TestWorker m_worker;
    std::vector<Test> m_tests;
    std::vector<Test> m_allTests;
};
