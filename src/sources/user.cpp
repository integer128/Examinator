#include "user.h"

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

void User::setAuth(const bool &flag)
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

void User::setRole(const int &value)
{
    m_user->m_role = value;

    emit RoleChanged();
}

int User::getUserId() const
{
    return m_user->m_number;
}

void User::enter(const QString &login, const QString &password)
{
    if(checkAuth(login,password))
    {
        setAuth(true);
    }
}

void User::addTest(const QString &question, const QString &answer1,
                   const QString &answer2, const QString &answer3,
                   const QString &trueAnswer, const QString &points)
{
    Test test;
    test.s_question = question;
    test.s_points = QString(points).toInt();
    test.answers.push_back(answer1);
    test.answers.push_back(answer2);
    test.answers.push_back(answer3);

    for(int i = 0; i < 3; i++)
    {
        if(test.answers[i] == trueAnswer)
            test.s_trueIndex = i;
    }
    m_reader.requestAddTest(test);
}

bool User::checkAuth(const QString &login, const QString &password)
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
