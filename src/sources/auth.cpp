#include "auth.h"

Auth::Auth(QObject *parent)
    : QObject { parent }
    //, sdb { DBControl::getInstance() }
{

}

void Auth::enter(QString login, QString password)
{
    if(connectionManager.isValid())
    {
        std::pair<DBResult, std::vector<DBEntry> > pair_ = processor.requestTableData(DBTables::users);

        if(pair_.first == DBResult::OK)
        {
            for(auto v : pair_.second) {

            }
        }
    }
    /*if(sdb->checkUser(login, password) == true)
    {
        setAuthFlag(true);

        this->login = login;
        this->password = password;
        this->id = sdb->getID();
        this->role = sdb->getRole();
        this->fio = sdb->getFio();

        emit authFlagChanged();
        emit idChanged();
        emit roleChanged();
    }
    else
    {

    }*/
}
