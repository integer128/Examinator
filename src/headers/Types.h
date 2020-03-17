#pragma once

#include <QString>
#include <QDateTime>

struct TheoryData
{
    short theory_id;
    QString theory_name;
    QString theory;
};

struct UserInfo
{
    UserInfo() = default;
    UserInfo(const QString& login,
             const QString& password,
             const QString& fio,
             const int& number,
             const int& role)
        : m_login { login }
        , m_password { password }
        , m_fio { fio }
        , m_number { number }
        , m_role { role }
    {

    }

    QString m_login;
    QString m_password;
    QString m_fio;
    int m_number;
    int m_role;
    QDateTime m_lastExam;
};
