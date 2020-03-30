#pragma once

#include "Types.h"
#include "userreader.h"

#include <QObject>

class User : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool authFlag READ getAuth WRITE setAuth NOTIFY AuthFlagChanged)
    Q_PROPERTY(int userRole READ getRole WRITE setRole NOTIFY RoleChanged)
    Q_PROPERTY(int userId READ getUserId NOTIFY UserIdChanged)

public:
    explicit User(QObject *parent = nullptr);
    ~User();

    bool getAuth() const;
    void setAuth(const bool& flag);

    int getRole() const;
    void setRole(const int& value);

    int getUserId() const;

    Q_INVOKABLE void enter(const QString& login, const QString& password);
    Q_INVOKABLE void addTest(const QString& question,
                             const QString& answer1, const QString& answer2,
                             const QString& answer3, const QString& trueAnswer,
                             const QString& points);
    bool checkAuth(const QString& login, const QString& password);

signals:
    void AuthFlagChanged();
    void RoleChanged();
    void UserIdChanged();

private:
    UserReader m_reader;
    bool m_authFlag { false };
    UserInfo* m_user;
};
