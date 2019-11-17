#include "adminlogin.h"
#include "ui_adminlogin.h"

adminLogin::adminLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminLogin)
{
    ui->setupUi(this);
}

adminLogin::~adminLogin()
{
    delete ui;
}
