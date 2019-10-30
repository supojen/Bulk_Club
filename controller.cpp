#include "controller.h"

/**
 * @brief Controller::Controller
 * @param parent
 */
Controller::Controller(QObject *parent) : QObject(parent)
{
    // Connecting to database
    m_database = QSqlDatabase::addDatabase("QSQLITE");
    QString path = QDir::homePath() + "/bulk_club.db";
    m_database.setDatabaseName(path);
    if(!m_database.open())
    {
        qDebug() << "problem opening database" << endl;
    }

}
/**
 * @brief Controller::createTable
 */
void Controller::createTable()
{
    QSqlQuery qry;

    // About creating the member table
    QString createMemberTable =
    "create table IF NOT EXISTS member(                            "
    "id              integer primary key,                          "
    "name            varchar(50) not null,                         "
    "type            varchar(50) not null,                         "
    "year            integer     not null,                         "
    "month           integer     not null,                         "
    "day             integer     not null,                         "
    "spent           real        not null,                         "
    "rebate          real        not null                          "
    ");                                                            ";
    if(!qry.exec(createMemberTable))
    {
        qDebug() << "error creating member table" << endl;
    }
    qry.clear();
    //==============================================================
    // About creating the record table
    QString createRecordTable =
    "create table IF NOT EXISTS record(                            "
    "id              integer primary key  autoincrement not null,  "
    "member_id       integer     not null,                         "
    "year            integer     not null,                         "
    "month           integer     not null,                         "
    "day             integer     not null,                         "
    "item            varchar(50) not null,                         "
    "quantity        integer     not null                          "
    ");                                                            ";
    if(!qry.exec(createRecordTable))
    {
        qDebug() << "error creating member table" << endl;
    }
    qry.clear();
    //==============================================================
    // About creating the commodity table
    QString createCommodityTable =
    "create table IF NOT EXISTS record(                            "
    "item            varchar(50) primary key,                      "
    "quantity        real not null                                 "
    ");                                                            ";
    if(!qry.exec(createCommodityTable))
    {
        qDebug() << "error creating commodity table" << endl;
    }
    qry.clear();
    //==============================================================
    // About creating the admin table
    QString createAdminTable =
    "create table IF NOT EXISTS record(                            "
    "username        varchar(50) primary key,                      "
    "password        varchar(50)                                   "
    ");                                                            ";
    if(!qry.exec(createAdminTable))
    {
        qDebug() << "error creating admin table" << endl;
    }
    qry.clear();

}
/**
 * @brief Controller::createMember
 * @param id
 * @param name
 * @param type
 * @param date
 * @param spent
 * @param rebate
 */
void Controller::createMember(int id, QString name, QString type, QDate date, float spent, float rebate)
{
    // Step 1
    // Creating an entry into database
    QSqlQuery qry;
    qry.prepare("insert into member   (          "
                "id,                         "
                "name,                           "
                "type,                           "
                "year,                           "
                "month,                          "
                "day,                            "
                "spent,                          "
                "rebate)                         "
                "values(?,?,?,?,?,?,?,?);        "
                );
    qry.addBindValue(id);
    qry.addBindValue(name);
    qry.addBindValue(type);
    qry.addBindValue(date.year());
    qry.addBindValue(date.month());
    qry.addBindValue(date.day());
    qry.addBindValue(spent);
    qry.addBindValue(rebate);

    if(!qry.exec())
    {
         qDebug() << "Error adding member" << endl;
    }
    qry.clear();

    // Step 2
    // Creating an entry into local memory
    Member* entry = new Member();
    entry->setId(id);
    entry->setName(name);
    entry->setDate(date);
    entry->setType(type);
    entry->setSpent(spent);
    entry->setRebate(rebate);
    this->m_members.append(entry);

}
/**
 * @brief Controller::createRecord
 * @param member_id
 * @param date
 * @param item
 * @param quantity
 */
