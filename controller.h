#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QtSql>
#include <QList>
#include <QMap>
#include "member.h"
#include "record.h"
#include "commodity.h"
#include "admin.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);

    Controller(Controller& controller);
    ~Controller();

    void createTable();

    //=================================================================
    // This part will change the data
    //=================================================================
    //*************************************************
    // Creating the entry
    //*************************************************
    void createMember(int     id,
                      QString name,
                      QString type,
                      QDate   date,
                      float   spent,
                      float   rebate);
    void createRecord(int     member_id,
                      QDate   date,
                      QString item,
                      int     quantity);
    void createCommodity(QString item,
                         float price);
    //*************************************************
    // deleting the entry
    //*************************************************
    void deleteMember(int id);
    //*************************************************
    // updateing the entry
    //*************************************************
    void updatemember(int     id,
                      QString name,
                      QString type,
                      QDate   date,
                      float   spent,
                      float   rebate);
    //=================================================================
    // This part will not change the data
    //=================================================================
    // About Records
    void getSalesReportBydate(QDate               date,
                              QMap<QString, int>& items,
                              QList<int>&         regularMembers,
                              QList<int>&         executiveMembers,
                              int&                revenue);
    void getexpireMembers(QDate date, QList<int>& members);
    void getTotalQuantityOfItems(QMap<QString, int>& totalQuantityOfItems);
    void getTotalRevenueOfItems(QMap<QString, float>& totalRevenueOfItems);
    // About Members
    void getMembersPurchased(QMap<int, QList<int> >& membersPuchasedHistory);
    void getRebateByMembers(QMap<int,float>& reabateOfMembers);
    void getTotalSpentBymembers(QMap<int,float>& totalSpentOfMembers);

    // This function get the list of the infos, but if you change the data you get here
    // it will not change the database
    QList<Commodity*> getCommodity();
    QList<Admin*>     getAdmins();
    QList<Record*>    getRecords();
    QList<Member*>    getMembers();

signals:

public slots:
private:
    QSqlDatabase      m_database;
    QList<Member*>    m_members;
    QList<Record*>    m_records;
    QList<Commodity*> m_commodities;
    QList<Admin*>     m_admins;

    void loadMembers();
    void loadRecords();
    void loadCommodities();
    void loadAdmins();

};

#endif // CONTROLLER_H
