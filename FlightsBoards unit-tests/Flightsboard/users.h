#ifndef USERS_H
#define USERS_H

#include <QString>
#include <QDataStream>
#include <QMap>

/*!
    \brief Класс пользователя.
    Данный класс существует для осуществления действий над пользователями, включая запись и чтение данных о пользователе.
*/
class User
{
public:
    /// Набор возможных статусов пользователя
    enum Status { Passenger, ///< Указывает, что пользователь - пассажир
                  Dispatcher , ///< Указывает, что статус пользователя - диспетчер
                  Admin ///< Указывает, что статус пользователя - администратор
                };

    User();

    /*!
    Конструктор класса
    \param login Логин пользователя
    \param password Пароль пользователя
    \param status Статус пользователя
    */
    User(const QString &login, const QString &password, const Status &status);


    ///Метод получения логина пользователя
    const QString &login() const;
    ///Метод получения пароля пользователя
    const QString &password() const;
    ///Метод получения статуса пользователя
    const Status &status() const;
    ///Метод получения статуса пользователя строкой
    const QString statusString() const;

    ///Установка данных пользователя
    void setData(const QString &login, const QString &password, const Status &status);
    ///Установка лоигна пользователя
    void setLogin(const QString &login);
    ///Установка пароля пользователя
    void setPassword(const QString &password);

    ///Метод установки значения статуса
    void setStatus(const Status &status);


    ///Повышение статуса
    bool upStatus();
    ///Понижение статуса
    bool downStatus();

    ///Статический метод, возвращающий список соответствий статуса его строковому типу
    static QMap<Status, QString> getListStatus();

private:
    QString m_login;
    QString m_password;
    Status m_status;
};

/// Запись пользователя в поток
inline QDataStream &operator<< (QDataStream &ost, const User &user)
{
    ost << user.login() << user.password() << user.status();
    return ost;
}

/// Считывание пользователя из потока
inline QDataStream &operator>> (QDataStream &ist, User &user)
{
    QString login;
    QString password;
    int status;
    ist >> login >> password >> status;
    user.setData(login, password, User::Status(status));

    return ist;
}


#endif // USERS_H


