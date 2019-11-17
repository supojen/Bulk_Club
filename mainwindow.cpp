#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller *controller,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_controller(controller)
{
    ui->setupUi(this);

    QMap<QString, float> items;
    m_controller->getTotalRevenueOfItems(items);


    // Setting the coloums
    ui->tableWidget->setColumnCount(2);
    QStringList coloums_name;
    coloums_name << "item" << "revenue";
    ui->tableWidget->setHorizontalHeaderLabels(coloums_name);
    // Setting the rows
    int index = 0;
    for( auto iter = items.begin(); iter != items.end(); iter++)
    {
         ui->tableWidget->insertRow(ui->tableWidget->rowCount());
         ui->tableWidget->setItem(index,0, new QTableWidgetItem(iter.key()));
         ui->tableWidget->setItem(index,1, new QTableWidgetItem(QString::number(double(iter.value()))));
         index++;
    }


}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::on_btn_record_clicked()
{
    this->m_controller->readRecordFile();
}

void MainWindow::on_btn_member_clicked()
{
    this->m_controller->readMemberFile();
}
