#include "LK.h"
#include "ui_LK.h"
#include "users.h"
#include "mainwindow.h"

InfoUser::InfoUser(const User &user, QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::InfoUser)

{
    mUi->setupUi(this);
    // Выводим информацию на виджеты, при этом пароль маскируем звездочками
    mUi->Llogin->setText(user.login());

    QString pass = "";
    for (int i = 0; i < user.password().size(); i++)
    {
        pass += '*';
    }
    mUi->LPassword->setText(pass);
    mUi->Lstatus->setText(user.statusString());
}

InfoUser::~InfoUser()
{
    delete mUi;
}
