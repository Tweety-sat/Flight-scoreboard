#include "addusers.h"
#include "ui_addusers.h"
#include "config.h"
#include "users.h"

#include <QFile>
#include <QDataStream>


AddUsers::AddUsers(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::AddUsers)
{
    mUi->setupUi(this);
}

AddUsers::~AddUsers()
{
    delete mUi;
}

const User &AddUsers::getUser() const
{
    return m_user;
}

//Проверка на существование логина
bool AddUsers::isLoginExists(const QString &login)
{
    //Загружаем данные о пользователях
    QFile file(Config::Usersbin);
    if (file.exists())
    {
        if (!file.open(QIODevice::ReadOnly))
        {
            mUi->Error->setText("Ошибка: чтение файла невозможно!");
            return false;
        }

        QDataStream ist(&file);
        while (!ist.atEnd())
        {
            User buf_user;
            ist >> buf_user;   //Читаем данные о пользователе
            if (buf_user.login() == login) //Если логин совпадает возвращаем true, при котором пользователю выведется ошибка о существующем логине
                return true;
        }
        return false;
    }
    else
        return false;
}


void AddUsers::accept()
{
    // Получаем введенные данные
    const QString login = mUi->L_login->text();
    const QString password = mUi->L_password->text();

    // Преобразуем статус из QString в необходимый тип (Status)
    User::Status status = User::getListStatus().key(mUi->L_status->currentText());

    //Проверка на корректность логина и пароля
    if (login.isEmpty() || password.isEmpty())
    {
        mUi->Error->setText("Ошибка: необходимо заполнить все поля!");
    }
    else if (isLoginExists(login))
    {
        if (mUi->Error->text().isEmpty())
            mUi->Error->setText("Ошибка: данное имя пользователя уже существует!");
    }
    else if (login.size() < 5 || login.size() > 15)
    {
        mUi->Error->setText("Ошибка: имя пользователя должено содержать от 5 до 15 символов!");
    }
    else if (password.size() < 6 || password.size() > 15)
    {
        mUi->Error->setText("Ошибка: пароль должен содержать от 6 до 15 символов!");
    }
    else
    {
        //При успешной проверка загружаем данные
        m_user.setData(login, password, status);
        QDialog::accept();
    }
}
