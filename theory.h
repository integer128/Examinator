#ifndef THEORY_H
#define THEORY_H

#include <QObject>
#include <QString>

#include <dbcontrol.h>

class Theory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString txt READ getText WRITE setText NOTIFY textChanged)

public:
    explicit Theory(QObject *parent = nullptr);

    void setText(const QString &txt) { this->text_ = txt; }
    QString getText() const { return this->text_; }

    Q_INVOKABLE void setTextByIndex(int index);

signals:
    void textChanged();

private:
    QString text_;
    DBControl *dbc_;
};

#endif // THEORY_H
