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
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    this->ui->username->setText("");
    this->ui->password->setText("");
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
    ui->stackedWidget->setCurrentWidget(ui->adminLogin);
    page++;
}

void MainWindow::changeToManager()
{
    ui->stackedWidget->setCurrentWidget(ui->managerLogin);
    page++;
}

void MainWindow::changeToValidate()
{
    ui->stackedWidget->setCurrentWidget(ui->addMember);
}

void MainWindow::on_viewItems_clicked()
{
   ui->managerTable->setModel(m_controller->getCommoditiesQueryModel());
}

void MainWindow::on_loadSales_clicked()
{
    m_controller->readRecordFile();
}

void MainWindow::on_comboBox_currentIndexChanged(const QString &arg1)
{
    QString date = ui->comboBox->currentText();
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

}
void MainWindow::showTables()
{
    ui->managerTable->setColumnHidden(0,false);
    ui->managerTable->setColumnHidden(2,false);
    ui->managerTable->setColumnHidden(3,false);
    ui->managerTable->setColumnHidden(4,false);
}
void MainWindow::on_loadSales_2_clicked()
{
   m_controller->readMemberFile();

}

void MainWindow::on_comboBox_2_currentIndexChanged(const QString &arg1)
{
    QString select = ui->comboBox_2->currentText();

    if(select == "Sort By ID")
    {
      showTables();
      ui->managerTable->setModel(m_controller->getRevenueSortedById());

    }
    if(select == "Sort By REV")
    {
       showTables();
       ui->managerTable->setModel(m_controller->getRevenueSortedByRev());
    }
}

void MainWindow::on_validate_clicked()
{
    changeToValidate();
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

    QDate date = QDate::currentDate();
    QString stringDate = date.toString();
    QString monthDate = stringDate.mid( 4, 3);
    QString dayDate = stringDate.mid(8,2);
    QString dayYear = stringDate.mid(11,5);

    qDebug() << dayYear;
    int intYear = dayYear.toInt() + 1;
    year = QString::number(intYear);

    month = getMonth(monthDate);
    if (dayDate.toInt() < 10)
    {
        dayDate = "0" + dayDate;
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

    /*
     * memberId is created before the execution which consistently generates a new 5 digit number to be assigned as a unique memberId
     */

    QSqlQuery qry;
    qry.prepare("INSERT INTO member (id, name, type, year, month, day, spent, rebate )"
                " values( '"+memberId+"','"+name+"','"+type+"','"+year+"','"+month+"','"+dayDate+"', '"+spent+"','"+rebate+"')");
    if(!qry.exec())
    {
        qDebug() << memberId << " " << name << " " << type << " " << year << " " << month << " " << dayDate <<
                    " " << spent << " " << rebate << endl;
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


    ui->adminTable->setModel(m_controller->getCommoditiesQueryModel());
    ui->adminTable->resizeColumnsToContents();
}

void MainWindow::on_adminTable_clicked(const QModelIndex &index)
{

    QString name;

    if(index.isValid())
    {
        QSqlQuery qry;
        name = index.data().toString();
        ui->nameShow->setText(name);

        qry.prepare("Select * from commodity where item = '"+name+"'");
        if (qry.exec())
        {
            while(qry.next())
            {
                ui->priceShow->setText(qry.value(1).toString());
                qDebug() << qry.value(1).toString();

            }
        }

    }
}
