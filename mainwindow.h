#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QSqlQuery>
#include <QSqlError>
#include <QtDebug>
#include <QFileInfo>
#include <QKeyEvent>
#include <QDate>
#include <QInputDialog>
#include "controller.h"



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Controller *controller, QWidget *parent = nullptr);
    ~MainWindow();

    int page = 0;

private slots:


    void on_pushButton_clicked();
    void changeToAdmin();
    void changeToManager();
    void on_viewItems_clicked();

    void on_loadSales_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void showTables();
    QString generateMemberID();
    QString getMonth(QString month);
    void on_createMember_clicked();
    void on_LoadMemberInfo_clicked();
    void changetoValidationTool();

    void on_ValidateSoftware_clicked();

    void on_SearchItembyname_clicked();
    void on_SearchCustomerByID_clicked();
    void on_FinalizePurchase_clicked();
    void on_adminTable_clicked(const QModelIndex &index);

    void on_BackButton_clicked();

    void on_BacktoMAINADMIN_clicked();

    void on_LogoutfromAdmin_clicked();

    void on_BackFromVsoft_clicked();

    void on_ViewMembersadmin_clicked();

    void on_adminviewmember_clicked();

    void on_dateEdit_userDateChanged(const QDate &date);

    void on_ClearButton_clicked();

    void on_BackFromInventory_clicked();

    void on_ViewInventory_clicked();

    void on_ViewInventory_2_clicked();
    void savetoNewFile(QString date, QString ID, QString item, QString price, QString QTY);
    QString getFullMonth(QString month);


protected:
    void keyPressEvent(QKeyEvent* pe);

private:
    Ui::MainWindow *ui;
    Controller *m_controller;
};
#endif // MAINWINDOW_H
