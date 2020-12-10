#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class SignUp;
}

class SignUp : public QWidget
{
    Q_OBJECT

public:
    enum TypeRegistration { Passenger, Admin }; //Перечисление существующих групп пользователей, определит какого пользователя будет регистрировать класс

    explicit SignUp(TypeRegistration typeReg, QWidget *parent = nullptr);
    ~SignUp();

private:
    Ui::SignUp *mUi;
    TypeRegistration m_typeReg;
    bool isLoginExists(const QString &login);

signals:
    void openAuthorization(); //Сигнал оповещающий о необходимости открытия окна авторизации

private slots:
    void on_accept_clicked();
};


#endif // REGISTRATION_H
