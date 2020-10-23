#include "LKUser.h"
#include "ui_LKUser.h"
#include "user.h"
#include "mainwindow.h"

InfoUser::InfoUser(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::InfoUser)

{
    mUi->setupUi(this);
}

InfoUser::~InfoUser()
{
    delete mUi;
}

