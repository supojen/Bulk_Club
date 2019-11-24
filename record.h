#ifndef RECORD_H
#define RECORD_H

#include <QObject>
#include <QString>
#include <QDate>

class Record : public QObject
{
    Q_OBJECT
public:
    explicit Record(QObject *parent = nullptr);


    int id() const;
    void setId(int id);

    int member_id() const;
    void setMember_id(int member_id);

    QDate date() const;
    void setDate(const QDate &date);

    QString item() const;
    void setItem(const QString &item);

    int quantity() const;
    void setQuantity(int quantity);

signals:
    void idChanged();
    void memberIdChanged();
    void dateChanged();
    void itemChanged();
    void quantityChanged();

public slots:

private:
    int     m_id;
    int     m_member_id;
    QDate   m_date;
    QString m_item;
    int     m_quantity;


};

#endif // RECORD_H
