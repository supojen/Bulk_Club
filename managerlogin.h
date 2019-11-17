#ifndef MANAGERLOGIN_H
#define MANAGERLOGIN_H

#include <QDialog>

namespace Ui {
class managerLogin;
}

class managerLogin : public QDialog
{
    Q_OBJECT

public:
    explicit managerLogin(QWidget *parent = nullptr);
    ~managerLogin();

private:
    Ui::managerLogin *ui;
};

#endif // MANAGERLOGIN_H
