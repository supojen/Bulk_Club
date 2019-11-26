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
    createTable();

    loadAdmins();
    loadMembers();
    loadRecords();
    loadCommodities();
}

Controller::Controller(Controller &controller)
    :Controller()
{
    qDebug() << "old controller has " << controller.m_members.count()    << " members in its list"     << endl;
    qDebug() << "old controller has "<< controller.m_admins.count()      << " adimins in its list"     << endl;
    qDebug() << "old controller has "<< controller.m_records.count()     << " records in its list"     << endl;
    qDebug() << "old controller has "<< controller.m_commodities.count() << " commodities in its list" << endl;
}

Controller::~Controller()
{
    m_database.close();
    // clean the memory occupied by m_admins
    for(int index = 0; index < this->m_admins.count(); index++)
    {
        delete this->m_admins.at(index);
    }
    // clean the memory occupied by m_members
    for(int index = 0; index < this->m_members.count(); index++)
    {
        delete this->m_members.at(index);
    }
    // clean the memory occupied by m_records
    for(int index = 0; index < this->m_records.count(); index++)
    {
        delete this->m_records.at(index);
    }
    // clean the memory occupied by m_commodites
    for(int index = 0; index < this->m_commodities.count(); index++)
    {
        delete this->m_commodities.at(index);
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
    "create table IF NOT EXISTS commodity(                         "
    "item            varchar(50) primary key,                      "
    "price           float not null,                               "
    "quantity        int   not null,                               "
    "revenue         float not null                                "
    ");                                                            ";
    if(!qry.exec(createCommodityTable))
    {
        qDebug() << "error creating commodity table" << endl;
    }
    qry.clear();
    //==============================================================
    // About creating the admin table
    QString createAdminTable =
    "create table IF NOT EXISTS admin(                             "
    "username        varchar(50) primary key,                      "
    "password        varchar(50),                                  "
    "rank            integer                                       "
    ");                                                            ";
    if(!qry.exec(createAdminTable))
    {
        qDebug() << "error creating admin table" << endl;
    }
    qry.clear();

    createAdmin();
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
void Controller::createCommodity(QString item, float price, int quantity, float revenue)
{
    // Step 1
    // Creating an entry into database
    QSqlQuery qry;
    qry.prepare("insert into commodity   (    "
                "item,                        "
                "price,                       "
                "quantity,                    "
                "revenue)                     "
                "values(?,?,?,?);             "
                );
    qry.addBindValue(item);
    qry.addBindValue(price);
    qry.addBindValue(quantity);
    qry.addBindValue(revenue);

    if(!qry.exec())
    {
         qDebug() << "Error adding commodity" << endl;
    }
    qry.clear();

    // Step 2
    // Creating an entry into local memory
    Commodity* entry = new Commodity();
    entry->setItem(item);
    entry->setPrice(price);
    this->m_commodities.append(entry);

}

void Controller::createAdmin()
{
    QSqlQuery qry;
    qry.prepare("insert into admin   (    "
                "username,                "
                "password,                "
                "rank)                    "
                "values(?,?,?);           "
                );
    qry.addBindValue("admin");
    qry.addBindValue("admin");
    qry.addBindValue(2);
    if(!qry.exec())
    {
         qDebug() << "Error adding admin" << endl;
    }
    qry.clear();

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
    // Deleting entry from m_member variable
    int index;
    for(index = 0; index < this->m_members.count(); index++)
    {
        if(this->m_members[index]->id() == id)
            break;
    }
    this->m_members.removeAt(index);
}

void Controller::deleteRecord(int id)
{
    // Step 1
    // Deleting entry from database
    QSqlQuery qry;
    qry.prepare("delete from record where id = ?;");
    qry.addBindValue(id);
    if(!qry.exec())
    {
        qDebug() <<"error deleting values to db" << endl;
    }

    // Step 2
    // Deleting entry from m_record variable
    int index;
    for(index = 0; index < this->m_records.count(); index++)
    {
        if(this->m_records[index]->id() == id)
            break;
    }
    this->m_records.removeAt(index);
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

void Controller::updateCommodity(QString item, float price, int quantity, float revenue)
{
    QSqlQuery qry;
    qry.prepare("update commodity set  "
                "item               = ?, "
                "price              = ?, "
                "quantity           = ?, "
                "revenue            = ?  "
                "where item         = ?; "
                     );

    qry.addBindValue(item);
    qry.addBindValue(price);
    qry.addBindValue(quantity);
    qry.addBindValue(revenue);
    qry.addBindValue(item);

    if(!qry.exec())
    {
        //qDebug() <<"error updating values to db" << endl;
        qDebug() << qry.lastError().text() << endl;
    }
    qry.clear();

    int index;
    for(index = 0; index < this->m_commodities.count(); index++)
    {
        if(this->m_commodities[index]->item() == item)
        {
            this->m_commodities[index]->setPrice(price);
            this->m_commodities[index]->setQuantity(quantity);
            this->m_commodities[index]->setRevenue(revenue);
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

void Controller::getexpireMembers(QDate date, QList<int> &members)
{
    for(int index = 0; index < this->m_members.count(); index++)
    {
        if(date.month() == this->m_members[index]->date().month() &&
           date.year()  == this->m_members[index]->date().year())
        {
            members.append(this->m_members[index]->id());
        }
    }
}

void Controller::getTotalQuantityOfItems(QMap<QString, int> &totalQuantityOfItems)
{

    for(int index = 0; index < this->m_commodities.count(); index++)
    {
       totalQuantityOfItems[this->m_commodities[index]->item()] = 0;
    }

    for(int index = 0; index < this->m_records.count(); index++)
    {
        totalQuantityOfItems[this->m_records[index]->item()] += this->m_records[index]->quantity();
    }
}

//fixed it
void Controller::getTotalRevenueOfItems(QMap<QString, float> &totalRevenueOfItems)
{
    for(int index = 0; index < this->m_commodities.count(); index++)
    {
       totalRevenueOfItems[this->m_commodities[index]->item()] = 0;
    }

    QMap<QString, int> totalQuantityOfItems;
    getTotalQuantityOfItems(totalQuantityOfItems);

    auto iter = totalRevenueOfItems.begin();
    while(iter != totalRevenueOfItems.end())
    {
        auto commodity = getCommodityByItemName(iter.key());
        iter.value() = totalQuantityOfItems[iter.key()] * commodity->price();
        iter++;
    }
}

void Controller::getMembersPurchased(QMap<int, QList<Record*> > &membersPuchasedHistory)
{
    // initialize the output variable
    for(int index = 0; index < this->m_members.count(); index++)
    {
        QList<Record*> list;
        membersPuchasedHistory[this->m_members[index]->id()] = list;
    }

    // setting up the output variable
    for(int index_mem = 0; index_mem < this->m_members.count(); index_mem++)
    {
        for(int index_rec = 0; index_rec < this->m_records.count(); index_rec++)
        {
            if(this->m_records[index_rec]->member_id() == this->m_members[index_mem]->id())
            {
                membersPuchasedHistory[this->m_members[index_mem]->id()]
                .append(this->m_records[index_rec]);
            }
        }
    }
}

void Controller::getRebateByMembers(QMap<int, float> &reabateOfMembers)
{
    // initialize the output variable
    for(int index = 0; index < this->m_members.count(); index++)
    {
        reabateOfMembers[this->m_members[index]->id()] = 0;
    }
    // setting up the output variable
    for(int index = 0; index < this->m_members.count(); index++)
    {
        reabateOfMembers[this->m_members[index]->id()] = this->m_members[index]->rebate();
    }
}

void Controller::getTotalSpentBymembers(QMap<int, float> &totalSpentOfMembers)
{
    // initialize the output variable
    for(int index = 0; index < this->m_members.count(); index++)
    {
        totalSpentOfMembers[this->m_members[index]->id()] = 0;
    }
    // setting up the output variable
    for(int index = 0; index < this->m_members.count(); index++)
    {
        totalSpentOfMembers[this->m_members[index]->id()] = this->m_members[index]->spent();
    }
}

QList<Commodity *> Controller::getCommodity()
{
    return this->m_commodities;
}

QMap<QString, float> Controller::getCommodityPriceList()
{
    QMap<QString, float> price_list;

    for(int index = 0; index < m_commodities.count(); index++)
    {
        price_list[m_commodities[index]->item()] = m_commodities[index]->price();
    }
    return price_list;
}

QList<Admin *> Controller::getAdmins()
{
    return this->m_admins;
}

QList<Record *> Controller::getRecords()
{
    return this->m_records;
}

QList<Member *> Controller::getMembers()
{
    return this->m_members;
}

QSqlQueryModel *Controller::getMembersQueryModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("select * from member;");
    if(!qry.exec())
    {
        qDebug() <<"error Loading values to db" << endl;

    }

    model->setQuery(qry);

    return model;
}

QSqlQueryModel *Controller::getRecordsQueryModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("select * from record;");
    if(!qry.exec())
    {
        qDebug() <<"error Loading values to db" << endl;

    }

    model->setQuery(qry);

    return model;
}

QSqlQueryModel *Controller::getCommoditiesQueryModel()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    QSqlQuery qry;
    qry.prepare("select * from commodity;");
    if(!qry.exec())
    {
        qDebug() <<"error Loading values to db" << endl;

    }

    model->setQuery(qry);

    return model;
}

QSqlTableModel *Controller::getMembersQueryModelWithCondition(QString condition)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("member");
    model->setFilter(condition);
    model->sort(0,Qt::AscendingOrder);
    model->select();

    return model;
}



QSqlTableModel *Controller::getRecordsQueryModelWithCondition(QString condition)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("record");
    model->setFilter(condition);
    model->sort(0,Qt::AscendingOrder);
    model->select();


    return model;
}

QSqlTableModel *Controller::getCommoditiesQueryModelWithCondition(QString condition)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("commodity");
    model->setFilter(condition);
    model->select();

    return model;
}

