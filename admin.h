#ifndef ADMIN_H
#define ADMIN_H

#include <QObject>
#include <QString>

class Admin : public QObject
{
    Q_OBJECT
public:
    explicit Admin(QObject *parent = nullptr);

    QString username() const;
    void setUsername(const QString &username);

    QString password() const;
    void setPassword(const QString &password);

    int rank() const;
    void setRank(int rank);

signals:
    void usernameChanged();
    void passwordChanged();
    void rankChanged();
public slots:

private:
    QString m_username;
    QString m_password;
    int     m_rank;
};

#endif // ADMIN_H
