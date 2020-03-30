#pragma once

#include "Types.h"
#include "processor.h"

#include <QObject>

#include <vector>

class TestWorker  : public QObject
{
    Q_OBJECT
public:
    TestWorker();
    std::vector<Test> requestTests();
    void requestSaveResult(const int& userId, const int& points);
    void requestUpdateTest(const int &testId, const QString &question,
                           const QString &answer1, const QString &answer2,
                           const QString &answer3, const QString &trueAnswer,
                           const int &points);

private:
    std::unique_ptr<database::Processor> m_processor;

};
