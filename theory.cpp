#include "theory.h"

Theory::Theory(QObject *parent) : QObject{parent}
{
    dbc_ = DBControl::getInstance();
}

void Theory::setTextByIndex(int index)
{

}
