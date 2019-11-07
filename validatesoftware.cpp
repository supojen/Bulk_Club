#include "validatesoftware.h"
#include <QDebug>

validateSoftware::validateSoftware(QObject *parent)  : QObject(parent)
{

}
QString validateSoftware :: generateMemberID()
{
    srand(time(0));
    int ID = (rand() % 100000) + 1;
    QString memberID = QString::number(ID);
    qDebug() << memberID << endl;
    return memberID;

}
