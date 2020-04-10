#include "userreader.h"
#include "dbtypes.h"

#include <iterator>

UserReader::UserReader()
    : m_processor { new database::Processor {} }
{

}

UserReader::~UserReader()
{

}

UserData UserReader::requestUserBrowse(const QString &login)
{
    database::DBVariantList entries {
        m_processor->requestUserData(database::DBTables::Contacts, login) };

    return transform(entries.second);
}

UserData UserReader::transform(const std::vector<QVariantList> &source)
{
    UserData target;
    std::transform(source.begin(), source.end(), std::back_inserter(target),
                   [](const QVariantList &entry)
    {
        return UserInfo
        {
            entry[0].toString(), entry[1].toString(), entry[2].toString(),
            entry[3].toInt(), entry[4].toInt()
        };
    });
    return target;
}

void UserReader::requestAddTest(const Test &test)
{
    m_processor->requestAddTest(test);
}
