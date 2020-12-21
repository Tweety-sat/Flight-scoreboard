#ifndef LK_H
#define LK_H
#include <QDialog>

class User;

namespace Ui {
class InfoUser;
}
/*!
    \brief Класс получения информаии по личному кабинету.
    Данный класс существует для получения пользователем информации об его аккаунте.
*/
class InfoUser : public QDialog
{
    Q_OBJECT

public:
    /*!
    Конструктор класса
    \param user ссылка на пользователя с данными о нем
    \param parent ссылка на родительский объект
    */
     explicit InfoUser(const User &user, QWidget *parent = nullptr);
    ~InfoUser();

private slots:

private:
    Ui::InfoUser *mUi;
};
#endif // LK_H
