#include "mydialog.h"
#include "QSpinBox"
#include "QTextEdit"
#include "QHBoxLayout"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MyDialog dg;
    dg.show();
    QSpinBox *sBox = new QSpinBox;
    QTextEdit *tEdit = new QTextEdit;
    QHBoxLayout *Hlay = new QHBoxLayout;
    Hlay->addWidget(sBox);
    Hlay->addWidget(tEdit);
    dg.setLayout(Hlay);

    return a.exec();
}
