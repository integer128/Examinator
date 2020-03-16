#include "userreader.h"
#include "dbtypes.h"

#include <iterator>

UserReader::UserReader()
    : m_processor { new db::Processor {} }
{

}

UserReader::~UserReader()
{

}

std::vector<UserInfo> UserReader::requestUserBrowse(const QString& login)
{
    std::pair<DBTypes::DBResult, std::vector<QVariantList> > entries { m_processor->requestUserData(DBTypes::DBTables::Contacts, login) };

    return transform(entries.second);
}

std::vector<UserInfo> UserReader::transform(const std::vector<QVariantList>& source)
{
    std::vector<UserInfo> target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const QVariantList& entry) {
        return UserInfo{ entry[0].toString(), entry[1].toString(), entry[2].toString(), entry[3].toInt(), entry[4].toInt() };
    });
    return target;
}
