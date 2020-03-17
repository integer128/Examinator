#pragma once

#include "dbtypes.h"
#include "theoryreader.h"
#include "Types.h"

#include <QObject>

class Theory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int thId READ getId WRITE setId NOTIFY IdChanged)
    Q_PROPERTY(QString thName READ getName WRITE setName NOTIFY NameChanged)
    Q_PROPERTY(QString theory READ getTheory WRITE setTheory NOTIFY TheoryChanged)

public:
    explicit Theory(QObject *parent = nullptr);

    short getId() const;
    void setId(const short& new_id);

    QString getName() const;
    void setName(const QString& new_name);

    QString getTheory() const;
    void setTheory(const QString& new_theory);
    //TODO: GET THEORY
signals:
    void IdChanged();
    void NameChanged();
    void TheoryChanged();

private:
    TheoryData m_data;
    TheoryReader m_reader;
};
