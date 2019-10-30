#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>

class Admin : public QObject
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);

signals:

public slots:
};

#endif // ADMIN_H
