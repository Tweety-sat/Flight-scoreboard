#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QDialog>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:

    explicit SignUp(QWidget *parent = nullptr);
    ~SignUp();


private slots:


private:
    Ui::SignUp *mUi;
};

#endif // REGISTRATION_H
