#include "Theory.h"

Theory::Theory(QObject *parent)
    : QObject { parent }
{

}

short Theory::getId() const
{
    return m_data.theory_id;
}

void Theory::setId(const short &new_id)
{
    if(m_data.theory_id != new_id)
    {
        m_data.theory_id = new_id;
    }

    emit IdChanged();
}

QString Theory::getName() const
{
    return m_data.theory_name;
}

void Theory::setName(const QString &new_name)
{
    if(m_data.theory_name != new_name)
    {
        m_data.theory_name = new_name;
    }

    emit NameChanged();
}

QString Theory::getTheory() const
{
    return m_data.theory;
}

void Theory::setTheory(const QString &new_theory)
{
    if(m_data.theory != new_theory)
    {
        m_data.theory = new_theory;
    }

    emit TheoryChanged();
}
