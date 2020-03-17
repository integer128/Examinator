#pragma once

#include <QVariant>
#include <QString>
#include <QDateTime>

class UserInfo
{
public:
    UserInfo() = default;
    ~UserInfo();

    UserInfo(const QString& login,
             const QString& password,
             const QString& fio,
             const int& number,
             const int& role);

    QString login() const;
    QString password() const;
    QString fio() const;
    QDateTime lastExam() const;
    int number() const;
    int role() const;
    void role(const int& value);

private:
    QString m_login;
    QString m_password;
    QString m_fio;
    int m_number;
    int m_role;
    QDateTime m_lastExam;
};
