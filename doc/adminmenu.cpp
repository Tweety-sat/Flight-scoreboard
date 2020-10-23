#include "adminmenu.h"
#include "ui_adminmenu.h"
#include "controllflights.h"
#include "controllusers.h"
#include "mainwindow.h"
#include "config.h"

AdminMenu::AdminMenu(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::AdminMenu)
{
    mUi->setupUi(this);
}

AdminMenu::~AdminMenu()
{
    delete mUi;
}

//Нажатие кнопки управления рейсами
void AdminMenu::on_butControlFlights_clicked()
{
    ControlFlights dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}

//Нажатие кнопки управления пользователями
void AdminMenu::on_butControlUsers_clicked()
{
    ControlUsers dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}