void Controller::createRecord(int member_id, QDate date, QString item, int quantity)
{
    // Step 1
    // Creating an entry into database
    QSqlQuery qry;
    qry.prepare("insert into record   (          "
                "member_id,                      "
                "year,                           "
                "month,                          "
                "day,                            "
                "item,                           "
                "quantity)                       "
                "values(?,?,?,?,?,?);        "
                );
    qry.addBindValue(member_id);
    qry.addBindValue(date.year());
    qry.addBindValue(date.month());
    qry.addBindValue(date.day());
    qry.addBindValue(item);
    qry.addBindValue(quantity);

    if(!qry.exec())
    {
         qDebug() << "Error adding record" << endl;
    }
    qry.clear();

    // Step 2
    // Creating an entry into local memory
    Record* entry = new Record();
    entry->setId(0);
    entry->setMember_id(member_id);
    entry->setDate(date);
    entry->setItem(item);
    entry->setQuantity(quantity);
    this->m_records.append(entry);
}
/**
 * @brief Controller::createCommodity
 * @param item
 * @param price
 */
void Controller::createCommodity(QString item, float price)
{
    // Step 1
    // Creating an entry into database
    QSqlQuery qry;
    qry.prepare("insert into commodity   (    "
                "item,                        "
                "quantity)                    "
                "values(?,?);         "
                );
    qry.addBindValue(item);
    qry.addBindValue(price);

    if(!qry.exec())
    {
         qDebug() << "Error adding record" << endl;
    }
    qry.clear();

    // Step 2
    // Creating an entry into local memory
    Commodity* entry = new Commodity();
    entry->setItem(item);
    entry->setPrice(price);
    this->m_commodities.append(entry);

}

void Controller::deleteMember(int id)
{
    // Step 1
    // Deleting entry from database
    QSqlQuery qry;
    qry.prepare("delete from member where id = ?;");
    qry.addBindValue(id);
    if(!qry.exec())
    {
        qDebug() <<"error deleting values to db" << endl;
    }

    // Step 2
    // Deleting entry from member variable
    int index;
    for(index = 0; index < this->m_members.count(); index++)
    {
        if(this->m_members[index]->id() == id)
            break;
    }
    this->m_members.removeAt(index);
}

void Controller::updatemember(int id, QString name, QString type, QDate date, float spent, float rebate)
{
    QSqlQuery qry;
    qry.prepare("update member set  "
                "id                 = ?, "
                "name               = ?, "
                "type               = ?, "
                "year               = ?, "
                "month              = ?, "
                "day                = ?, "
                "spent              = ?, "
                "rebate             = ?  "
                "where id           = ? ;"
                     );

    qry.addBindValue(id);
    qry.addBindValue(name);
    qry.addBindValue(type);
    qry.addBindValue(date.year());
    qry.addBindValue(date.month());
    qry.addBindValue(date.day());
    qry.addBindValue(spent);
    qry.addBindValue(rebate);
    qry.addBindValue(id);

    if(!qry.exec())
    {
        //qDebug() <<"error updating values to db" << endl;
        qDebug() << qry.lastError().text() << endl;
    }
    qry.clear();

    // Step 2
    // Deleting entry from member variable
    int index;
    for(index = 0; index < this->m_members.count(); index++)
    {
        if(this->m_members[index]->id() == id)
        {
            this->m_members[index]->setName(name);
            this->m_members[index]->setDate(date);
            this->m_members[index]->setType(type);
            this->m_members[index]->setSpent(spent);
            this->m_members[index]->setRebate(rebate);
            break;
        }
    }

}

void Controller::getSalesReportBydate(QDate date, QMap<QString, int> &items, QList<int> &regularMembers, QList<int> &executiveMembers, int &revenue)
{
    // Loading items
    for(int index = 0; index < this->m_records.count(); index++)
    {
        if(this->m_records[index]->date() == date)
            items[this->m_records[index]->item()] = this->m_records[index]->quantity();
    }

    // Loading members
    for(int index = 0; index < this->m_members.count(); index++)
    {
        if(this->m_records[index]->date() == date)
        {
            if(this->m_members[index]->type() == "regular")
                regularMembers.append(this->m_members[index]->id());
            else
                executiveMembers.append(this->m_members[index]->id());
        }
    }

    // Loading revenue
    revenue = 0;
    for(int index = 0; index < this->m_records.count(); index++)
    {
        if(this->m_records[index]->date() == date)
        {
            for(int index_inner = 0; index_inner < this->m_commodities.count();index_inner++)
            {
                if(this->m_records[index]->item() == this->m_commodities[index_inner]->item())
                {
                    revenue += (this->m_commodities[index_inner]->price() *
                               this->m_records[index]->quantity());
                }
            }
        }
    }
}
