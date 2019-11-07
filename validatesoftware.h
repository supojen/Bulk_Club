#ifndef VALIDATESOFTWARE_H
#define VALIDATESOFTWARE_H

#include <QObject>
#include <QString>

class validateSoftware : public QObject
{
    Q_OBJECT

public:
    explicit validateSoftware(QObject *parent = nullptr);

public:
    QString generateMemberID();

private:
};

#endif // VALIDATESOFTWARE_H
