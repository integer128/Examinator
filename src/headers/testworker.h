#pragma once

#include <QObject>

#include "Types.h"
#include "processor.h"

#include <vector>

class TestWorker  : public QObject
{
    Q_OBJECT
public:
    TestWorker();
    std::vector<Test> requestTests();

signals:


private:
    std::unique_ptr<database::Processor> m_processor;

};
