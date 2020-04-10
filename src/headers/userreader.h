#pragma once

#include "Types.h"
#include "processor.h"
#include "dbtypes.h"

#include <memory>

class UserReader
{
public:
    UserReader();
    ~UserReader();

    UserData requestUserBrowse(const QString &login);
    UserData transform(const std::vector<QVariantList> &source);
    void requestAddTest(const Test &test);

private:
    std::unique_ptr<database::Processor> m_processor;
};
