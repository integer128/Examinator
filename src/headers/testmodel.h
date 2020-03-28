#pragma once

#include "Types.h"
#include "testworker.h"

#include <QObject>
#include <QAbstractListModel>
#include <QDateTime>

#include <vector>

class TestModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int points_ READ getPoints WRITE setPoints NOTIFY PointsChanged)
    Q_PROPERTY(int trueAnswers_ READ getTrueAnswers WRITE setTrueAnswers NOTIFY TrueAnswersChanged)

public:
    TestModel();

    virtual int rowCount(const QModelIndex &parent = {}) const override;
    virtual QVariant data(const QModelIndex &index, int role) const override;

    virtual QHash<int, QByteArray> roleNames() const override;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    virtual Qt::ItemFlags flags(const QModelIndex &index) const override;

    Q_INVOKABLE void createVariant(); //create variant with random questions
    Q_INVOKABLE void updateData() { updateTests(); }
    Q_INVOKABLE void calculatePoints(const int &userId);

    int getPoints() const;
    void setPoints(const int& points);

    int getTrueAnswers() const;
    void setTrueAnswers(const int& trueAnswers);

signals:
    void PointsChanged();
    void TrueAnswersChanged();

private:
    void updateTests();
    void saveResult(const int& userId, const int& points);

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

    int m_points { 0 };
    int m_trueAnswers { 0 };
    TestWorker m_worker;
    std::vector<Test> m_tests;
    std::vector<Test> m_allTests;
};
