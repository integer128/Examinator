#pragma once

#include "Theory.h"
#include "processor.h"
#include "dbtypes.h"

#include <memory>

class TheoryReader
{
public:
    TheoryReader();
    ~TheoryReader();

    TheoryData requestTheoryDataById(const short& id);
    TheoryData transform(const std::vector<QVariant> &source);

private:
    std::unique_ptr<database::Processor> m_processor;
};
