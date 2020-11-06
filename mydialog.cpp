#include "mydialog.h"
#include "ui_mydialog.h"
#include "QSpinBox"
#include "QTextEdit"
#include "QHBoxLayout"
#include <QComboBox>
#include <QPushButton>
#include <QFileDialog>
#include <QFile>
#include <QIODevice>
#include<QTextStream>
#include <QSaveFile>
#include <QMessageBox>

MyDialog::MyDialog(QWidget *parent) : QDialog(parent),
    ui(new Ui::MyDialog)
{
     setWindowTitle("Анкета");
        Hlay->addWidget(sBox);
        Hlay->addWidget(tEdit);
        setLayout(Hlay);
        Hlay->addWidget(cBox);
        Hlay->addWidget(But);
        cBox->addItem("1");
        cBox->addItem("2");
        cBox->addItem("3");
        But->setText("Сохранить");
        QObject::connect(But, SIGNAL(clicked()), this, SLOT(Wrf()));
}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::Wrf()
{
 //%%По примеру летней практики
    try
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("Save form"), QString(), "(*.txt)");
        QSaveFile outf(fileName);
        outf.open(QIODevice::WriteOnly);
        QTextStream ost(&outf);

        ost << "Spin box: " << sBox->value() << "\nText:" << tEdit->toPlainText() << "\nCombo box: " << cBox->itemText(cBox->currentIndex());

        if (fileName.isEmpty())
        {
            return;
        }
        outf.commit();

    }
    //Проброс исключительных ситуаций
    catch (const std::exception &e)
    {
        QMessageBox::critical(this,"Warning","Something went wrong");
    }
}