QSqlTableModel *Controller::getCommoditiesQueryModelOrderBy(QString colum)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("commodity");

    int index;
    for(index = 0; index < model->columnCount(); index++)
    {
        QString columnName = model->headerData(index, Qt::Horizontal, Qt::DisplayRole).toString();
        if( columnName == colum)
            break;
    }
    model->sort(index, Qt::AscendingOrder);
    return model;
}

QSqlTableModel *Controller::getMembersQuesryModelOrderBy(QString colum)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("member");

    int index;
    for(index = 0; index < model->columnCount(); index++)
    {
        QString columnName = model->headerData(index, Qt::Horizontal, Qt::DisplayRole).toString();
        if( columnName == colum)
            break;
    }
    model->sort(index, Qt::DescendingOrder);
    return model;
}

QSqlTableModel *Controller::getMembersExpiredAtTheMonth(int year, int month)
{
    QSqlTableModel* model = new QSqlTableModel();
    model->setTable("member");
    // Setting the condition
    QString condition;
    condition = "year = " + QString::number(year) + "&";
    condition = "month = " + QString::number(month);

    model->setFilter(condition);
    model->sort(0,Qt::AscendingOrder);
    model->select();

    return model;
}



bool Controller::readRecordFile()
{
    QString file_name = QFileDialog::getOpenFileName(nullptr, "Open Record File",QDir::homePath());


    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream in(&file);
    bool date_is_alraedy_be_record = false;
    while (!in.atEnd())
    {
        // Read Date
        QString date_str = in.readLine();
        QStringList date_split = date_str.split('/');
        int month = date_split[0].toInt();
        int day = date_split[1].toInt();
        int year = date_split[2].toInt();
        // Read member id
        QString member_id_str = in.readLine();
        int member_id = member_id_str.toInt();
        // Read item name
        QString item = in.readLine();
        // Read item price
        QString price_str = in.readLine();
        float price = price_str.toFloat();
        //Read item quantity
        QString quantity_str = in.readLine();
        int quantity = quantity_str.toInt();
        // Check if the date is already be loaded
        if(!date_is_alraedy_be_record)
        {
            for(int index = 0; index < this->m_records.count(); index++)
            {
                if(this->m_records[index]->date() == QDate(year,month,day))
                {
                    qDebug() << "Today's record is already loaded!" << endl;
                    return false;
                }
            }
            date_is_alraedy_be_record = true;
        }

        // create the record
        createRecord(member_id,
                    QDate(year,month,day),
                    item,
                    quantity);
        // create the commodity
        createCommodity(item,price,0,0);
     }


    QMap<QString, float> itemsRevenue;
    getTotalRevenueOfItems(itemsRevenue);

    for(auto iter = itemsRevenue.begin(); iter != itemsRevenue.end(); iter++)
    {
        Commodity* commodity = getCommodityByItemName(iter.key());
        updateCommodity(commodity->item(),
                        commodity->price(),
                        commodity->quantity(),
                        iter.value());
    }

    QMap<QString, int> itemsQuantity;
    getTotalQuantityOfItems(itemsQuantity);
    for(auto iter = itemsQuantity.begin(); iter != itemsQuantity.end(); iter++)
    {
        Commodity* commodity = getCommodityByItemName(iter.key());
        updateCommodity(commodity->item(),
                        commodity->price(),
                        iter.value(),
                        commodity->revenue());
    }

    loadAdmins();
    loadMembers();
    loadRecords();
    loadCommodities();


    return true;
}

