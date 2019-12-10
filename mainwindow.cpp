#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QPixmap>

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_controller(controller)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->MAINWINDOW);
    QPixmap pix("/Users/littlejimmyfirl/Desktop/bulkClub/Logo.png");
    int w = ui ->logo->width();
    int h = ui ->logo->height();
    ui->logo->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));

    ui->MAINWINDOW->setMinimumSize(800, 600);   // args are (width, height) in pixels
     // This sets the minimum size (pixels) of the main window. It cannot be shrunk smaller than those values.



    QFile file(QDir::homePath() + "/storedDates.txt");
       if(!file.exists())
       {
           qDebug() << file.fileName() << " does not exist";
       }

       QString line;
       if(file.open(QIODevice::ReadOnly | QIODevice::Text))
       {
           QTextStream stream(&file);
              while (!stream.atEnd())
              {
                   line = stream.readLine();
                   ui-> comboBox->addItem(line);
              }

       }
               file.close();
       /* This is just simply reading in the storedDates text and adding them to the combo box. */
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ValidateSoftware_clicked()
{
    changetoValidationTool();
}


void MainWindow::keyPressEvent(QKeyEvent* pe)
{
    if(page == 0)
    {
        if(pe->key()== Qt::Key_Return) on_pushButton_clicked();
    }
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->username ->text();
    QString password = ui->password->text();

    QSqlQuery qry;
    // RANK 2 IS USED FOR ADMINS
    // RANK 1 IS USED FOR STORE MANAGERS
    qry.prepare("select * from admin where username ='"+username+"' and password ='"+password+"' and rank= '2'");
    if (qry.exec())
    {
        int count = 0;
        while (qry.next())
        {
            count++;
        }
           if(count == 1)
           {
            QMessageBox::information(this, "Login", "Username and password is correct");
            changeToAdmin();
            this->ui->username->setText("");
            this->ui->password->setText("");
           }
           else if (count!= 1)
           {
               if(qry.exec("select * from admin where username ='"+username+"' and password ='"+password+"' and rank= '1'"))
                   count  = 0;
                    while(qry.next())
                    {
                        count++;
                    }
                    if (count == 1)
                    {
                       QMessageBox::information(this,"Login", "Username and Password is correct");
                       changeToManager();
                       this->ui->username->setText("");
                       this->ui->password->setText("");
                    }
                    else
                    {
                        QMessageBox::warning(this,"Login","Username and password is not correct");
                        this->ui->username->setText("");
                        this->ui->password->setText("");
                    }
           }
    }
}
void MainWindow::changeToAdmin()
{
    ui->stackedWidget->setCurrentWidget(ui->TransitionalAdminPage);
    page++;
}
void MainWindow::changetoValidationTool()
{
    ui->stackedWidget->setCurrentWidget(ui->ValidationTool);
}
void MainWindow::changeToManager()
{
    ui->stackedWidget->setCurrentWidget(ui->managerLogin);
    ui->totalProfits->setText(QString::number(m_controller->get_total_revenue()));
    page++;
}


void MainWindow::on_viewItems_clicked()
{
    showTables();
   ui->managerTable->setModel(m_controller->getCommoditiesQueryModel());
   ui->managerTable->resizeColumnsToContents();

   ui->totalSalesLabel->clear();
   ui->totalCustomers->clear();
   ui->totalRegularCustomers->clear();
   ui->totalExecutiveCustomers->clear();
}

