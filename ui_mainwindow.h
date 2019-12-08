/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *MAINWINDOW;
    QGroupBox *groupBox;
    QLineEdit *username;
    QLineEdit *password;
    QPushButton *ClearButton;
    QPushButton *pushButton;
    QLabel *Username;
    QLabel *Password;
    QLabel *logo;
    QWidget *ValidationTool;
    QLabel *label_5;
    QLabel *label_6;
    QLineEdit *nameEdit;
    QLabel *label_7;
    QComboBox *typeBox;
    QPushButton *createMember;
    QTableView *adminTable;
    QLabel *label_12;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *memberName;
    QLabel *memberType;
    QLabel *memberId;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QLabel *priceShow;
    QLabel *nameShow;
    QLabel *subShow;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_8;
    QLabel *label_10;
    QLabel *label_9;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout;
    QPushButton *BackFromVsoft;
    QPushButton *FinalizePurchase;
    QWidget *layoutWidget4;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QWidget *managerLogin;
    QTableView *managerTable;
    QPushButton *viewItems;
    QLabel *label_3;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QLabel *label_4;
    QLabel *label_11;
    QPushButton *SearchItembyname;
    QSplitter *splitter;
    QPushButton *loadSales;
    QPushButton *LoadMemberInfo;
    QPushButton *BackButton;
    QPushButton *SearchCustomerByID;
    QPushButton *Viewmembermanager;
    QWidget *TransitionalAdminPage;
    QWidget *layoutWidget5;
    QVBoxLayout *verticalLayout_2;
    QPushButton *ViewMembersadmin;
    QPushButton *ViewInventory;
    QPushButton *ValidateSoftware;
    QPushButton *LogoutfromAdmin;
    QWidget *AdminMemberpage;
    QTableView *adminmembertable;
    QPushButton *BacktoMAINADMIN;
    QSplitter *splitter_2;
    QPushButton *Adminsortmember;
    QPushButton *AdminAddCustomer;
    QPushButton *AdminDeleteCustomer;
    QWidget *layoutWidget6;
    QVBoxLayout *verticalLayout_8;
    QLabel *Adminmembername;
    QLabel *adminmemberID;
    QPushButton *adminviewmember;
    QWidget *layoutWidget7;
    QHBoxLayout *horizontalLayout_2;
    QLabel *ExpirationDate;
    QDateEdit *dateEdit;
    QWidget *AdminIventoryPage;
    QTableView *TableAdminInventory;
    QWidget *layoutWidget8;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *AddInventory;
    QPushButton *Delete;
    QWidget *layoutWidget9;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *ViewInventory_2;
    QPushButton *BackFromInventory;
    QWidget *layoutWidget10;
    QVBoxLayout *verticalLayout_6;
    QLabel *label;
    QLabel *label_2;
    QWidget *layoutWidget11;
    QVBoxLayout *verticalLayout_7;
    QLabel *Itemshow;
    QLabel *ItemPrice;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        MAINWINDOW = new QWidget();
        MAINWINDOW->setObjectName(QString::fromUtf8("MAINWINDOW"));
        groupBox = new QGroupBox(MAINWINDOW);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(190, 320, 441, 251));
        username = new QLineEdit(groupBox);
        username->setObjectName(QString::fromUtf8("username"));
        username->setGeometry(QRect(130, 80, 261, 21));
        password = new QLineEdit(groupBox);
        password->setObjectName(QString::fromUtf8("password"));
        password->setGeometry(QRect(130, 130, 261, 21));
        password->setEchoMode(QLineEdit::Password);
        ClearButton = new QPushButton(groupBox);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));
        ClearButton->setGeometry(QRect(280, 190, 112, 32));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 190, 112, 32));
        Username = new QLabel(groupBox);
        Username->setObjectName(QString::fromUtf8("Username"));
        Username->setGeometry(QRect(20, 80, 111, 16));
        Password = new QLabel(groupBox);
        Password->setObjectName(QString::fromUtf8("Password"));
        Password->setGeometry(QRect(20, 130, 101, 16));
        logo = new QLabel(MAINWINDOW);
        logo->setObjectName(QString::fromUtf8("logo"));
        logo->setGeometry(QRect(260, 30, 280, 280));
        stackedWidget->addWidget(MAINWINDOW);
        ValidationTool = new QWidget();
        ValidationTool->setObjectName(QString::fromUtf8("ValidationTool"));
        label_5 = new QLabel(ValidationTool);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(119, 12, 265, 29));
        label_6 = new QLabel(ValidationTool);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 80, 93, 16));
        nameEdit = new QLineEdit(ValidationTool);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setGeometry(QRect(130, 80, 125, 21));
        label_7 = new QLabel(ValidationTool);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 120, 88, 16));
        typeBox = new QComboBox(ValidationTool);
        typeBox->addItem(QString());
        typeBox->addItem(QString());
        typeBox->setObjectName(QString::fromUtf8("typeBox"));
        typeBox->setGeometry(QRect(130, 110, 99, 32));
        createMember = new QPushButton(ValidationTool);
        createMember->setObjectName(QString::fromUtf8("createMember"));
        createMember->setGeometry(QRect(113, 184, 136, 32));
        adminTable = new QTableView(ValidationTool);
        adminTable->setObjectName(QString::fromUtf8("adminTable"));
        adminTable->setGeometry(QRect(405, 61, 361, 301));
        label_12 = new QLabel(ValidationTool);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(640, 20, 231, 41));
        QFont font;
        font.setPointSize(18);
        font.setBold(true);
        font.setWeight(75);
        label_12->setFont(font);
        layoutWidget = new QWidget(ValidationTool);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(127, 222, 201, 251));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        memberName = new QLabel(layoutWidget);
        memberName->setObjectName(QString::fromUtf8("memberName"));

        verticalLayout->addWidget(memberName);

        memberType = new QLabel(layoutWidget);
        memberType->setObjectName(QString::fromUtf8("memberType"));

        verticalLayout->addWidget(memberType);

        memberId = new QLabel(layoutWidget);
        memberId->setObjectName(QString::fromUtf8("memberId"));

        verticalLayout->addWidget(memberId);

        layoutWidget1 = new QWidget(ValidationTool);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(590, 390, 171, 121));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        priceShow = new QLabel(layoutWidget1);
        priceShow->setObjectName(QString::fromUtf8("priceShow"));

        verticalLayout_3->addWidget(priceShow);

        nameShow = new QLabel(layoutWidget1);
        nameShow->setObjectName(QString::fromUtf8("nameShow"));

        verticalLayout_3->addWidget(nameShow);

        subShow = new QLabel(layoutWidget1);
        subShow->setObjectName(QString::fromUtf8("subShow"));

        verticalLayout_3->addWidget(subShow);

        layoutWidget2 = new QWidget(ValidationTool);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 230, 95, 241));
        verticalLayout_4 = new QVBoxLayout(layoutWidget2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_8 = new QLabel(layoutWidget2);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_4->addWidget(label_8);

        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_4->addWidget(label_10);

        label_9 = new QLabel(layoutWidget2);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_4->addWidget(label_9);

        layoutWidget3 = new QWidget(ValidationTool);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(6, 540, 761, 32));
        horizontalLayout = new QHBoxLayout(layoutWidget3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        BackFromVsoft = new QPushButton(layoutWidget3);
        BackFromVsoft->setObjectName(QString::fromUtf8("BackFromVsoft"));

        horizontalLayout->addWidget(BackFromVsoft);

        FinalizePurchase = new QPushButton(layoutWidget3);
        FinalizePurchase->setObjectName(QString::fromUtf8("FinalizePurchase"));

        horizontalLayout->addWidget(FinalizePurchase);

        layoutWidget4 = new QWidget(ValidationTool);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(409, 395, 101, 111));
        verticalLayout_5 = new QVBoxLayout(layoutWidget4);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_13 = new QLabel(layoutWidget4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        verticalLayout_5->addWidget(label_13);

        label_14 = new QLabel(layoutWidget4);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        verticalLayout_5->addWidget(label_14);

        label_15 = new QLabel(layoutWidget4);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        verticalLayout_5->addWidget(label_15);

        stackedWidget->addWidget(ValidationTool);
        managerLogin = new QWidget();
        managerLogin->setObjectName(QString::fromUtf8("managerLogin"));
        managerTable = new QTableView(managerLogin);
        managerTable->setObjectName(QString::fromUtf8("managerTable"));
        managerTable->setGeometry(QRect(12, 42, 641, 441));
        viewItems = new QPushButton(managerLogin);
        viewItems->setObjectName(QString::fromUtf8("viewItems"));
        viewItems->setGeometry(QRect(10, 500, 181, 32));
        label_3 = new QLabel(managerLogin);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(210, 490, 91, 51));
        comboBox = new QComboBox(managerLogin);
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(290, 500, 191, 32));
        comboBox_2 = new QComboBox(managerLogin);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(570, 500, 191, 32));
        label_4 = new QLabel(managerLogin);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(530, 490, 91, 51));
        label_11 = new QLabel(managerLogin);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(20, -10, 151, 51));
        QFont font1;
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        font1.setStrikeOut(false);
        label_11->setFont(font1);
        SearchItembyname = new QPushButton(managerLogin);
        SearchItembyname->setObjectName(QString::fromUtf8("SearchItembyname"));
        SearchItembyname->setGeometry(QRect(660, 50, 112, 121));
        splitter = new QSplitter(managerLogin);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setGeometry(QRect(10, 530, 761, 32));
        splitter->setOrientation(Qt::Horizontal);
        loadSales = new QPushButton(splitter);
        loadSales->setObjectName(QString::fromUtf8("loadSales"));
        splitter->addWidget(loadSales);
        LoadMemberInfo = new QPushButton(splitter);
        LoadMemberInfo->setObjectName(QString::fromUtf8("LoadMemberInfo"));
        splitter->addWidget(LoadMemberInfo);
        BackButton = new QPushButton(splitter);
        BackButton->setObjectName(QString::fromUtf8("BackButton"));
        splitter->addWidget(BackButton);
        SearchCustomerByID = new QPushButton(managerLogin);
        SearchCustomerByID->setObjectName(QString::fromUtf8("SearchCustomerByID"));
        SearchCustomerByID->setGeometry(QRect(660, 180, 112, 121));
        Viewmembermanager = new QPushButton(managerLogin);
        Viewmembermanager->setObjectName(QString::fromUtf8("Viewmembermanager"));
        Viewmembermanager->setGeometry(QRect(660, 311, 111, 131));
        QFont font2;
        font2.setBold(true);
        font2.setItalic(false);
        font2.setWeight(75);
        font2.setStrikeOut(false);
        Viewmembermanager->setFont(font2);
        stackedWidget->addWidget(managerLogin);
        TransitionalAdminPage = new QWidget();
        TransitionalAdminPage->setObjectName(QString::fromUtf8("TransitionalAdminPage"));
        layoutWidget5 = new QWidget(TransitionalAdminPage);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(230, 50, 321, 441));
        verticalLayout_2 = new QVBoxLayout(layoutWidget5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        ViewMembersadmin = new QPushButton(layoutWidget5);
        ViewMembersadmin->setObjectName(QString::fromUtf8("ViewMembersadmin"));

        verticalLayout_2->addWidget(ViewMembersadmin);

        ViewInventory = new QPushButton(layoutWidget5);
        ViewInventory->setObjectName(QString::fromUtf8("ViewInventory"));

        verticalLayout_2->addWidget(ViewInventory);

        ValidateSoftware = new QPushButton(layoutWidget5);
        ValidateSoftware->setObjectName(QString::fromUtf8("ValidateSoftware"));

        verticalLayout_2->addWidget(ValidateSoftware);

        LogoutfromAdmin = new QPushButton(layoutWidget5);
        LogoutfromAdmin->setObjectName(QString::fromUtf8("LogoutfromAdmin"));

        verticalLayout_2->addWidget(LogoutfromAdmin);

        stackedWidget->addWidget(TransitionalAdminPage);
        AdminMemberpage = new QWidget();
        AdminMemberpage->setObjectName(QString::fromUtf8("AdminMemberpage"));
        adminmembertable = new QTableView(AdminMemberpage);
        adminmembertable->setObjectName(QString::fromUtf8("adminmembertable"));
        adminmembertable->setGeometry(QRect(45, 30, 551, 371));
        BacktoMAINADMIN = new QPushButton(AdminMemberpage);
        BacktoMAINADMIN->setObjectName(QString::fromUtf8("BacktoMAINADMIN"));
        BacktoMAINADMIN->setGeometry(QRect(200, 500, 321, 32));
        splitter_2 = new QSplitter(AdminMemberpage);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setGeometry(QRect(40, 460, 631, 32));
        splitter_2->setOrientation(Qt::Horizontal);
        Adminsortmember = new QPushButton(splitter_2);
        Adminsortmember->setObjectName(QString::fromUtf8("Adminsortmember"));
        splitter_2->addWidget(Adminsortmember);
        AdminAddCustomer = new QPushButton(splitter_2);
        AdminAddCustomer->setObjectName(QString::fromUtf8("AdminAddCustomer"));
        splitter_2->addWidget(AdminAddCustomer);
        AdminDeleteCustomer = new QPushButton(splitter_2);
        AdminDeleteCustomer->setObjectName(QString::fromUtf8("AdminDeleteCustomer"));
        splitter_2->addWidget(AdminDeleteCustomer);
        layoutWidget6 = new QWidget(AdminMemberpage);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(610, 70, 151, 241));
        verticalLayout_8 = new QVBoxLayout(layoutWidget6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        Adminmembername = new QLabel(layoutWidget6);
        Adminmembername->setObjectName(QString::fromUtf8("Adminmembername"));

        verticalLayout_8->addWidget(Adminmembername);

        adminmemberID = new QLabel(layoutWidget6);
        adminmemberID->setObjectName(QString::fromUtf8("adminmemberID"));

        verticalLayout_8->addWidget(adminmemberID);

        adminviewmember = new QPushButton(AdminMemberpage);
        adminviewmember->setObjectName(QString::fromUtf8("adminviewmember"));
        adminviewmember->setGeometry(QRect(40, 420, 301, 32));
        layoutWidget7 = new QWidget(AdminMemberpage);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(360, 424, 301, 23));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget7);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        ExpirationDate = new QLabel(layoutWidget7);
        ExpirationDate->setObjectName(QString::fromUtf8("ExpirationDate"));

        horizontalLayout_2->addWidget(ExpirationDate);

        dateEdit = new QDateEdit(layoutWidget7);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_2->addWidget(dateEdit);

        stackedWidget->addWidget(AdminMemberpage);
        AdminIventoryPage = new QWidget();
        AdminIventoryPage->setObjectName(QString::fromUtf8("AdminIventoryPage"));
        TableAdminInventory = new QTableView(AdminIventoryPage);
        TableAdminInventory->setObjectName(QString::fromUtf8("TableAdminInventory"));
        TableAdminInventory->setGeometry(QRect(12, 12, 271, 551));
        layoutWidget8 = new QWidget(AdminIventoryPage);
        layoutWidget8->setObjectName(QString::fromUtf8("layoutWidget8"));
        layoutWidget8->setGeometry(QRect(420, 40, 301, 101));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget8);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        AddInventory = new QPushButton(layoutWidget8);
        AddInventory->setObjectName(QString::fromUtf8("AddInventory"));

        horizontalLayout_3->addWidget(AddInventory);

        Delete = new QPushButton(layoutWidget8);
        Delete->setObjectName(QString::fromUtf8("Delete"));

        horizontalLayout_3->addWidget(Delete);

        layoutWidget9 = new QWidget(AdminIventoryPage);
        layoutWidget9->setObjectName(QString::fromUtf8("layoutWidget9"));
        layoutWidget9->setGeometry(QRect(420, 170, 301, 151));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget9);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        ViewInventory_2 = new QPushButton(layoutWidget9);
        ViewInventory_2->setObjectName(QString::fromUtf8("ViewInventory_2"));

        horizontalLayout_4->addWidget(ViewInventory_2);

        BackFromInventory = new QPushButton(layoutWidget9);
        BackFromInventory->setObjectName(QString::fromUtf8("BackFromInventory"));

        horizontalLayout_4->addWidget(BackFromInventory);

        layoutWidget10 = new QWidget(AdminIventoryPage);
        layoutWidget10->setObjectName(QString::fromUtf8("layoutWidget10"));
        layoutWidget10->setGeometry(QRect(340, 390, 68, 71));
        verticalLayout_6 = new QVBoxLayout(layoutWidget10);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget10);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_6->addWidget(label);

        label_2 = new QLabel(layoutWidget10);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_6->addWidget(label_2);

        layoutWidget11 = new QWidget(AdminIventoryPage);
        layoutWidget11->setObjectName(QString::fromUtf8("layoutWidget11"));
        layoutWidget11->setGeometry(QRect(440, 390, 151, 71));
        verticalLayout_7 = new QVBoxLayout(layoutWidget11);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        Itemshow = new QLabel(layoutWidget11);
        Itemshow->setObjectName(QString::fromUtf8("Itemshow"));

        verticalLayout_7->addWidget(Itemshow);

        ItemPrice = new QLabel(layoutWidget11);
        ItemPrice->setObjectName(QString::fromUtf8("ItemPrice"));

        verticalLayout_7->addWidget(ItemPrice);

        stackedWidget->addWidget(AdminIventoryPage);

        gridLayout->addWidget(stackedWidget, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "Login", nullptr));
        ClearButton->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        Username->setText(QCoreApplication::translate("MainWindow", "Username:", nullptr));
        Password->setText(QCoreApplication::translate("MainWindow", "Password:", nullptr));
        logo->setText(QString());
        label_5->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:24pt; font-weight:600; text-decoration: underline;\">BulkClub Validation Tool</span></p></body></html>", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "Member Name:", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Member Type:", nullptr));
        typeBox->setItemText(0, QCoreApplication::translate("MainWindow", "Regular", nullptr));
        typeBox->setItemText(1, QCoreApplication::translate("MainWindow", "Executive", nullptr));

        createMember->setText(QCoreApplication::translate("MainWindow", "Create Member", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "Inventory List", nullptr));
        memberName->setText(QString());
        memberType->setText(QString());
        memberId->setText(QString());
        priceShow->setText(QString());
        nameShow->setText(QString());
        subShow->setText(QString());
        label_8->setText(QCoreApplication::translate("MainWindow", "Member Name:", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "Member Type:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "MemberID:", nullptr));
        BackFromVsoft->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        FinalizePurchase->setText(QCoreApplication::translate("MainWindow", "Finalize Purchase", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "Item name", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Price", nullptr));
        label_15->setText(QCoreApplication::translate("MainWindow", "Subtotal", nullptr));
        viewItems->setText(QCoreApplication::translate("MainWindow", "View Items", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Daily Sales:", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("MainWindow", "Select Your Date", nullptr));

        comboBox_2->setItemText(0, QCoreApplication::translate("MainWindow", "Sort Members By ID", nullptr));
        comboBox_2->setItemText(1, QCoreApplication::translate("MainWindow", "Sort Members By REV", nullptr));
        comboBox_2->setItemText(2, QCoreApplication::translate("MainWindow", "Sort item By Rev", nullptr));
        comboBox_2->setItemText(3, QCoreApplication::translate("MainWindow", "Sort item By Name", nullptr));

        label_4->setText(QCoreApplication::translate("MainWindow", "Menu :", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "Manager Page", nullptr));
        SearchItembyname->setText(QCoreApplication::translate("MainWindow", "Search \n"
"item\n"
"By \n"
"Name", nullptr));
        loadSales->setText(QCoreApplication::translate("MainWindow", "Load Daily Sales Report", nullptr));
        LoadMemberInfo->setText(QCoreApplication::translate("MainWindow", "Load Member Info", nullptr));
        BackButton->setText(QCoreApplication::translate("MainWindow", "Back Button", nullptr));
        SearchCustomerByID->setText(QCoreApplication::translate("MainWindow", "Search\n"
"Customer\n"
"By\n"
"ID", nullptr));
        Viewmembermanager->setText(QCoreApplication::translate("MainWindow", "View All\n"
"Transactions", nullptr));
        ViewMembersadmin->setText(QCoreApplication::translate("MainWindow", "View Members", nullptr));
        ViewInventory->setText(QCoreApplication::translate("MainWindow", "View Inventory", nullptr));
        ValidateSoftware->setText(QCoreApplication::translate("MainWindow", "Validate Software", nullptr));
        LogoutfromAdmin->setText(QCoreApplication::translate("MainWindow", "Log Out", nullptr));
        BacktoMAINADMIN->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        Adminsortmember->setText(QCoreApplication::translate("MainWindow", "Sort Name Alphabetically", nullptr));
        AdminAddCustomer->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        AdminDeleteCustomer->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        Adminmembername->setText(QString());
        adminmemberID->setText(QString());
        adminviewmember->setText(QCoreApplication::translate("MainWindow", "View All Members", nullptr));
        ExpirationDate->setText(QCoreApplication::translate("MainWindow", "Expiration", nullptr));
        AddInventory->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        Delete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        ViewInventory_2->setText(QCoreApplication::translate("MainWindow", "View Inventory", nullptr));
        BackFromInventory->setText(QCoreApplication::translate("MainWindow", "Back", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Item:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Price:", nullptr));
        Itemshow->setText(QString());
        ItemPrice->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
