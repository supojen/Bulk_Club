#ifndef COMMODITY_H
#define COMMODITY_H

#include <QObject>
#include <QString>

class Commodity : public QObject
{
    Q_OBJECT
public:
    explicit Commodity(QObject *parent = nullptr);

    /* Getter and Setter for m_item */
    QString item() const;
    void setItem(const QString &item);
    /* Getter and Setter for m_price */
    float price() const;
    void setPrice(float price);

signals:
    void itemChanged();
    void priceChanged();
public slots:
private:
    QString m_item;
    float   m_price;
};

#endif // COMMODITY_H