void MainWindow::on_loadSales_clicked()
{
    ui->totalSalesLabel->clear();
    ui->totalCustomers->clear();
    ui->totalRegularCustomers->clear();
    ui->totalExecutiveCustomers->clear();

    QString comboDate;
        if(m_controller->readRecordFile() == true)
        {
            m_controller->getComboDate(comboDate);

            qDebug() << comboDate;
            ui-> comboBox->addItem(comboDate);
            QFile file(QDir::homePath() + "/storedDates.txt");
            if(!file.exists())
            {
                qDebug() << file.fileName() << " does not exist";
            }

            if(file.open(QIODevice::Append| QIODevice::WriteOnly | QIODevice::Text))
            {
                QTextStream txtStream (&file);

                qDebug() << "~ Writing To File ~";
                qDebug() << comboDate << endl;
                txtStream << comboDate << endl;
                file.close();
            }
            /* The addition to the original controller function here adds functinailty
             * for the date to be added to a new file that stores the dates that have
             * already been added to the application. This is helpful because, without saving this information
             * the combobox does not keep the dynamically added dates. Therefore the dates are saved, and loaded
             * into the combobox when the application is started up.
             */
            QFile file2(QDir::homePath() + "/warehouse shoppers.txt");
            if(!file.exists())
            {
                qDebug() << file2.fileName() << " does not exist";
            }
            QString name;
            QString memberID;
            QString type;
            QString fullDate;
            QString month;
            QString day;
            QString year;
            QSqlQuery qry;
            if(file2.open(QIODevice::ReadOnly | QIODevice::Text))
            {
                QTextStream stream2(&file2);
                   while (!stream2.atEnd())
                   {
                        name = stream2.readLine();
                        qDebug() << name << endl;
                        memberID = stream2.readLine();
                        type = stream2.readLine();
                        fullDate = stream2.readLine();
                        month = fullDate.mid(0,2);
                        qDebug() << month << endl;
                        day = fullDate.mid(3,2);
                        qDebug() << day << endl;
                        year = fullDate.mid(6,4);
                        qDebug() << year << endl;
                        float spent =m_controller->calcMemberSpent(memberID.toInt());
                        qDebug() << spent << endl;

                        qry.exec("update member set id = '"+memberID+"', name= '"+name+"', year = '"+year+"',"
                                 " month  = '"+month+"', day = '"+day+"',spent = '"+QString::number(spent)+"' where id = '"+memberID+"'");
                   }

            }
            file2.close();
            ui->totalProfits->setText(QString::number(m_controller->get_total_revenue()));

        }
        else
            QMessageBox::warning(this,"Date Already Added", "This Daily Sales Report Has Already Been Added to the Database!");


}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString date = ui->comboBox->currentText();
    if(date !=  "Select Your Date")
    {
        QStringList str_split = date.split(',');
        int day = str_split[1].toInt();

        QString condition = "day==";
        condition += QString::number(day);

        ui->managerTable->setModel(
        m_controller->getRecordsQueryModelWithCondition(condition));
        ui->managerTable->setColumnHidden(0,true);
        ui->managerTable->setColumnHidden(2,true);
        ui->managerTable->setColumnHidden(3,true);
        ui->managerTable->setColumnHidden(4,true);
        ui->managerTable->show();
        ui->managerTable->resizeColumnsToContents();

        //qDebug() << day << endl;
        // The purpose for this part is finding the total spent for the day
        // total_spent varaible hold the total spent
        //---------------------------------------------------------------------
        auto commodities = m_controller->getCommodity();
        auto model = m_controller->getRecordsQueryModelWithCondition(condition);
        float total_spent = 0;
        QStringList memberIDs;

        for(int index = 0; index < model->rowCount();index++)
        {
            int quantity = model->record(index).value("quantity").toInt();
            QString item = model->record(index).value("item").toString();
            QString ID = model->record(index).value("member_id").toString();

            if(memberIDs.contains(ID))
            {
                qDebug() << "ID is already in the Array" << endl;
            }
            else
            {
                memberIDs.append(ID);
            }
            float spent = 0;

            for(int com_iter = 0; com_iter < commodities.count(); com_iter++)
            {

                if(item == commodities[com_iter]->item())
                {
                    spent = commodities[com_iter]->price();
                    break;
                }
            }
            spent *= quantity;
            total_spent += spent;
        }

        total_spent *= 1.0775;
        ui->totalCustomers ->setText(QString::number(memberIDs.size()));
        ui->totalSalesLabel->setText("$" + QString::number(total_spent,'f',2));

        // IF THE PROGRAM BREAKS DELETE THIS
        // --------------------------------------------------------------------
        QSqlQuery qry;
        QString type;
        int exec = 0;
        int reg = 0;

        for(QStringList::iterator it = memberIDs.begin(); it != memberIDs.end(); it++)
        {
            QString current = *it;
            qDebug() << current << endl;
            qry.prepare("Select * from record where member_id = '"+current+"'");

        if (qry.exec())
        {
            while(qry.next())
            {
                qry.prepare("Select * from member where id = '"+current+"'");
                if (qry.exec())
                {
                    while(qry.next())
                    {
                        type = qry.value(2).toString();
                        qDebug() << type << endl;
                        if(type == "Executive")
                            exec++;
                        else if (type == "Regular")
                            reg++;
                        else
                            qDebug() << "No Matching Type Detected!";
                    }
                }

            }
        }
        }
        //---------------------------------------------------------------------
    ui->totalRegularCustomers->setText(QString::number(reg));
    ui->totalExecutiveCustomers->setText(QString::number(exec));
    }
}
void MainWindow::showTables()
{
    ui->managerTable->setColumnHidden(0,false);
    ui->managerTable->setColumnHidden(2,false);
    ui->managerTable->setColumnHidden(3,false);
    ui->managerTable->setColumnHidden(4,false);
}


