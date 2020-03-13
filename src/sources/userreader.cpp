#include "userreader.h"

UserReader::UserReader()
    : m_processor { new Processor {} }
{

}

UserReader::~UserReader()
{

}

std::pair<bool, std::vector<User> > UserReader::requestUserBrowse(const QString& login, const QString& password)
{
    DBResult result;
    std::vector<DBEntry> entries;
    std::tie(result, entries) = m_processor->requestTableData(DBTables::users,
                                                              "login", "password", "fio", "number", "role",
                                                              ":",
                                                              "login='"+login+"'",
                                                              "password='"+password+"'");
    return std::make_pair(result == DBResult::OK, transform(entries));
}

std::vector<User> UserReader::transform(const std::vector<DBEntry> &source)
{
    std::vector<User> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const DBEntry& entry) {
        return new User{ entry[0].toString(), entry[1].toString(), entry[2].toString(), entry[3].toInt(), entry[4].toInt() };
    });
    return target;
}
