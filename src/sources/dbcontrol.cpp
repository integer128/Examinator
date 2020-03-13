#include "dbcontrol.h"

DBControl* DBControl::db_ = nullptr;

DBControl::DBControl()
{
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("D:\\Repository\\Examinator\\src\\database\\examinator.db");
    sdb.open();
}

bool DBControl::checkUser(QString login, QString password)
{
    QSqlQuery query;
    query.exec("SELECT number,role,fio FROM users WHERE login='" + login + "' AND password='" + password + "';");
    QSqlRecord rec = query.record();

    while(query.next()) {
        int id = query.value(rec.indexOf("number")).toInt();
        int role = query.value(rec.indexOf("role")).toInt();
        QString n_fio = query.value(rec.indexOf("fio")).toString();
        qDebug() << "id:" << id << " role:" << role;

        if(id >= 0 && role >= 0)
        {
            userID = id;
            userRole = role;
            fio = n_fio;

            return true;
        }
    }
    return false;
}

QString DBControl::getTextById(int index)
{
    QSqlQuery query;
    QString str = "SELECT * FROM theory";
    query.exec(str);

    int i = query.record().indexOf("data");
    int j = query.record().indexOf("text_id");

    while(query.next())
    {
        QString text_data = query.value(i).toString();
        if(query.value(j).toInt() == index)
        return text_data;
    }

    return QString("ERROR getTextById");
}

QString DBControl::getTextNameById(int index)
{
    QSqlQuery query;
    QString str = "SELECT * FROM theory";
    query.exec(str);

    int i = query.record().indexOf("name");
    int j = query.record().indexOf("text_id");

    while(query.next()) {
        QString text_data = query.value(i).toString();
        if(query.value(j).toInt() == index)
        return text_data;
    }

    return QString("ERROR getTextNameById");
}
