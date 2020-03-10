#include "dbcontrol.h"

DBControl* DBControl::db_ = nullptr;

DBControl::DBControl()
{
    sdb.setDatabaseName("D:\\Repository\\Examinator\\examinator.db");
    sdb.open();
}

bool DBControl::checkUser(QString login, QString password)
{
    query.exec("SELECT number,role,fio FROM users WHERE login='" + login + "' AND password='" + password + "';");
    QSqlRecord rec = query.record();

    while(query.next()){
        int id = query.value(rec.indexOf("number")).toInt();
        int role = query.value(rec.indexOf("role")).toInt();
        QString n_fio = query.value(rec.indexOf("fio")).toString();
        qDebug() << "id:" << id << " role:" << role;

        if(id >= 0 && role >= 0) {
            userID = id;
            userRole = role;
            fio = n_fio;

            return true;
        }
    }

    return false;
}
