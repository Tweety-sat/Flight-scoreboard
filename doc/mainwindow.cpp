#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "adminmenu.h"
#include "usermenu.h"
#include "config.h"


#include <QFile>
#include <QDataStream>

#include <QDebug>

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->Board_flight->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents); //Подгоняет размер ячеек таблицы
}

MainWindow::~MainWindow()
{
    delete ui;

}

//Администрирование
void MainWindow::on_adminMenu_clicked()
{
    AdminMenu dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}


//Личный кабинет
void MainWindow::on_infoUser_clicked()
{
    UserMenu dialog(this);
    dialog.setWindowTitle(Config::nameApplication);
    dialog.exec();
}