void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    ui->totalSalesLabel->clear();
    ui->totalCustomers->clear();
    ui->totalRegularCustomers->clear();
    ui->totalExecutiveCustomers->clear();

    QString select = ui->comboBox_2->currentText();

    if(select == "Sort Members By ID")
    {
      showTables();
      ui->managerTable->setModel(m_controller->getRevenueSortedById());
      ui->managerTable->resizeColumnsToContents();

    }
    if(select == "Sort Members By REV")
    {
       showTables();
       ui->managerTable->setModel(m_controller->getRevenueSortedByRev());
       ui->managerTable->resizeColumnsToContents();
    }
    if(select == "Sort item By Rev")
    {
        showTables();
        ui->managerTable->setModel(m_controller->SortByRevenueItems());
        ui->managerTable->resizeColumnsToContents();
    }
    if(select == "Sort item By Name")
    {
        showTables();
        ui->managerTable->setModel(m_controller->SortByNameItems());
        ui->managerTable->resizeColumnsToContents();
    }
    if(select == "View Rebate Totals")
    {
        showTables();
        ui->managerTable->setModel(m_controller->SortByRebate());
        ui->managerTable->resizeColumnsToContents();

        QSqlQuery qry;
        double rebate = 0;
        double totalRebate = 0;
        qry.prepare("select * from member where type = 'Executive'");

        if(qry.exec())
        {
            while(qry.next())
            {
                rebate = qry.value(7).toDouble();
                totalRebate += rebate;
                qDebug() << totalRebate << endl;

            }
        }
        QMessageBox::information(this, "Rebate Total", "The Total Rebate for All Executive Members is $" + QString::number(totalRebate,'f',2));
    }
}


QString MainWindow::generateMemberID()
{
    int ID;
    qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
    ID = (qrand() % 100000);
    QString memberID = QString::number(ID);
    return memberID;

    //This function generaters a random 5 digit number that will be used as a unique MemberID

}
QString MainWindow ::getMonth(QString month)
{
    if (month == "Jan")
        month = "01";
    else if (month == "Feb")
        month = "02";
    else if (month == "Mar")
        month = "03";
    else if (month == "Apr")
        month = "04";
    else if (month == "May")
        month = "05";
    else if (month == "Jun")
        month = "06";
    else if (month == "Jul")
        month = "07";
    else if (month == "Aug")
        month = "08";
    else if (month == "Sep")
        month = "09";
    else if (month == "Oct")
        month = "10";
    else if (month == "Nov")
        month = "11";
    else if (month == "Dec")
        month = "12";
    else
        qDebug() << "No Valid Month" << endl;

    return month;

    // This function takes a 3 letter month value that is taken from "QDate::currentDate()" and
    // converts it into a two number string that is formatted to work with our database.
    // Ideally this would in a switch statement however that only functions properly with integer values or enum values.
}
void MainWindow::on_createMember_clicked()
{
    QString name;
    QString type;
    QString memberId;
    QString year;
    QString month;
    QString day;
    QString spent = "0.0";
    QString rebate = "0.0";
    float   renewal = 0.0;

    QDate date = QDate::currentDate();
    QString stringDate = date.toString();
    QString monthDate = stringDate.mid( 4, 3);
    QString dayDate = stringDate.mid(8,2);
    QString dayYear;

    if (dayDate.toInt() < 10)
        {
            dayYear = stringDate.mid(10,5);
            qDebug() << "The Current Date is less than 10" << endl;
        }
    else
        {
            dayYear = stringDate.mid(11,5);
            qDebug() << "The Current Date is greater than 10" << endl;
        }

    qDebug() << dayYear;
    int intYear = dayYear.toInt() + 1;
    year = QString::number(intYear);

    month = getMonth(monthDate);
    if (dayDate.toInt() < 10)
    {
        dayDate = "0" + dayDate;
        dayDate = dayDate.mid(0,2);
    }
    qDebug() << dayDate << endl;
    qDebug() << year << endl;
    /*
     * QDate date takes the current date in the format as "11 - 06 - 2019" in a QDate value.
     * It is then converted into a string wich converts it into the format "Wed Nov 6 2019
     * The new string is broken down into substring which individually hold the month, day, and year.
     *
     * The Year in converted to an integer so it can be incremented by one, this is because the memberships expires in one year.
     * The new value is converted back to a string.
     *
     * The month substring is passed into a function which converts it from a 3 letter string to a two number format.
     * Example:
     * Jan will be converted into 01
     *
     * Day is sent into an if statement which converts it to an int, a,d if that value is less than 10 a 0 is placed infront of its number
     * Example:
     * 6 will be converted into 06
     */

    name = ui->nameEdit->text();
    type = ui->typeBox->currentText();
    memberId =generateMemberID();

    // set renewal cost
     if (type == "Regular")
         renewal = 65.00;
     else if (type == "Executive")
         renewal = 120.00;
     else
         qDebug() << " MainWindow::on_createMember_clicked() Error - improper membership type \n";

    /*
     * memberId is created before the execution which consistently generates a new 5 digit number to be assigned as a unique memberId
     */

    QSqlQuery qry;
    qry.prepare("INSERT INTO member (id, name, type, year, month, day, spent, rebate, renewal )"
                " values( '"+memberId+"','"+name+"','"+type+"','"+year+"','"+month+"','"+dayDate+"', '"+spent+"','"+rebate+"', '"+QString::number(renewal)+"')");
    if(!qry.exec())
    {
        qDebug() << memberId << " " << name << " " << type << " " << year << " " << month << " " << dayDate <<
                    " " << spent << " " << rebate << " " << renewal << endl;
        qDebug() <<"error Loading values to db" << endl;
    }

    /*
     * All values are passed into a query which updates the member table of the database that with the new values and sets their total spent
     * and their rebate to 0.0. These 0's are placeholder values which will be changed once the admin makes a purchase on the newly made account.
     */


    QMessageBox::information(this,"Account Creation", "Member Sucsessfully Created with a Unique Member ID of " + memberId);
    ui->nameEdit->setText("");

    ui->memberName->setText(name);
    ui->memberType->setText(type);
    ui->memberId->setText(memberId);
    ui->adminTable->setModel(m_controller->getInventoryQueryModel());
        ui->adminTable->resizeColumnsToContents();

}

