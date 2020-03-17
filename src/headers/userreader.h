#pragma once

#include "userinfo.h"
#include "processor.h"
#include "dbtypes.h"

#include <vector>
#include <memory>

class UserReader
{
public:
    UserReader();
    ~UserReader();

    std::vector<UserInfo> requestUserBrowse(const QString& login);
    std::vector<UserInfo> transform(const std::vector<QVariantList>& source);

private:
    std::unique_ptr<database::Processor> m_processor;
};
