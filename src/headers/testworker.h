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

signals:


private:
    std::unique_ptr<database::Processor> m_processor;

};
