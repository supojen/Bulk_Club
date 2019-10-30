#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminlogin.h"
#include "managerlogin.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    if(!connOpen())
    {
        ui-> statusLabel ->setText("Failed to open the Database");
    }
    else
        ui-> statusLabel ->setText("Database Connected");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    this->ui->lineEdit->setText("");
    this->ui->lineEdit_2->setText("");
}

void MainWindow::on_pushButton_clicked()
{
    QString username = ui->lineEdit ->text();
    QString password = ui->lineEdit_2->text();

    if(!connOpen())
    {
        qDebug() << "Failed to open the Database";
    }
    QSqlQuery qry;
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
            hide();
            connClose();
            adminLogin *admin = new adminLogin;
            admin->show();
           }
           else if (count!= 1)
           {
               if(qry.exec("select * from admin where username ='"+username+"' and password ='"+password+"' and rank= '1'"))
                   int count  = 0;
                    while(qry.next())
                    {
                        count++;
                    }
                    if (count == 1)
                    {
                       QMessageBox::information(this,"Login", "Username and Password is correct");
                       hide();
                       connClose();
                       managerLogin *manager = new managerLogin;
                       manager->show();
                    }
                    else
                    {
                        QMessageBox::warning(this,"Login","Username and password is not correct");
                    }
           }
    }
}
