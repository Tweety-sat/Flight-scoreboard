#include "registration.h"
#include "ui_registration.h"

#include "config.h"
#include "users.h"

#include <QFile>
#include <QDataStream>

SignUp::SignUp(TypeRegistration typeReg, QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::SignUp)
{
    mUi->setupUi(this);
    if (typeReg == Admin)
    {
      mUi->label->setText("Регистрация администратора");
      mUi->auth->hide();
    }
    m_typeReg = typeReg;


    connect(mUi->auth, SIGNAL(clicked()),
           this, SIGNAL(openAuthorization()));
}

SignUp::~SignUp()
{
    delete mUi;
}


bool SignUp::isLoginExists(const QString &login)
{
    QFile file(Config::Usersbin);
    if (file.exists())
    {
        if (!file.open(QIODevice::ReadOnly))
        {
            mUi->label_error->setText("Ошибка: чтение файла невозможно!");
            return false;
        }

        QDataStream ist(&file);

        while (!ist.atEnd())
        {
            //считывание данных
            User buf_user;
            ist >> buf_user;
            if (buf_user.login() == login)
                return true;
        }

        return false;
    }
    else
        return false;
}




void SignUp::on_accept_clicked()
{
    mUi->label_error->clear(); //очистка лейбла ошибок
    const QString login = mUi->log->text();
    const QString password = mUi->pass->text();
    const QString repeatPassword = mUi->reppass->text();


    if (login.isEmpty() || password.isEmpty() || repeatPassword.isEmpty())
    {
        mUi->label_error->setText("Ошибка: заполните все поля!");
    }
    else if (isLoginExists(login))
    {
        if (mUi->label_error->text().isEmpty())
            mUi->label_error->setText("Ошибка: данное имя пользователя занято!");
    }
    else if (login.size() < 5 || login.size() > 15)
    {
        mUi->label_error->setText("Ошибка: имя пользователя должено содержать от 5 до 15 символов!");
    }
    else if (password.size() < 5 || password.size() > 15)
    {
        mUi->label_error->setText("Ошибка: пароль должен содержать от 5 до 15 символов!");
    }
    else if (password != repeatPassword)
    {
        mUi->label_error->setText("Ошибка: пароли не совпадают!");
    }
    else
    {
        // Создание объекта пользователя
        User user(login,
                  password,
                  m_typeReg == Admin ? User::Admin : User::Passenger);

        QFile file(Config::Usersbin);
        file.open(QIODevice::Append);
        QDataStream ost(&file);
        ost << user;

        emit openAuthorization(); // Посылаем сигнал об открытии окна авторизации
    }
}