bool Controller::readMemberFile()
{
    QString file_name = QFileDialog::getOpenFileName(nullptr, "Open Record File",QDir::homePath());


    QFile file(file_name);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString member_name = in.readLine();
        int member_id = in.readLine().toInt();
        QString type = in.readLine();
        QString date_str = in.readLine();
        QStringList date_split = date_str.split('/');
        int month = date_split[0].toInt();
        int day = date_split[1].toInt();
        int year = date_split[2].toInt();

        createMember(member_id,
                     member_name,
                     type,
                     QDate(year,month,day),
                     calcMemberSpent(member_id),
                     calcMemberRebate(member_id));
    }

    return true;
}

float Controller::calcMemberSpent(int member_id)
{
    QMap<int, QList<Record*>> membersRecords;
    getMembersPurchased(membersRecords);
    QMap<QString, float> price_list = getCommodityPriceList();

    float spent = 0;
    for(int index = 0; index < m_records.count(); index++)
    {
        if(m_records[index]->member_id() == member_id)
        {
            spent += m_records[index]->quantity() *
                     price_list[m_records[index]->item()];
        }
    }

    return spent;
}

float Controller::calcMemberRebate(int member_id)
{
    float spent = calcMemberSpent(member_id);
    float rebate = spent * float(0.02);
    return rebate;
}

