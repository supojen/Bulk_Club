#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Controller *controller,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_controller(controller)
{
    ui->setupUi(this);

    ui->tableView->setModel(m_controller->getCommoditiesQueryModelWithCondition("item = Steak"));


    QList<Member*> members = m_controller->getMembers();
    for(int index = 0; index < members.count(); index++)
    {
        qDebug() << members[index]->name();
        qDebug() << members[index]->id() << endl;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}






void MainWindow::on_pushButton_clicked()
{
    m_controller->readRecordFile();
}

void MainWindow::on_pushButton_2_clicked()
{
    m_controller->readMemberFile();
}

void MainWindow::on_pushButton_3_clicked()
{
    QString id_str = ui->lineEdit->text();
    int id = id_str.toInt();

    Member* member = m_controller->getMemberById(id);
    ui->label_name->setText(member->name());
    QString spent;
    ui->label_spent->setText(spent.setNum(member->spent(),'f',6));
    QString condition = "member_id =";


    condition += QString::number(id);
    ui->tableView->setModel(m_controller->getRecordsQueryModelWithCondition(condition));
}
