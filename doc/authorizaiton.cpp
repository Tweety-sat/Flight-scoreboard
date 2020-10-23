#include "authorizaiton.h"
#include "ui_authorizaiton.h"
#include "user.h"
#include "registration.h"


SignIn::SignIn(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::SignIn)

{
    mUi->setupUi(this);
}

SignIn::~SignIn()
{
    delete mUi;
}


