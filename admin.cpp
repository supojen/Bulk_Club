#include "admin.h"

Admin::Admin(QObject *parent) : QObject(parent)
{

}

QString Admin::getUsername() const
{
    return username;
}

void Admin::setUsername(const QString &value)
{
    username = value;
}

QString Admin::getPassword() const
{
    return password;
}

void Admin::setPassword(const QString &value)
{
    password = value;
}
