#include "admin.h"

Admin::Admin(QObject *parent) : QObject(parent)
{

}

QString Admin::username() const
{
    return m_username;
}

void Admin::setUsername(const QString &username)
{
    m_username = username;
}

QString Admin::password() const
{
    return m_password;
}

void Admin::setPassword(const QString &password)
{
    m_password = password;
}

int Admin::rank() const
{
    return m_rank;
}

void Admin::setRank(int rank)
{
    m_rank = rank;
}


