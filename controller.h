#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QString>
#include <QDate>
#include <QtSql>
#include <QList>
#include <QMap>
#include <QFile>
#include <QFileDialog>
#include <QStringList>
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

    //==========================================================================================
    // This part will change the data
    //==========================================================================================
    //******************************************************************************************
    // Creating the entry
    //******************************************************************************************
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
                         float price,
                         int quantity,
                         float revenue);
    //******************************************************************************************
    // deleting the entry
    //******************************************************************************************
    void deleteMember(int id);
    //******************************************************************************************
    // updateing the entry
    //******************************************************************************************
    void updatemember(int     id,
                      QString name,
                      QString type,
                      QDate   date,
                      float   spent,
                      float   rebate);

    void updateCommodity(QString item,
                         float price,
                         int quantity,
                         float revenue);

    //==========================================================================================
    // This part will not change the data
    // This part is about reading the data
    //==========================================================================================
    //******************************************************************************************
    // Getting the sales report according to the date
    // Input:
    //      QDate date:                   representing the date you want to check
    // Return:
    //      QMap<QString, int>& items :   <item's name, item's quantity> (According to the date)
    //      QList<int>& regularMembers:   <regular member's id> (According to the date)
    //      QList<int>& executiveMembers: <executive member 's id> (According to the date)
    //      int&:                         The total revenue according to the date
    //******************************************************************************************
    void getSalesReportBydate(QDate               date,
                              QMap<QString, int>& items,
                              QList<int>&         regularMembers,
                              QList<int>&         executiveMembers,
                              int&                revenue);
    //******************************************************************************************
    // Getting the member ID that will expired by the givn date(the same month and year)
    // Input:
    //      QDate date:                   representing the date you want to check
    // Return:
    //      QList<int>& members:          <member 's ID>,
    //                                    these are the members who's membership will expired in
    //                                    the month and year you given
    //******************************************************************************************
    void getexpireMembers(QDate date, QList<int>& members);
    //******************************************************************************************
    // Getting the total quantity of items
    // Return:
    //      QMap<QString, int>& totalQuantityOfItems: <item's name, the qunatity of the item>
    //******************************************************************************************
    void getTotalQuantityOfItems(QMap<QString, int>& totalQuantityOfItems);
    //******************************************************************************************
    // Getting the total revenue of items
    // Return:
    //      QMap<QString, int>& totalRevenueOfItems: <item's name, the Revenue of the item>
    //****************************************************************************************
    void getTotalRevenueOfItems(QMap<QString, float>& totalRevenueOfItems);
    //******************************************************************************************
    // Getting the records according to the member
    // Return:
    //      QMap<QString, QList<Record*>>& membersPuchasedHistory: <member's ID, the record related to the member>
    //******************************************************************************************
    void getMembersPurchased(QMap<int, QList<Record*> >& membersPuchasedHistory);
    //******************************************************************************************
    // Getting the members' rebate
    // Return:
    //      QMap<int,float>& rebateOfMembers: <member's ID, the rebate of the member>
    //******************************************************************************************
    void getRebateByMembers(QMap<int,float>& reabateOfMembers);
    //******************************************************************************************
    // Getting the members' total spent
    // Return:
    //      QMap<int,float>& rebateOfMembers: <member's ID, the total spent of the member>
    //******************************************************************************************
    void getTotalSpentBymembers(QMap<int,float>& totalSpentOfMembers);


    //==========================================================================================
    // This function get the list of the infos, but if you change the data you get here
    // it will not change the database
    //==========================================================================================
    QList<Commodity*> getCommodity();
    QList<Admin*>     getAdmins();
    QList<Record*>    getRecords();
    QList<Member*>    getMembers();
    QMap<QString,float> getCommodityPriceList();

    QSqlQueryModel* getMembersQueryModel();
    QSqlQueryModel* getRecordsQueryModel();
    QSqlQueryModel* getCommoditiesQueryModel();
    QSqlQueryModel* getRevenueSortedById();
    QSqlQueryModel* getRevenueSortedByRev();
    QSqlQueryModel*SortByRevenueItems();
    QSqlQueryModel*SortByNameItems();


    QSqlTableModel* getMembersQueryModelWithCondition(QString condition);
    QSqlTableModel* getRecordsQueryModelWithCondition(QString condition);
    QSqlTableModel* getCommoditiesQueryModelWithCondition(QString condition);
    QSqlTableModel* getMembersExpiredAttheMonth(int year,int month);

    bool readRecordFile();
    bool readMemberFile();

    float calcMemberSpent(int member_id);
    float calcMemberRebate(int member_id);

    Commodity* getCommodityByItemName(QString item);
    QSqlQueryModel* getCommoditiesQueryModelbyName(QString name);
    Member* getMemberById(int id);



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
