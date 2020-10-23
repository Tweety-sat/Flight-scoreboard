#include "usermenu.h"
#include "ui_usermenu.h"
#include "user.h"
#include "mainwindow.h"
#include "LKUser.h"
#include "config.h"
#include "authorizaiton.h"
#include "registration.h"

UserMenu::UserMenu(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::UserMenu)

{
    mUi->setupUi(this);
}

UserMenu::~UserMenu()
{
    delete mUi;
}


void UserMenu::on_info_clicked()
{
    InfoUser dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}

void UserMenu::on_author_clicked()
{
    SignIn dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}

void UserMenu::on_registr_clicked()
{
    SignUp dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}
