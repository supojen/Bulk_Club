#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller *controller,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_controller(controller)
{
    ui->setupUi(this);
    ui->tableView->setModel(m_controller->getCommoditiesQueryModel());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    m_controller->readRecordFile();
    ui->tableView->setModel(m_controller->getCommoditiesQueryModel());
}

void MainWindow::on_pushButton_addMember_clicked()
{
    m_controller->readMemberFile();
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->tableView->setModel(
    m_controller->getCommoditiesQueryModelWithCondition("price > 13.75"));
    ui->tableView->show();
}
