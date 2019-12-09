#include "member.h"

Member::Member(QObject *parent) : QObject(parent)
{

}

int Member::id() const
{
    return m_id;
}

void Member::setId(int id)
{
    m_id = id;
}

QString Member::name() const
{
    return m_name;
}

void Member::setName(const QString &name)
{
    m_name = name;
}

QString Member::type() const
{
    return m_type;
}

void Member::setType(const QString &type)
{
    m_type = type;
}

QDate Member::date() const
{
    return m_date;
}

void Member::setDate(const QDate &date)
{
    m_date = date;
}

float Member::spent() const
{
    return m_spent;
}

void Member::setSpent(float spent)
{
    m_spent = spent;
}

float Member::rebate() const
{
    return m_rebate;
}

void Member::setRebate(float rebate)
{
    m_rebate = rebate;
}
/* Getter and Setter for m_renewal */
 float Member::renewal() const
 {
     return m_renewal;
 }
 void Member::setRenewal(float renewal)
 {
     m_renewal = renewal;
 }
