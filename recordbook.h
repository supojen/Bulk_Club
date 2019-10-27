#ifndef RECORDBOOK_H
#define RECORDBOOK_H

#include <QObject>

class RecordBook : public QObject
{
    Q_OBJECT
public:
    explicit RecordBook(QObject *parent = nullptr);

signals:

public slots:
};

#endif // RECORDBOOK_H
