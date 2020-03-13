#pragma once

#include <vector>
#include <memory>

#include "user.h"

class UserReader
{
public:
    UserReader();
    ~UserReader();

    std::pair<bool, std::vector<User> > requestUserBrowse(const QString &login, const QString &password);
    std::vector<User> transform(const std::vector<DBEntry>& source);

private:
    std::unique_ptr<Processor> m_processor;
};
