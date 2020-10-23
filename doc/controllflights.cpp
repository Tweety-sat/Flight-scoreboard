#include "controllflights.h"
#include "ui_controllflights.h"
#include "addflight.h"
#include "adminmenu.h"
#include "config.h"

ControlFlights::ControlFlights(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::ControlFlights)
{
    mUi->setupUi(this);
    mUi->BoardFlight->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents); //Подгоняет размер ячеек таблицы
}

ControlFlights::~ControlFlights()
{
    delete mUi;
}

//Добавить рейс
void ControlFlights::on_butAdd_clicked()
{
    AddFlight dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}

