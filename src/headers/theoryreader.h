#pragma once

#include "processor.h"
#include "dbtypes.h"
#include "Types.h"

#include <memory>

class TheoryReader
{
public:
    TheoryReader();
    ~TheoryReader();

    TheoryData requestTheoryDataById(const int &id);
    TheoryData transform(const std::vector<QVariant> &source);

    void requestSaveChanges(const TheoryData &data);

private:
    std::unique_ptr<database::Processor> m_processor;
};
