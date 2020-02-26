#ifndef AUTH_H
#define AUTH_H

#include <QObject>
#include <QString>
#include <QDateTime>

#include <dbcontrol.h>

class Auth : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool authFlag READ getAuthFlag WRITE setAuthFlag NOTIFY authFlagChanged)
    Q_PROPERTY(int userId READ getId WRITE setId NOTIFY idChanged)
    Q_PROPERTY(int userRole READ getRole WRITE setRole NOTIFY roleChanged)
    Q_PROPERTY(QDateTime lastExam READ getLastExam WRITE setLastExam NOTIFY lastExamChanged)
    Q_PROPERTY(QString fio READ getFio WRITE setFio NOTIFY fioChanged)

public:
    explicit Auth(QObject *parent = nullptr);

    bool getAuthFlag() const { return authFlag; }
    void setAuthFlag(const bool& value_) { authFlag = value_; }

    int getId() const { return id; }
    void setId(const int& value_) { id = value_; }

    int getRole() const { return role; }
    void setRole(const int& value_) { role = value_; }

    QDateTime getLastExam() const { return lastExam; }
    void setLastExam(const QDateTime& value_) { lastExam = value_; }

    QString getFio() const { return fio; }
    void setFio(const QString& value) { fio = value; }

    Q_INVOKABLE void enter(QString login, QString password);

signals:
    void authFlagChanged();
    void idChanged();
    void roleChanged();
    void lastExamChanged();
    void fioChanged();

private:
    bool authFlag{false};
    QString login;
    QString password;
    QString fio;
    int id;
    int role;
    QDateTime lastExam;
    DBControl *sdb;
};

#endif // AUTH_H
