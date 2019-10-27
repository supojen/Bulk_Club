#ifndef MEMBER_H
#define MEMBER_H

#include <QObject>

class Member : public QObject
{
    Q_OBJECT
public:
    explicit Member(QObject *parent = nullptr);

signals:

public slots:
};

#endif // MEMBER_H
