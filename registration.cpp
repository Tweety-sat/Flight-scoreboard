#include "registration.h"
#include "ui_registration.h"
#include "user.h"


SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::SignUp)

{
    mUi->setupUi(this);
}

SignUp::~SignUp()
{
    delete mUi;
}


