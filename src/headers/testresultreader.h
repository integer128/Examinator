#pragma once

#include "processor.h"
#include "Types.h"

#include <QList>

#include <memory>

class TestResultReader
{
public:
    TestResultReader();
    QList<TestResult> requestTestResults();
    QList<TestResult> transform(const std::vector<QVariantList> &variant);

private:
    std::unique_ptr<database::Processor> m_processor;
};