void MainWindow::on_LoadMemberInfo_clicked()
{
       m_controller->readMemberFile();

       ui->totalSalesLabel->clear();
       ui->totalCustomers->clear();
       ui->totalRegularCustomers->clear();
       ui->totalExecutiveCustomers->clear();
}

void MainWindow::on_SearchItembyname_clicked()
{
    QString name = QInputDialog::getText(this,"Search For Item", "Enter the Item Name");
    showTables();

    ui->managerTable->setModel(m_controller->getCommoditiesQueryModelbyName(name));
    ui->managerTable->resizeColumnsToContents();

    ui->totalSalesLabel->clear();
    ui->totalCustomers->clear();
    ui->totalRegularCustomers->clear();
    ui->totalExecutiveCustomers->clear();
}

void MainWindow::on_SearchCustomerByID_clicked()
{
    int ID = QInputDialog::getInt(this,"Search For Customer", "Enter the Item ID");

    Member* member = m_controller->getMemberById(ID);

    QString condition = "member_id =";


    condition += QString::number(ID);
    showTables();
    ui->managerTable->setModel(m_controller->getRecordsQueryModelWithCondition(condition));
    ui->managerTable->resizeColumnsToContents();

    ui->totalSalesLabel->clear();
    ui->totalCustomers->clear();
    ui->totalRegularCustomers->clear();
    ui->totalExecutiveCustomers->clear();
}

void MainWindow::on_adminTable_clicked(const QModelIndex &index)
{

    QString name;

    if(index.isValid())
    {
        QSqlQuery qry;
        name = index.data().toString();
        QString price;
        QString subTotal;
        ui->nameShow->setText(name);

        qry.prepare("Select * from inventory where item = '"+name+"'");

        if (qry.exec())
        {
            while(qry.next())
            {
                price = qry.value(1).toString();
                subTotal = (QString::number(price.toDouble() * 1.0775));
                ui->priceShow->setText(QString::number(price.toDouble(),'g',6));
                ui->subShow->setText(QString::number(subTotal.toDouble(),'g',4));
            }
        }

    }
}

