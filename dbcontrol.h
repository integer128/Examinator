#ifndef DBCONTROL_H
#define DBCONTROL_H

#include <QtSql>
#include <QString>

class DBControl
{
public:
    DBControl();
    bool checkUser(QString login, QString password);
    int getID(){ return userID; }
    int getRole() { return userRole; }
    QString getFio() { return fio; }

private:
    int userID;
    int userRole;
    QString fio;
    QSqlDatabase sdb{QSqlDatabase::addDatabase("QSQLITE")};
    QSqlQuery query;
};

#endif // DBCONTROL_H
