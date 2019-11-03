#include "record.h"

Record::Record(QObject *parent) : QObject(parent)
{

}

int Record::id() const
{
    return m_id;
}

void Record::setId(int id)
{
    m_id = id;
}

int Record::member_id() const
{
    return m_member_id;
}

void Record::setMember_id(int member_id)
{
    m_member_id = member_id;
}

QDate Record::date() const
{
    return m_date;
}

void Record::setDate(const QDate &date)
{
    m_date = date;
}

QString Record::item() const
{
    return m_item;
}

void Record::setItem(const QString &item)
{
    m_item = item;
}

int Record::quantity() const
{
    return m_quantity;
}

void Record::setQuantity(int quantity)
{
    m_quantity = quantity;
}



