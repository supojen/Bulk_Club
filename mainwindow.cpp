#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller *controller,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_controller(controller)
{
    ui->setupUi(this);

    //ui->tableView->setModel(m_controller->getCommoditiesQueryModelWithCondition("item = Steak"));
    //ui->tableView->setModel(m_controller->getMembersQuesryModelOrderBy("spent"));
    //ui->tableView->setModel(m_controller->getRecordsQueryModelWithCondition("member_id = 12345"));
    ui->tableView->setModel(m_controller->getMembersExpiredAtTheMonth(2020,12));

}

MainWindow::~MainWindow()
{
    delete ui;
}






