#ifndef MANAGEUSERS_H
#define MANAGEUSERS_H

#include <QDialog>
#include "users.h"

namespace Ui {
class ManageUsers;
}
/*!
    \brief Класс управления пользователями.
    Данный класс предназначен для управления пользователями.
*/
class ManageUsers : public QDialog
{
    Q_OBJECT

public:
    /*!
    Конструктор класса главного окна
    \param parent ссылка на родительский объект
    */
    explicit ManageUsers(QWidget *parent = nullptr);
    ~ManageUsers();

private slots:
    void on_delete_2_clicked();

    void on_add_clicked();
    void slotUpDownStatus();
    void on_lineFind_textChanged(const QString &arg1);

private:
    Ui::ManageUsers *mUi;
    QList<User> m_listUsers;
    // Возвращает количество администраторов в системе
    int countAdmins() const;
};
#endif // MANAGEUSERS_H