void MainWindow::on_FinalizePurchase_clicked()
{
        QString price;
        QString subtotal;
        QString rebate;
        QString name;
        QString item;
        QString memberType;
        QString memberID;
        QSqlQuery qry;

        QString year;
        QString month;
        QString day;
        double savedSubtotal = 0.0;
        double savedRebate = 0.0;
        int quantity;

        // TO KEEP MY TRAIN OF THOUGHT MAKE A QRY AND ADD THE VAULE OF SUBTOTAL TO SAVED SUBTOTAL AND REUPDATE THE VALUE.

        price = ui->priceShow->text();
        name = ui->memberName->text();
        memberType = ui->memberType->text();
        memberID = ui->memberId->text();
        item = ui->nameShow->text();
        subtotal = ui->subShow->text();
        quantity = ui->spinBox->value();

        qDebug() << subtotal;
        if(ui->priceShow->text() != "")
        {
        rebate = QString::number((price.toDouble() * quantity) * 0.02);
        subtotal = QString::number(subtotal.toDouble() * quantity);
        qry.prepare("select * from member where id = '"+memberID+"'");

        qDebug() << subtotal;
        if(qry.exec())
        {
            while(qry.next())
            {
                savedSubtotal = qry.value(6).toDouble();
                savedRebate = qry.value(7).toDouble();

                savedSubtotal = savedSubtotal + subtotal.toDouble();
                savedRebate = savedRebate + rebate.toDouble();
            }
        }
        qDebug() << savedSubtotal << " " << savedRebate << endl;
        qry.prepare("update member set spent = '"+QString::number(savedSubtotal)+"', rebate = '"+QString::number(savedRebate)+"' where name = '"+name+"'");
        if(!qry.exec())
        {
            qDebug() << "Query failed to execute" << endl;
        }
        QMessageBox::information(this,"Purchase Complete", "Purchase Has Successfully Been Completed by Member " + name);

        QString dayYear;
        QDate date = QDate::currentDate();
        QString stringDate = date.toString();
        QString monthDate = stringDate.mid( 4, 3);
        QString dayDate = stringDate.mid(8,2);

        if (dayDate.toInt() < 10)
            {
                dayYear = stringDate.mid(10,5);
                qDebug() << "The Current Date is less than 10" << endl;
            }
        else
            {
                dayYear = stringDate.mid(11,5);
                qDebug() << "The Current Date is greater than 10" << endl;
            }

        int intYear = dayYear.toInt();
        year = QString::number(intYear);
        qDebug() << date << endl;

        qDebug() << monthDate << endl;
        qDebug() << year << endl;
        qDebug() << stringDate << endl;

        month = getMonth(monthDate);
        if (dayDate.toInt() < 10)
        {
            dayDate = "0" + dayDate;
            dayDate = dayDate.mid(0,2);
        }

        QString finalDate = month + '/' + dayDate + '/' + year;

            savetoNewFile(finalDate, memberID,item, price, QString::number(quantity));

            QString fullMonth = getFullMonth(month);
            QString fullDate = fullMonth + ", " + dayDate +", "+ year;
            qDebug() << fullDate;


            changeToAdmin();
        }
        else
            QMessageBox::warning(this, "Purchase Failure", "You Must Select an Item to Purchase Before Continuing");


}

void MainWindow::on_BackButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->MAINWINDOW);
    page = 0;
}

void MainWindow::on_BacktoMAINADMIN_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TransitionalAdminPage);
}

void MainWindow::on_LogoutfromAdmin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->MAINWINDOW);
    page = 0;
}

void MainWindow::on_BackFromVsoft_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TransitionalAdminPage);
}

void MainWindow::on_ViewMembersadmin_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->AdminMemberpage);

}

void MainWindow::on_adminviewmember_clicked()
{
        ui->adminmembertable->setModel(m_controller->getMembersQueryModel());
        ui->adminmembertable->resizeColumnsToContents();
        ui->adminmembertable->showColumn(6);    // show "spent" column
        ui->adminmembertable->showColumn(7);    // show "rebate" column
        ui->adminmembertable->show();           // display results in table
}

void MainWindow::on_dateEdit_userDateChanged(const QDate &date)
{
    int month = date.month();
    qDebug() << month;
    int year = date.year();
    qDebug() << year;

    ui->adminmembertable->setModel(m_controller->getMembersExpiredAttheMonth(date.year(),date.month()));
    ui->adminmembertable->setModel(m_controller->getMembersExpiredAttheMonth(date.year(),date.month()));    // Get members whose expiration date matches month and year
    ui->adminmembertable->resizeColumnsToContents();    // Match column width to max entry width
    ui->adminmembertable->hideColumn(6);    // hide "spent" column
    ui->adminmembertable->hideColumn(7);    // hide "rebate" column
    ui->adminmembertable->show();           // display results in table
}

void MainWindow::on_ClearButton_clicked()
{
    this->ui->username->setText("");
    this->ui->password->setText("");
}

void MainWindow::on_BackFromInventory_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->TransitionalAdminPage);
}

void MainWindow::on_ViewInventory_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->AdminIventoryPage);
}

