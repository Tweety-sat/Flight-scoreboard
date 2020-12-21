#ifndef ADDUSERS_H
#define ADDUSERS_H

#include <QDialog>
#include "users.h"

namespace Ui {
class AddUsers;
}
/*!
    \brief Класс добавления пользователя.
    Данный класс существует для добавления пользователя администратором.
*/
class AddUsers : public QDialog
{
    Q_OBJECT
public:
    /*!
    Конструктор класса добавления пользователя
    \param parent ссылка на родительский объект
    */
    explicit AddUsers(QWidget *parent = nullptr);
    ~AddUsers();
    ///Метод получения данных о пользователе
    const User &getUser() const;

private:
    Ui::AddUsers *mUi;
    //Для хранения данных добавляемого пользователя
    User m_user;

public slots:
    /// функция определяющая порядок действий после получения сигнала от кнопки "принять"
    void accept();
    /*! \brief Логическая функция, проверяющая существует ли логин
             \param login Логин пользователя
             \returns Существует логин или нет
        */
    bool isLoginExists(const QString &login);
};

#endif // ADDUSERS_H
