#ifndef ADDMEMBER_H
#define ADDMEMBER_H

#include <QDialog>
#include "mainwindow.h"


namespace Ui {
class AddMember;
}

class AddMember : public QDialog
{
    Q_OBJECT

public:
    explicit AddMember(QWidget *parent = nullptr);
    ~AddMember();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddMember *ui;
    MainWindow *m_window;
};

#endif // ADDMEMBER_H
