#ifndef REGISTRATION_H
#define REGISTRATION_H

#include <QWidget>

namespace Ui {
class SignUp;
}

/*!
    \brief Класс регистрации.
    Данный класс предназначен для регистрации пользователей.
*/
class SignUp : public QWidget
{
    Q_OBJECT

public:
    /// Перечисление возсожных типов регистрации
    enum TypeRegistration { Passenger,  ///< Указывает, что регистрируемый пользователь получает статус администратор
                            Admin  ///< Указывает, что регистрируемый пользователь получает статус пассажира
                          };
    /*!
    Конструктор класса регистрации
    \param typeReg передает тип регистрации
    \param parent ссылка на родительский объект
    */
    explicit SignUp(TypeRegistration typeReg, QWidget *parent = nullptr);
    ~SignUp();

private:
    Ui::SignUp *mUi;
    TypeRegistration m_typeReg;
    bool isLoginExists(const QString &login);

signals:
    void openAuthorization(); ///< Сигнал оповещающий о необходимости открытия окна авторизации

private slots:
    void on_accept_clicked();
};


#endif // REGISTRATION_H
