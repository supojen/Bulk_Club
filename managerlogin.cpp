#include "managerlogin.h"
#include "ui_managerlogin.h"

managerLogin::managerLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::managerLogin)
{
    ui->setupUi(this);
}

managerLogin::~managerLogin()
{
    delete ui;
}
