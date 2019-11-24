#ifndef COMMODITY_H
#define COMMODITY_H

#include <QObject>
#include <QString>

class Commodity : public QObject
{
    Q_OBJECT
public:
    explicit Commodity(QObject *parent = nullptr);


    QString item() const;
    void setItem(const QString &item);

    float price() const;
    void setPrice(float price);

    int quantity() const;
    void setQuantity(int quantity);

    float revenue() const;
    void setRevenue(float revenue);

signals:
    void itemChanged();
    void priceChanged();
    void quantityChanged();
    void revenueChanged();
public slots:
private:
    QString m_item;
    float   m_price;
    int     m_quantity;
    float   m_revenue;
};

#endif // COMMODITY_H
