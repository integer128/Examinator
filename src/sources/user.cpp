#include "user.h"
#include "connectionmanager.h"

User::User(QObject *parent)
    : QObject { parent }
{
    m_user = new UserInfo();
}

User::~User()
{
    delete m_user;
}

bool User::getAuthFlag() const
{
    return m_authFlag;
}

void User::setAuthFlag(const bool& flag)
{
    if(m_authFlag != flag)
    {
        m_authFlag = flag;
    }

    emit AuthFlagChanged();
}

int User::getRole() const
{
    return m_user->role();
}

void User::setRole(const int& value)
{
    m_user->role(value);

    emit RoleChanged();
}

void User::enter(const QString& login, const QString& password)
{
    if(checkAuth(login,password))
    {
        setAuthFlag(true);
    }
}

bool User::checkAuth(const QString& login, const QString& password)
{
    bool flag = false;

    std::vector<UserInfo> userResult { m_reader.requestUserBrowse(login) };

    if(userResult.size() > 0)
    {
        if(password == userResult.front().password())
        {
            flag = true;
        }

        m_user = new UserInfo(userResult.front().login(),
                              userResult.front().password(),
                              userResult.front().fio(),
                              userResult.front().number(),
                              userResult.front().role());
        return flag;
    }
    return flag;
}
