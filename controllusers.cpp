#include "controllusers.h"
#include "ui_controllusers.h"
#include "adduser.h"
#include "adminmenu.h"
#include "config.h"

ControlUsers::ControlUsers(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::ControlUsers)
{
    mUi->setupUi(this);
}

ControlUsers::~ControlUsers()
{
    delete mUi;
}

//Добавить пользователя
void ControlUsers::on_butaddw_clicked()
{
    AddUser dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}
