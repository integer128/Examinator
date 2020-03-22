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
    Q_PROPERTY(QString thTheory READ getTheory WRITE setTheory NOTIFY TheoryChanged)

public:
    explicit Theory(QObject *parent = nullptr);

    int getId() const;
    void setId(const int& new_id);

    QString getName() const;
    void setName(const QString& new_name);

    QString getTheory() const;
    void setTheory(const QString& new_theory);
    Q_INVOKABLE void updateTheory(const int& new_id = 1);

signals:
    void IdChanged();
    void NameChanged();
    void TheoryChanged();

private:
    TheoryData m_data; // theory_id, theory_name, text
    TheoryReader m_reader;
};
