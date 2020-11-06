#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTextCharFormat>
#include <auth.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::About_Lab1()
{
    auth *dg = new auth();
    dg->show();
}
void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->calendarWidget->setFirstDayOfWeek(Qt::DayOfWeek(index+1));
    QTextCharFormat format;
    format.setForeground(qvariant_cast<QColor>("green"));
    ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(index+1), format);

    QTextCharFormat default_color;
        default_color.setForeground(qvariant_cast<QColor>("black"));
        for (int i = 1; i <= 7; i++)
        {
            ui->calendarWidget->setWeekdayTextFormat(Qt::DayOfWeek(i), (i == index+1?format:default_color));
        }
}
