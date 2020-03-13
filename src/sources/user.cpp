#include "user.h"
#include "connectionmanager.h"

User::User(QObject *parent)
    : QObject { parent }
{

}

User::User(const QString &login, const QString &password, const QString &fio, const int &number, const int &role)
    : m_login { login }
    , m_password { password }
    , m_fio { fio }
    , m_number { number }
    , m_role { role }
{

}

User::~User()
{

}

bool User::getAuthFlag() const
{
    return m_authFlag;
}

void User::setAuthFlag(const bool &flag)
{
    if(m_authFlag != flag)
    {
        m_authFlag = flag;
    }

    emit AuthFlagChanged();
}

void User::enter(const QString &login, const QString &password)
{
    m_login = login;
    m_password = password;

}

bool User::checkAuth(const QString &login, const QString &password)
{

}
