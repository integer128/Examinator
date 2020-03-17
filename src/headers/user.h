#pragma once

#include "userinfo.h"
#include "userreader.h"

#include <QObject>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool authFlag READ getAuth WRITE setAuth NOTIFY AuthFlagChanged)
    Q_PROPERTY(int userRole READ getRole WRITE setRole NOTIFY RoleChanged)

public:
    explicit User(QObject *parent = nullptr);
    ~User();

    bool getAuth() const;
    void setAuth(const bool& flag);

    int getRole() const;
    void setRole(const int& value);

    Q_INVOKABLE void enter(const QString& login, const QString& password);
    bool checkAuth(const QString& login, const QString& password);

signals:
    void AuthFlagChanged();
    void RoleChanged();

private:
    UserReader m_reader;
    bool m_authFlag { false };
    UserInfo* m_user;
};
