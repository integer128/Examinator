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

bool User::getAuth() const
{
    return m_authFlag;
}

void User::setAuth(const bool& flag)
{
    if(m_authFlag != flag)
    {
        m_authFlag = flag;
    }

    emit AuthFlagChanged();
}

int User::getRole() const
{
    return m_user->m_role;
}

void User::setRole(const int& value)
{
    m_user->m_role = value;

    emit RoleChanged();
}

int User::getUserId() const
{
    return m_user->m_number;
}

void User::enter(const QString& login, const QString& password)
{
    if(checkAuth(login,password))
    {
        setAuth(true);
    }
}

bool User::checkAuth(const QString& login, const QString& password)
{
    bool flag = false;

    UserData userResult { m_reader.requestUserBrowse(login) };

    if(userResult.size() > 0)
    {
        if(password == userResult.front().m_password)
        {
            flag = true;
        }

        m_user = new UserInfo(userResult.front().m_login,
                              userResult.front().m_password,
                              userResult.front().m_fio,
                              userResult.front().m_number,
                              userResult.front().m_role);
    }
    return flag;
}
