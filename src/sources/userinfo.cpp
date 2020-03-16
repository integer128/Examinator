#include "userinfo.h"


UserInfo::~UserInfo()
{

}

UserInfo::UserInfo(const QString& login, const QString& password, const QString& fio, const int& number, const int& role)
    : m_login { std::move(login) }
    , m_password { std::move(password) }
    , m_fio { std::move(fio) }
    , m_number { std::move(number) }
    , m_role { std::move(role) }
{

}

QString UserInfo::login() const
{
    return  m_login;
}

QString UserInfo::password() const
{
    return  m_password;
}

QString UserInfo::fio() const
{
    return  m_fio;
}

QDateTime UserInfo::lastExam() const
{
    return  m_lastExam;
}

int UserInfo::number() const
{
    return m_number;
}

int UserInfo::role() const
{
    return m_role;
}

void UserInfo::role(const int& value)
{
    if(m_role != value)
    {
        m_role = value;
    }
}
