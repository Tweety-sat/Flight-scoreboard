#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QHBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui { class MyDialog; }
QT_END_NAMESPACE

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    MyDialog(QWidget *parent = nullptr);
    ~MyDialog();
private slots:
    void Wrf();
private:
    Ui::MyDialog *ui;
    QComboBox *cBox = new QComboBox;
    QPushButton *But = new QPushButton;
    QSpinBox *sBox = new QSpinBox;
    QTextEdit *tEdit = new QTextEdit;
    QHBoxLayout *Hlay = new QHBoxLayout;

};
#endif // MYDIALOG_H
