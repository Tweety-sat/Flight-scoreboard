#ifndef AUTHORIZATION_H
#define AUTHORIZATION_H

#include <QWidget>
class User;

namespace Ui {
class SignIn;
}
/*!
    \brief Класс авторизации.
    Данный класс существует для выполнения авторизации пользователя при входе в систему
*/
class SignIn : public QWidget
{
    Q_OBJECT

public:
    /*!
    Конструктор класса авторизации
    \param parent ссылка на родительский объект
    */
    explicit SignIn(QWidget *parent = nullptr);
    ~SignIn();

private:
    Ui::SignIn *mUi;

        //Если вернет nullptr => пользователь не найден, иначе указатель на данные пользователя
    User *checkUser(const QString &login, const QString &password);

signals:
    ///Сигнал об необходимости открытия окна регистрации
    void openRegistration();
    ///Сигнал об успешном входе
    void succesfulEntry(User*);

private slots:
    void on_sign_clicked();
};


#endif // AUTHORIZATION_H
