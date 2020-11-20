#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>
class User;

namespace Ui {
class SignIn;
}

class SignIn : public QWidget
{
    Q_OBJECT

public:
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

private:
    Ui::SignIn *mUi;

        //Если вернет nullptr => пользователь не найден, иначе указатель на данные пользователя
    User *checkUser(const QString &login, const QString &password);

signals:
    void openRegistration(); //Сигнал об необходимости открытия окна регистрации
    void succesfulEntry(User*);//Сигнал об успешном входе

private slots:
    void on_sign_clicked();
};


#endif // AUTHORIZATION_H
