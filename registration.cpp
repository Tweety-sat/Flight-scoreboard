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
    if (typeReg == Admin)  //Если регистрируется администратор,
    {
      mUi->label->setText("Регистрация администратора");
      mUi->auth->hide(); //то "прячем" кнопку авторизации
    }
    m_typeReg = typeReg;

    //соединяем кнопку авторизации с сигналом открытия окна авторизации данный сигнал передаст главному окну, что необходимо открыть окно авторизации
    connect(mUi->auth, SIGNAL(clicked()),
           this, SIGNAL(openAuthorization()));
}

SignUp::~SignUp()
{
    delete mUi;
}


//если вернет true, то логин существует и в последствии будет выведена ошибка
bool SignUp::isLoginExists(const QString &login)
{
    QFile file(Config::Usersbin);
    if (file.exists()) //если файл существует
    {
        if (!file.open(QIODevice::ReadOnly)) //если не удалось открыть файл
        {
            mUi->label_error->setText("Ошибка: чтение файла невозможно!");
            return false;
        }
        //создаем поток
        QDataStream ist(&file);
        //пока не конец файла
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
    //Запись введенных данных в переменные
    const QString login = mUi->log->text();
    const QString password = mUi->pass->text();
    const QString repeatPassword = mUi->reppass->text();

    //проверка на корректность
    if (login.isEmpty() || password.isEmpty() || repeatPassword.isEmpty()) //Если одно из полей пароля, логина или повтор пароля не заполнено, то пользователь будет оповещен
    {
        mUi->label_error->setText("Ошибка: заполните все поля!");
    }
    else if (isLoginExists(login)) //проверка на существование логина
    {
        if (mUi->label_error->text().isEmpty())
            mUi->label_error->setText("Ошибка: данное имя пользователя занято!");
    }
    else if (login.size() < 5 || login.size() > 15) //Проверяется соответствие длины логина
    {
        mUi->label_error->setText("Ошибка: имя пользователя должено содержать от 5 до 15 символов!");
    }
    else if (password.size() < 5 || password.size() > 15)//Проверяется соответствие длины пароля
    {
        mUi->label_error->setText("Ошибка: пароль должен содержать от 5 до 15 символов!");
    }
    else if (password != repeatPassword) //Если поля пароль и повтор пароля не совпадают, то авторизация не проходит и пользователю сообщается с помощью лейбла об ошибке
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
        // Открываем файл с флагом Append, который сообщает, что данные будут дописываться в файл
        file.open(QIODevice::Append);
        QDataStream ost(&file);
        //запись пользователя
        ost << user;

         // Посылаем сигнал об открытии окна авторизации
        emit openAuthorization();
    }
}

