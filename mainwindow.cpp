#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(Controller *controller, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      m_controller(controller)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentWidget(ui->MAINWINDOW);
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
                    }
           }
    }
}
void MainWindow::changeToAdmin()
{
    ui->stackedWidget->setCurrentWidget(ui->adminLogin);
}

void MainWindow::changeToManager()
{
    ui->stackedWidget->setCurrentWidget(ui->managerLogin);
}

void MainWindow::on_viewItems_clicked()
{
   ui->managerTable->setModel(m_controller->getCommoditiesQueryModel());
}
