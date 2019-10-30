#ifndef COMMODITY_H
#define COMMODITY_H

#include <QObject>

class Commodity : public QObject
{
    Q_OBJECT
public:
    explicit Commodity(QObject *parent = nullptr);

signals:

public slots:
};

#endif // COMMODITY_H
