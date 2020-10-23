#include "adduser.h"
#include "ui_adduser.h"
#include "controllusers.h"
#include "config.h"

AddUser::AddUser(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::AddUser)
{
    mUi->setupUi(this);
}

AddUser::~AddUser()
{
    delete mUi;
}
