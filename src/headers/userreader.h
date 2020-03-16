#pragma once

#include <vector>
#include <memory>

#include "userinfo.h"
#include "processor.h"
#include "dbtypes.h"

class UserReader
{
public:
    UserReader();
    ~UserReader();

    std::vector<UserInfo> requestUserBrowse(const QString& login);
    std::vector<UserInfo> transform(const std::vector<QVariantList>& source);

private:
    std::unique_ptr<db::Processor> m_processor;
};
