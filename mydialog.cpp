#include "mydialog.h"
#include "ui_mydialog.h"
#include "QSpinBox"
#include "QTextEdit"
#include "QHBoxLayout"

MyDialog::MyDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);
     setWindowTitle("Анкета");

}

MyDialog::~MyDialog()
{
    delete ui;
}

