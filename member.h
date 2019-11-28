#ifndef MEMBER_H
#define MEMBER_H

#include <QObject>
#include <QString>
#include <QDate>

class Member : public QObject
{
    Q_OBJECT
public:
    explicit Member(QObject *parent = nullptr);

    /* Getter and Setter for m_id */
    int id() const;
    void setId(int id);
    /* Getter and Setter for m_name */
    QString name() const;
    void setName(const QString &name);
    /* Getter and Setter for m_type */
    QString type() const;
    void setType(const QString &type);
    /* Getter and Setter for m_date */
    QDate date() const;
    void setDate(const QDate &date);
    /* Getter and Setter for m_spent */
    float spent() const;
    void setSpent(float spent);
    /* Getter and Setter for m_rebate */
    float rebate() const;
    void setRebate(float rebate);

    /* Getter and Setter for m_upgrade */
    QString upgrade() const;
    void setUpgrade(QString upgrade);


signals:
    void idChanged();
    void nameChanged();
    void typeChanged();
    void dateChanged();
    void spentChanged();
    void rebatChanged();

public slots:

private:
    int     m_id;
    QString m_name;
    QString m_type;
    QDate   m_date;
    float   m_spent;
    float   m_rebate;
    QString m_upgrade;
};

#endif // MEMBER_H