Commodity *Controller::getCommodityByItemName(QString item)
{
    for(int index = 0; index < m_commodities.count(); index++)
    {
        if(m_commodities[index]->item() == item)
            return m_commodities[index];
    }
    return nullptr;
}

Member *Controller::getMemberById(int id)
{
    Member* member = nullptr;
    for(int index = 0; index < m_members.count(); index++)
    {
        if(m_members[index]->id() == id)
        {
            member = m_members[index];
            break;
        }
    }
    return member;
}

void Controller::loadMembers()
{
    QSqlTableModel model;
    model.setTable("member");
    model.select();

    for(int index = 0; index < model.rowCount(); index++)
    {
        Member* entry = new Member();
        entry->setId(model.record(index).value("id").toInt());
        entry->setName(model.record(index).value("name").toString());
        entry->setType(model.record(index).value("type").toString());
        // setting date
        int year = model.record(index).value("year").toInt();
        int month = model.record(index).value("month").toInt();
        int day = model.record(index).value("day").toInt();
        QDate date(year,month,day);
        entry->setDate(date);
        entry->setSpent(model.record(index).value("spent").toInt());
        entry->setRebate(model.record(index).value("rebate").toInt());

        this->m_members.append(entry);
    }
}

void Controller::loadRecords()
{
    QSqlTableModel model;
    model.setTable("record");
    model.select();

    for(int index = 0; index < model.rowCount(); index++)
    {
        Record* entry = new Record();
        entry->setId(index);
        entry->setMember_id(model.record(index).value("member_id").toInt());
        // setting date
        int year = model.record(index).value("year").toInt();
        int month = model.record(index).value("month").toInt();
        int day = model.record(index).value("day").toInt();
        QDate date(year,month,day);
        entry->setDate(date);
        entry->setItem(model.record(index).value("item").toString());
        entry->setQuantity(model.record(index).value("quantity").toInt());

        this->m_records.append(entry);
    }
}

void Controller::loadCommodities()
{
    QSqlTableModel model;
    model.setTable("commodity");
    model.select();

    for(int index = 0; index < model.rowCount(); index++)
    {
        Commodity* entry = new Commodity();
        entry->setItem(model.record(index).value("item").toString());
        entry->setPrice(model.record(index).value("price").toFloat());

        this->m_commodities.append(entry);
    }

}

void Controller::loadAdmins()
{
    QSqlTableModel model;
    model.setTable("admin");
    model.select();

    for(int index = 0; index < model.rowCount(); index++)
    {
        Admin* entry = new Admin();
        entry->setRank(model.record(index).value("rank").toInt());
        entry->setUsername(model.record(index).value("username").toString());
        entry->setPassword(model.record(index).value("password").toString());

        this->m_admins.append(entry);
    }
}











