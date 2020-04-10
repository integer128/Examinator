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
    Q_PROPERTY(bool thVisible READ getVisible WRITE setVisible NOTIFY VisibleChanged)

public:
    explicit Theory(QObject *parent = nullptr);

    int getId() const;
    void setId(const int &new_id);

    QString getName() const;
    void setName(const QString &new_name);

    QString getTheory() const;
    void setTheory(const QString &new_theory);

    bool getVisible() const;
    void setVisible(const bool &value);

    Q_INVOKABLE void updateTheory(const int &new_id = 1);
    Q_INVOKABLE void saveChanged();

signals:
    void IdChanged();
    void NameChanged();
    void TheoryChanged();
    void VisibleChanged();

private:
    TheoryData m_data; // theory_id, theory_name, text
    TheoryReader m_reader;
};
