#pragma once

#include <QObject>
#include <QString>
#include <QDateTime>

#include "processor.h"

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool authFlag READ getAuthFlag WRITE setAuthFlag NOTIFY AuthFlagChanged)

public:
    explicit User(QObject *parent = nullptr);

    User(const User&) = delete;
    User& operator=(const User&) = delete;

    User(const QString& login,
         const QString& password,
         const QString& fio,
         const int& number,
         const int& role);
    ~User();

    bool getAuthFlag() const;
    void setAuthFlag(const bool& flag);

    Q_INVOKABLE void enter(const QString& login, const QString& password);
    bool checkAuth(const QString& login, const QString& password);

signals:
    void AuthFlagChanged();
private:

    QString m_login;
    QString m_password;
    QString m_fio;
    QDateTime m_lastExam;
    bool m_authFlag { false };
    int m_number;
    int m_role;
};
