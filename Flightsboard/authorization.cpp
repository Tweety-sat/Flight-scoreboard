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
    // Соединяем кнопку "Создать пользователя" с сигналом открытия окна регистрации.
    // Далее этот сигнал будет передавать главному окну, чтобы тот открыл окно регистрации.
    connect(mUi->registr, SIGNAL(clicked()), //Соединение кнопки создания пользователя и сигнала открытия окна регистрации
            this, SIGNAL(openRegistration())); //Сигнал передает mainwindow о необходимости открыть окно регистрации
}

SignIn::~SignIn()
{
    delete mUi;
}

//Проверка корректности введенных данных
User *SignIn::checkUser(const QString &login, const QString &password)
{
    QFile file(Config::Usersbin);
    if (file.exists()) //если файл существует, то
    {
        User *user = nullptr; //Создаем новый указатель, если пользователь  не будет найден, то указатель остантся нулевым

        //Успешность открытия файла. При неудаче выводится ошибка
        if (!file.open(QIODevice::ReadOnly))
        {
            mUi->labelError->setText("Ошибка: открытие файла невозможно!");
            return nullptr;
        }

        QDataStream ist(&file); // Создаем поток для упрощенного считывания данных из файла.

        while (!ist.atEnd())
        {
            //считывание данных пользователя
            User users_buf;
            ist >> users_buf;
            if (users_buf.login() == login && users_buf.password() == password) //Если считанные данные совпали с веденными, то
            {

                user = new User(users_buf);// Выделяем нулевому указателю память под объект User, присваиваем значение
                return user; //И вовзращаем его
            }
        }

        return user; // Если пользователь не был найден, возвращаем нулевой указатель.
    }
    else
        return nullptr;
}

void SignIn::on_sign_clicked()
{
    mUi->labelError->clear(); //Очищаем лейбл ошибок

    // Считываем введенные данные в переменные
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

        if (!checkUser(login, password)) mUi->labelError->setText("Ошибка: Проверка пользователя не пройдена!");
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








