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


private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();
    void changeToAdmin();
    void changeToManager();
    void changeToValidate();

    void on_viewItems_clicked();

    void on_loadSales_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_loadSales_2_clicked();


    void on_comboBox_2_currentIndexChanged(const QString &arg1);

    void on_validate_clicked();

    void showTables();

    QString generateMemberID();
    QString getMonth(QString month);



    void on_createMember_clicked();

protected:
    void keyPressEvent(QKeyEvent* pe);

private:
    Ui::MainWindow *ui;
    Controller *m_controller;
};
#endif // MAINWINDOW_H
