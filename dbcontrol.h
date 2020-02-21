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

private:
    int userID;
    int userRole;
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    QSqlQuery query;
};

#endif // DBCONTROL_H
