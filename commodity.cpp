#include "commodity.h"

Commodity::Commodity(QObject *parent) : QObject(parent)
{

}

QString Commodity::item() const
{
    return m_item;
}

void Commodity::setItem(const QString &item)
{
    m_item = item;
}

float Commodity::price() const
{
    return m_price;
}

void Commodity::setPrice(float price)
{
    m_price = price;
}

int Commodity::quantity() const
{
    return m_quantity;
}

void Commodity::setQuantity(int quantity)
{
    m_quantity = quantity;
}

float Commodity::revenue() const
{
    return m_revenue;
}

void Commodity::setRevenue(float revenue)
{
    m_revenue = revenue;
}
