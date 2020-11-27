#ifndef USERS_H
#define USERS_H

#include <QString>
#include <QDataStream>
#include <QMap>

class User
{
public:
    // Возможные статусы пользователя
    enum Status { Passenger, Dispatcher , Admin };

    User();
    User(const QString &login, const QString &password, const Status &status);

    // Получение данных
    const QString &login() const;
    const QString &password() const;
    const Status &status() const;
    const QString statusString() const;

    // Установка данных
    void setData(const QString &login, const QString &password, const Status &status);
    void setLogin(const QString &login);
    void setPassword(const QString &password);
    void setStatus(const Status &status);

    // Повышение и понижение статуса
    bool upStatus();
    bool downStatus();

    //Статический метод, возвращающий список соответствий статуса его строковому типу
    static QMap<Status, QString> getListStatus();

private:
    QString m_login;
    QString m_password;
    Status m_status;
};

// Запись пользователя в поток
inline QDataStream &operator<< (QDataStream &ost, const User &user)
{
    ost << user.login() << user.password() << user.status();
    return ost;
}

// Считывание пользователя из потока
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


