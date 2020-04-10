#pragma once

#include <QString>
#include <QDateTime>

#include <vector>

struct Test
{
    int s_id;
    QString s_question;
    int s_points;
    std::vector<QString> answers;
    int s_trueIndex; // 0, 1, 2
    int s_selectedIndex;
};

struct TestResult
{
    TestResult() = default;
    TestResult(const int &id, const int &result, const QDateTime &date)
        : s_id { id }
        , s_result { result }
        , s_date { date }
    {}
    int s_id;
    int s_result;
    QDateTime s_date;
};

struct TheoryData
{
    int theory_id;
    QString theory_name;
    QString theory;
    bool visible;
};

struct UserInfo
{
    UserInfo() = default;
    UserInfo(const QString &login, const QString &password, const QString &fio,
             const int &number, const int &role)
        : m_login { login }
        , m_password { password }
        , m_fio { fio }
        , m_number { number }
        , m_role { role }
    {}

    QString m_login;
    QString m_password;
    QString m_fio;
    int m_number;
    int m_role;
    QDateTime m_lastExam;
};

using UserData = std::vector<UserInfo>;
