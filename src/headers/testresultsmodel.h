#pragma once

#include "Types.h"
#include "testresultreader.h"

#include <QObject>
#include <QAbstractListModel>

class TestResultsModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit TestResultsModel(QObject* parent = nullptr);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    QHash<int, QByteArray> roleNames() const;

    Q_INVOKABLE void updateTable();

private:
    QList<TestResult> m_tr;
    TestResultReader m_reader;

    enum Roles
    {
        IDT,
        Result,
        Date
    };
};
