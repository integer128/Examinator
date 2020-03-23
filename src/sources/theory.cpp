#include "Theory.h"

Theory::Theory(QObject *parent)
    : QObject { parent }
{
    m_data.theory_id = 1; //default
}

int Theory::getId() const
{
    return m_data.theory_id;
}

void Theory::setId(const int &new_id)
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

bool Theory::getVisible() const
{
    return m_data.visible;
}

void Theory::setVisible(const bool &value)
{
    if(m_data.visible != value)
    {
        m_data.visible = value;
    }

    emit VisibleChanged();
}

void Theory::updateTheory(const int &new_id)
{
    m_data = m_reader.requestTheoryDataById(new_id);

    emit IdChanged();
    emit NameChanged();
    emit TheoryChanged();
    emit VisibleChanged();
}

void Theory::saveChanged()
{
    m_reader.requestSaveChanges(m_data);
}
