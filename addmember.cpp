#include "addmember.h"
#include "ui_addmember.h"
#include "QMessageBox"

AddMember::AddMember(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMember)
{
    ui->setupUi(this);
}

AddMember::~AddMember()
{
    delete ui;
}

void AddMember::on_pushButton_clicked()
{
    QString memberName;
    QString memberType;
    QString memberID;
    QSqlQuery qry;

    if(ui->memberName->text() == "")
        QMessageBox::warning(this,"Null Field", "You Need To Input the Member's Name Before Creating a New Member");
    else
    {
        memberName = ui->memberName->text();
        if(ui->memberComboBox->currentText() == "Regular")
            memberType = "Regular";
        else if (ui->memberComboBox->currentText() == "Executive")
            memberType = "Executive";

        memberID = m_window->generateMemberID();
        ui->memberID->setText(memberID);

        qry.exec("Insert into member (id, name, type) values ('"+memberID+"','"+memberName+"','"+memberType+"')");

        QMessageBox::information(this,"Add Member","New Member Created Sucsessfully with MemberID of " + memberID);

        hide();
    }
}
