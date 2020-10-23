#include "addflight.h"
#include "ui_addflight.h"
#include "controllflights.h"
#include "config.h"

AddFlight::AddFlight(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::AddFlight)
{
    mUi->setupUi(this);
}

AddFlight::~AddFlight()
{
    delete mUi;
}