void MainWindow::on_ViewInventory_2_clicked()
{
    ui->TableAdminInventory->setModel(m_controller->getInventoryQueryModel());
    ui->TableAdminInventory->resizeColumnsToContents();
}
void MainWindow::savetoNewFile(QString date, QString ID, QString item, QString price, QString QTY)
{
    QString year;
    QString month;
    QString day;

    QDate dates = QDate::currentDate();
    QString stringDate = dates.toString();
    QString monthDate = stringDate.mid( 4, 3);
    QString dayDate = stringDate.mid(8,2);
    QString dayYear;

    if (dayDate.toInt() < 10)
        {
            dayYear = stringDate.mid(10,5);
            qDebug() << "The Current Date is less than 10" << endl;
        }
    else
        {
            dayYear = stringDate.mid(11,5);
            qDebug() << "The Current Date is greater than 10" << endl;
        }

    int intYear = dayYear.toInt();
    year = QString::number(intYear);

    month = getMonth(monthDate);
    if (dayDate.toInt() < 10)
    {
        dayDate = "0" + dayDate;
        dayDate = dayDate.mid(0,2);
    }

    QString finalDate = month + dayDate + year;

    QFile file(QDir::homePath() + "/" + finalDate + ".txt");

    if(!file.exists())
    {
        qDebug() << file.fileName() << " does not exist";
    }

    if(file.open(QIODevice::Append| QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream txtStream (&file);

        qDebug() << "~ Writing To File ~";

        txtStream << date << endl;
        txtStream << ID << endl;
        txtStream << item << endl;
        txtStream << price << endl;
        txtStream << QTY << endl;

        file.close();
    }
    else
    {
        qDebug() << "Could not open the fie";
        return;
    }
}

QString MainWindow ::getFullMonth(QString month)
{
    if (month == "01")
        month = "January";
    else if (month == "02")
        month = "February";
    else if (month == "03")
        month = "March";
    else if (month == "04")
        month = "April";
    else if (month == "05")
        month = "May";
    else if (month == "06")
        month = "June";
    else if (month == "07")
        month = "July";
    else if (month == "08")
        month = "August";
    else if (month == "09")
        month = "September";
    else if (month == "10")
        month = "October";
    else if (month == "11")
        month = "November";
    else if (month == "12")
        month = "December";
    else
        qDebug() << "No Valid Month" << endl;

    return month;

    // This function takes a 3 letter month value that is taken from "QDate::currentDate()" and
    // converts it into a two number string that is formatted to work with our database.
    // Ideally this would in a switch statement however that only functions properly with integer values or enum values.
}

void MainWindow::on_AddInventory_clicked()
{

    QString name = QInputDialog::getText(this,"Add Item", "Enter the Item Name");
    double price = QInputDialog::getDouble(this,"Price For Item", "Enter the Item price", 0.00, 0.00, 999999.99, 2);
                                        // Default price is $0, min price is $0, max price is $999,999.99, max two decimal places
    m_controller->addInventory(name,price);
    ui->TableAdminInventory->setModel(m_controller->getInventoryQueryModel());
}


void MainWindow::on_TableAdminInventory_clicked(const QModelIndex &index)
{

    QString name;
    QString price;


    if(index.isValid())
    {
        QSqlQuery qry;
        name = index.data().toString();

        qry.prepare("Select * from inventory where item = '"+name+"'");

        if (qry.exec())
        {
            while(qry.next())
            {
                price = qry.value(1).toString();
                ui->Itemshow->setText(name);
                ui->ItemPrice->setText(QString::number(price.toDouble(),'g',6));
            }
        }

    }
}

void MainWindow::on_Delete_clicked()
{
    m_controller->deleteInventory(ui->Itemshow->text());
    ui->TableAdminInventory->setModel(m_controller->getInventoryQueryModel());
    QMessageBox::warning(this, "Delete Successful", "You have Sucsessfully Deleted " + ui->Itemshow->text() + " from the Inventory");
    ui->Itemshow->clear();
    ui->ItemPrice->clear();

}

void MainWindow::on_Adminsortmember_clicked()
{
    ui->adminmembertable->setModel(m_controller->getMembersQueryModelSortedByName());
}

void MainWindow::on_AdminDeleteCustomer_clicked()
{
    m_controller->deleteCustomer(ui->Adminmembername->text());
    ui->adminmembertable->setModel(m_controller->getMembersQueryModel());
    ui->adminmembertable->resizeColumnsToContents();
    ui->Adminmembername->clear();
    ui->adminmemberID->clear();
}

void MainWindow::on_adminmembertable_clicked(const QModelIndex &index)
{
    QString name;
    int id;


    if(index.isValid())
    {
        QSqlQuery qry;
        name = index.data().toString();

        qry.prepare("Select * from member where name = '"+name+"'");

        if (qry.exec())
        {
            while(qry.next())
            {
                id = qry.value(0).toInt();
                ui->Adminmembername->setText(name);
                ui->adminmemberID->setNum(id);
            }
        }

    }
}

void MainWindow::on_AdminAddCustomer_clicked()
{
    bool ok;
    QStringList type = {"Regular", "Executive"};
    QString rank;
    QString name = QInputDialog::getText(this,"Add Member", "Enter the Member's Name");
    if (name == "")
    {
        QMessageBox::warning(this, "Name Error", "The Member's Name Field Cannot Be Left Blank!");
        ui->stackedWidget->setCurrentWidget(ui->AdminMemberpage);
    }
    else
    {
        QString Type = QInputDialog::getItem(this,"Add Member", "Member Type: ", type, 0, false, &ok);
        qDebug() << Type << endl;
        qDebug() << name << endl;
        QString id = generateMemberID();
        qDebug() << id << endl;
        m_controller->addCustomer(name,id.toInt(),Type);
        QMessageBox::information(this, "Member Creation Successful", "Member " + name + " has been created succsessfully with"
                                                                                        " unique member ID: " + id);
        ui->adminmembertable->setModel(m_controller->getMembersQueryModel());
        ui->adminmembertable->resizeColumnsToContents();
    }
}

//


void MainWindow::on_Viewmembermanager_clicked()
{
   ui->managerTable->setModel(m_controller->getRecordsQueryModel());
   showTables();
   ui->managerTable->resizeColumnsToContents();

   ui->totalSalesLabel->clear();
   ui->totalCustomers->clear();
   ui->totalRegularCustomers->clear();
   ui->totalExecutiveCustomers->clear();
}

void MainWindow::on_managerTable_clicked(const QModelIndex &index)
{
 /* The on_managerTable_clicked function interacts with the manager table model
  * When the user clicks on one of the names of the member's displayed in the table
  * it gathers information about that member; member's ID, member's Name, how much
  * the member has spent and what type of member they are.
  *
  * This information is then passed into another function called checkUpgrade, which will
  * determine if the member's should upgrade from their regular status, downgrade from
  * their exectuive status, remain an executive, or lastly remain a regular member.
  *
  * This is determined by taking their total spent and multiplying it by 0.02
  * (2% is the rebate amount for executive members.) If the regular member's
  * potential rebate is greater than the cost of the membership upgrade, $55. They
  * are then prompted with a recommendadton, if it is not beneficial they will not
  * bbe prompted to upgrade. The same applies with the exectuve members, however if their rebate
  * is less than the cost of the upgrade, they are then prompted to downgrade their membership.
  */
    QString name;
    QString memberId;
    QString rank;

    if(index.isValid())
    {
        QSqlQuery qry;
        name = index.data().toString();
        qry.prepare("Select * from member where name = '"+name+"'");

        if(qry.exec()){
            while(qry.next())
            {
                double spent = qry.value(6).toDouble();
                memberId = qry.value(0).toString();
                rank = qry.value(2).toString();

                checkUpgrade(spent, memberId, rank);

            }
        }


    }
}

bool MainWindow::checkUpgrade(double spent, QString ID, QString rank)
{
    double rebate = spent * 0.02;
    if (rank == "Regular" && rebate >= 55)
    {
        QMessageBox::information(this, "Member Status", "Upgrade reccomendation has been sent to the Regular Member #" + ID);
        return true;
    }
    else if (rank == "Regular" && rebate < 55)
    {
        QMessageBox::information(this, "Member Status", "Upgrade not reccomended for Member #" + ID);
        return false;
    }
    else if (rank == "Executive" && rebate >= 55)
    {
        QMessageBox::information(this, "Member Status", "Downgrade not reccomended for Member #" + ID);
        return true;
    }
    else
    {
        QMessageBox::information(this, "Member Status", "Downgrade reccomendation has been sent to the Executive Member #" + ID);
        return false;
    }
}


void MainWindow::on_monthBox_currentIndexChanged(const QString &arg1)
{

    ui->totalSalesLabel->clear();
    ui->totalCustomers->clear();
    ui->totalRegularCustomers->clear();
    ui->totalExecutiveCustomers->clear();

    QString expiringMonth;

    expiringMonth = ui->monthBox->currentText();
    if (expiringMonth == "January")
        expiringMonth = "1";
    else if (expiringMonth == "February")
        expiringMonth = "2";
    else if (expiringMonth == "March")
        expiringMonth = "3";
    else if (expiringMonth == "April")
        expiringMonth = "4";
    else if (expiringMonth == "May")
        expiringMonth = "5";
    else if (expiringMonth == "June")
        expiringMonth = "6";
    else if (expiringMonth == "July")
        expiringMonth = "7";
    else if (expiringMonth == "August")
        expiringMonth = "8";
    else if (expiringMonth == "September")
        expiringMonth = "9";
    else if (expiringMonth == "October")
        expiringMonth = "10";
    else if (expiringMonth == "November")
        expiringMonth = "11";
    else if (expiringMonth == "December")
        expiringMonth = "12";
    else
        qDebug() << "No Valid Month" << endl;

     ui->managerTable->setModel(m_controller->getMembersExpiredAttheMonth(2020,expiringMonth.toInt()));
     ui->managerTable->resizeColumnsToContents();
}

void MainWindow::on_managerMonthBox_currentIndexChanged(const QString &arg1)
{
    QString expiringMonth;

    expiringMonth = ui->managerMonthBox->currentText();
    if (expiringMonth == "January")
        expiringMonth = "1";
    else if (expiringMonth == "February")
        expiringMonth = "2";
    else if (expiringMonth == "March")
        expiringMonth = "3";
    else if (expiringMonth == "April")
        expiringMonth = "4";
    else if (expiringMonth == "May")
        expiringMonth = "5";
    else if (expiringMonth == "June")
        expiringMonth = "6";
    else if (expiringMonth == "July")
        expiringMonth = "7";
    else if (expiringMonth == "August")
        expiringMonth = "8";
    else if (expiringMonth == "September")
        expiringMonth = "9";
    else if (expiringMonth == "October")
        expiringMonth = "10";
    else if (expiringMonth == "November")
        expiringMonth = "11";
    else if (expiringMonth == "December")
        expiringMonth = "12";
    else
        qDebug() << "No Valid Month" << endl;

     ui->adminmembertable->setModel(m_controller->getMembersExpiredAttheMonth(2020,expiringMonth.toInt()));
     ui->adminmembertable->resizeColumnsToContents();
}

void MainWindow::on_pushButton_2_clicked()
{
    // GET BACK TO THIS WHEN FEELING MORE MOTIVATED.
    QString price;
    QString subtotal;
    QString rebate;
    QString name;
    QString item;
    QString memberType;
    QString memberID;
    QSqlQuery qry;

    QString year;
    QString month;
    QString day;
    double savedSubtotal = 0.0;
    double savedRebate = 0.0;
    int quantity;

    // TO KEEP MY TRAIN OF THOUGHT MAKE A QRY AND ADD THE VAULE OF SUBTOTAL TO SAVED SUBTOTAL AND REUPDATE THE VALUE.

    price = ui->priceShow->text();
    name = ui->memberName->text();
    memberType = ui->memberType->text();
    memberID = ui->memberId->text();
    item = ui->nameShow->text();
    subtotal = ui->subShow->text();
    quantity = ui->spinBox->value();

    qDebug() << subtotal;
    if(ui->priceShow->text() != "")
    {
    rebate = QString::number((price.toDouble() * quantity) * 0.02);
    subtotal = QString::number(subtotal.toDouble() * quantity);
    qry.prepare("select * from member where id = '"+memberID+"'");

    qDebug() << subtotal;
    if(qry.exec())
    {
        while(qry.next())
        {
            savedSubtotal = qry.value(6).toDouble();
            savedRebate = qry.value(7).toDouble();

            savedSubtotal = savedSubtotal + subtotal.toDouble();
            savedRebate = savedRebate + rebate.toDouble();
        }
    }
    qDebug() << savedSubtotal << " " << savedRebate << endl;
    qry.prepare("update member set spent = '"+QString::number(savedSubtotal)+"', rebate = '"+QString::number(savedRebate)+"' where name = '"+name+"'");
    if(!qry.exec())
    {
        qDebug() << "Query failed to execute" << endl;
    }

    QMessageBox::information(this,"Purchase Complete", "Items Have Been Successfully added to your transaction");

    QString dayYear;
    QDate date = QDate::currentDate();
    QString stringDate = date.toString();
    QString monthDate = stringDate.mid( 4, 3);
    QString dayDate = stringDate.mid(8,2);

    if (dayDate.toInt() < 10)
        {
            dayYear = stringDate.mid(10,5);
            qDebug() << "The Current Date is less than 10" << endl;
        }
    else
        {
            dayYear = stringDate.mid(11,5);
            qDebug() << "The Current Date is greater than 10" << endl;
        }

    int intYear = dayYear.toInt();
    year = QString::number(intYear);
    qDebug() << date << endl;

    qDebug() << monthDate << endl;
    qDebug() << year << endl;
    qDebug() << stringDate << endl;

    month = getMonth(monthDate);
    if (dayDate.toInt() < 10)
    {
        dayDate = "0" + dayDate;
        dayDate = dayDate.mid(0,2);
    }

    QString finalDate = month + '/' + dayDate + '/' + year;

        savetoNewFile(finalDate, memberID,item, price, QString::number(quantity));

        QString fullMonth = getFullMonth(month);
        QString fullDate = fullMonth + ", " + dayDate +", "+ year;
        qDebug() << fullDate;

        ui->nameShow->clear();
        ui->subShow->clear();
        ui->priceShow->clear();
        ui->spinBox->setValue(0);

    }
    else
        QMessageBox::warning(this, "Purchase Failure", "You Must Select an Item to Purchase Before Continuing");


}


