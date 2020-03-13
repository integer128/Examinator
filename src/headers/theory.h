#pragma once

#include <QObject>
#include <QString>

#include <dbcontrol.h>

class Theory : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString txt READ getText WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QString txt_name READ getTxtName WRITE setTxtName NOTIFY txtNameChanged)

public:
    explicit Theory(QObject *parent = nullptr);

    void setText(const QString &txt) { this->text_ = txt; }
    QString getText() const { return this->text_; }

    void setTxtName(const QString& txt_name) { this->name_ = txt_name; }
    QString getTxtName() const { return this->name_; }

    Q_INVOKABLE void setTextByIndex(int index);
    Q_INVOKABLE void setTextNameByIndex(int index);

signals:
    void textChanged();
    void txtNameChanged();

private:
    QString name_;
    QString text_;
    DBControl *dbc_;
};
