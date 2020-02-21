#include "dbcontrol.h"

DBControl::DBControl()
{
    sdb.setDatabaseName("examinator.db");
    sdb.open();

    if(!sdb.open()){
        qDebug() << sdb.lastError().text();
    }
}

bool DBControl::checkUser(QString login, QString password)
{
    query.exec("SELECT number,role FROM users WHERE login='" + login + "' AND password='" + password + "';");
    QSqlRecord rec = query.record();

    while(query.next()){
        int id = query.value(rec.indexOf("number")).toInt();
        int role = query.value(rec.indexOf("role")).toInt();

        qDebug() << "id:" << id << " role:" << role;

        if(id >= 0 && role >= 0) {
            userID = id;
            userRole = role;
            return true;
        }
    }

    return false;
}

