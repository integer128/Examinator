#ifndef DBCONTROL_H
#define DBCONTROL_H

#include <QtSql>
#include <QString>

class DBControl
{
public:
    static DBControl* getInstance() {
        if(db_ == nullptr) db_ = new DBControl();
        return db_;
    }
    bool checkUser(QString login, QString password);
    int getID(){ return userID; }
    int getRole() { return userRole; }
    QString getFio() { return fio; }

private:
    DBControl();

protected:
    static DBControl *db_;

private:
    int userID;
    int userRole;
    QString fio;
    QSqlDatabase sdb{QSqlDatabase::addDatabase("QSQLITE")};
    QSqlQuery query;
};

#endif // DBCONTROL_H
