#include "authorization.h"
#include "ui_authorization.h"

#include "config.h"
#include "users.h"

#include <QFile>
#include <QDataStream>

SignIn::SignIn(QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::SignIn)
{
    mUi->setupUi(this);


    connect(mUi->registr, SIGNAL(clicked()),
            this, SIGNAL(openRegistration()));
}

SignIn::~SignIn()
{
    delete mUi;
}

User *SignIn::checkUser(const QString &login, const QString &password)
{
    QFile file(Config::Usersbin);
    if (file.exists())
    {
        User *user = nullptr;
        if (!file.open(QIODevice::ReadOnly))
        {
            mUi->labelError->setText("Ошибка: открытие файла невозможно!");
            return nullptr;
        }

        QDataStream ist(&file);

        while (!ist.atEnd())
        {

            User buf_user;
            ist >> buf_user;
            if (buf_user.login() == login && buf_user.password() == password)
            {

                user = new User(buf_user);
                return user;
            }
        }

        return user;
    }
    else
        return nullptr;
}

void SignIn::on_sign_clicked()
{
    mUi->labelError->clear();
    const QString login = mUi->Llog->text();
    const QString password = mUi->Lpass->text();

    //проверка на коректность введенных данных
    if (login.isEmpty() || password.isEmpty())
    {
        mUi->labelError->setText("Ошибка: заполните все поля!");
    }
    else if (login.size() < 5 || login.size() > 15)
    {
        mUi->labelError->setText("Ошибка: имя пользователя должено содержать от 5 до 15 символов!");
    }
    else if (password.size() < 5 || password.size() > 15)
    {
        mUi->labelError->setText("Ошибка: пароль должен содержать от 5 до 15 символов!");
    }
    else
        {
        User *user = checkUser(login, password); // Создаем указатель на объект User, который приравниваем возвращаемому типу метода

        if (!checkUser(login, password)) mUi->labelError->setText("Ошибка: 11!");
        if (user == nullptr) //данные введены неверно
        {
            mUi->labelError->setText("Ошибка: неправильный логин или пароль!");
        }
        else
        {
            emit succesfulEntry(user); // Посылаем сигнал об успешном входе
        }
    }
}








