#include "theory.h"

Theory::Theory(QObject *parent) : QObject{parent}
{
    dbc_ = DBControl::getInstance();
}

void Theory::setTextByIndex(int index)
{
    setText(dbc_->getTextById(index));
    emit textChanged();
}

void Theory::setTextNameByIndex(int index)
{
    setTxtName(dbc_->getTextNameById(index));
    emit txtNameChanged();
}
