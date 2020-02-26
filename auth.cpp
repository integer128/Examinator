#include "auth.h"

Auth::Auth(QObject *parent) : QObject{parent}
{
    sdb = new DBControl();
}

void Auth::enter(QString login, QString password)
{
    if(sdb->checkUser(login, password) == true) {
        setAuthFlag(true);

        this->login = login;
        this->password = password;
        this->id = sdb->getID();
        this->role = sdb->getRole();
        this->fio = sdb->getFio();

        emit authFlagChanged();
        emit idChanged();
        emit roleChanged();
    } else {

    }
}
