#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QDialog>

namespace Ui {
class SignIn;
}

class SignIn : public QDialog
{
    Q_OBJECT

public:

    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();


private slots:


private:
    Ui::SignIn *mUi;
};

#endif // AUTHORIZATION_H
