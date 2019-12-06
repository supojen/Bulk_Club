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
    void createInventoryTable(QString item,
                              float price);

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
    void updateInventory(QString item,
                         float price);

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
    QList<Commodity*> getCommodity();   // returns a pointer to commodities
    QList<Admin*>     getAdmins();      // returns a pointer to admins
    QList<Record*>    getRecords();     // returns a pointer to sales records
    QList<Member*>    getMembers();     // returns a pointer to members
    QMap<QString,float> getCommodityPriceList();    // returns a list of prices

    // GUI elements. All function call results are displayed in a tableview
    QSqlQueryModel* getMembersQueryModel();     // returns the list of members
    QSqlQueryModel* getRecordsQueryModel();     // returns the record of sales
    QSqlQueryModel* getCommoditiesQueryModel(); // returns the list of commodities
    QSqlQueryModel* getRevenueSortedById();     // returns the list of member revenue sorted by member ID (asc. order)
    QSqlQueryModel* getRevenueSortedByRev();    // returns the list of member revenue sorted by revenue (asc. order)
    QSqlQueryModel* SortByRevenueItems();       // returns the list of commodities sorted by revenue (asc. order)
    QSqlQueryModel* SortByNameItems();          // returns the list of commodities sorted by item name (asc. order)
    QSqlQueryModel *getInventoryQueryModel();   // returns the inventory list


    QSqlTableModel* getMembersQueryModelWithCondition(QString condition);
    QSqlTableModel* getRecordsQueryModelWithCondition(QString condition);
    QSqlTableModel* getCommoditiesQueryModelWithCondition(QString condition);
    QSqlTableModel* getMembersExpiredAttheMonth(int year,int month);

    bool readRecordFile();      // Reads a daily sales record from a file into the database. Returns true if the operation is successful
    bool readMemberFile();      // Reads a list of member information from a file into the database. Returns true if the operation is successful.

    float calcMemberSpent(int member_id);   // Calculates total purchases for a member. Returns the sum
    float calcMemberRebate(int member_id);  // Calculates the membership rebate for a customer. Returns the rebate.

    Commodity* getCommodityByItemName(QString item);        // Searches the commodity table for a given item name. If the item is found, a pointer to that item is returned.
                                                            // if it is not found, a null pointer is returned.
    QSqlQueryModel* getCommoditiesQueryModelbyName(QString name);   // Searches the commodity table for a given item name. If it is found, the results are displayed as tableview
    Member* getMemberById(int id);      // Searches the member table for a member ID. Returns a pointer to that member if found. If not found, returns a null pointer

    void setComboDate(QString combo);       // Sets the combo date (MMM/DD/YYYY) to the passed parameter
    void getComboDate (QString &combo);     // Returns the combo date (MMM/DD/YYYY)
    void deleteInventory(QString item);
    void addInventory (QString name,double price);
    QSqlQueryModel *getMembersQueryModelSortedByName();
    void deleteCustomer(QString name);
    void addCustomer(QString name, int id,QString Type);



signals:

public slots:
private:
    QSqlDatabase      m_database;
    QList<Member*>    m_members;
    QList<Record*>    m_records;
    QList<Commodity*> m_commodities;
    QList<Admin*>     m_admins;
    QString comboDate;

    void loadMembers();
    void loadRecords();
    void loadCommodities();
    void loadAdmins();
    void loadInventory();

};

#endif // CONTROLLER_H
