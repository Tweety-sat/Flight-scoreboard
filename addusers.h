#ifndef ADDUSERS_H
#define ADDUSERS_H

#include <QDialog>
#include "users.h"

namespace Ui {
class AddUsers;
}
//Окно добавления нового пользователя
class AddUsers : public QDialog
{
    Q_OBJECT

public:
    explicit AddUsers(QWidget *parent = nullptr);
    ~AddUsers();
    //Возвращает объект добавляемого пользователя
    const User &getUser() const;

private:
    Ui::AddUsers *mUi;
    //Для хранения данных добавляемого пользователя
    User m_user;

public slots:
    void accept();
    bool isLoginExists(const QString &login);
};

#endif // ADDUSERS_H
