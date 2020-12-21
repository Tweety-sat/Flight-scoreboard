#include "mainwidjet.h"

#include "config.h"
#include "mainwindow.h"
#include <registration.h>
#include <authorization.h>
#include <QFile>
#include <QVBoxLayout>

#include <QDebug>
#include "users.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent),
      m_currentWidget(nullptr)
{
    setWindowTitle(Config::nameApplication); // Установка заголовка.

    if (!QFile(Config::Usersbin).exists())  //Если файла с пользователем не существует, то
    {
        m_currentWidget = new SignUp(SignUp::Admin, this); //Создаем окно регистрации администратора при запуске
        //Подключаем сигнал, посылаемый из класса регистрации, активирующий окно регистрации
        connect(m_currentWidget, SIGNAL(openAuthorization()),
                this, SLOT(Authorization()));
    }
    else //Если существует хотя бы один пользователь, то
    {
        m_currentWidget = new SignIn(this); //создаем окно авторизации

        //Соединяем сигнал, отправленный из класса авторизации, активирубщий окно регистрации
        connect(m_currentWidget, SIGNAL(openRegistration()),
                this, SLOT(Registration()));

        //Соединяем сигнал, отправленныйиз класса авторизации, при успешном входе в систему, со слотом открытия MainWindow
        connect(m_currentWidget, SIGNAL(succesfulEntry(User*)),
                this, SLOT(slotMainWindow(User*)));
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0); // Делаем нулевые границы
    layout->addWidget(m_currentWidget);
    setLayout(layout);
}


MainWidget::~MainWidget()
{
    delete m_currentWidget;
}

void MainWidget::Authorization()
{
    delete m_currentWidget; // Удаление текущего окна
    m_currentWidget = new SignIn(this); // Создание окна авторизации

    // Соединение необходимых сигналов со слотами
    connect(m_currentWidget, SIGNAL(openRegistration()),
            this, SLOT(Registration()));
    connect(m_currentWidget, SIGNAL(succesfulEntry(User*)),
            this, SLOT(slotMainWindow(User*)));

    layout()->addWidget(m_currentWidget);
}

void MainWidget::Registration()
{
    delete m_currentWidget; // Удаление текущего окна
    m_currentWidget = new SignUp(SignUp::Passenger, this); // Создание окна регистрации пассажира

    // Соединение необходимых сигналов со слотами
    connect(m_currentWidget, SIGNAL(openAuthorization()),
            this, SLOT(Authorization()));
    layout()->addWidget(m_currentWidget); //Добавление нового окна
}

void MainWidget::slotMainWindow(User *user)
{
    delete m_currentWidget; // Удаление текущего окна
    m_currentWidget = new MainWindow(*user, this); // Создание окна рабочего виджета

    this->resize(900, 400); //Изменяем размер

    // Соединение необходимых сигналов со слотами
    connect(m_currentWidget, SIGNAL(changeUser()),
            this, SLOT(Authorization()));
    layout()->addWidget(m_currentWidget);
}
