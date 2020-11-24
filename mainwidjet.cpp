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
    setWindowTitle(Config::nameApplication);

    if (!QFile(Config::Usersbin).exists())
    {
        m_currentWidget = new SignUp(SignUp::Admin, this);
        connect(m_currentWidget, SIGNAL(openAuthorization()),
                this, SLOT(slotOpenAuthorization()));
    }
    else
    {
        m_currentWidget = new SignIn(this);
        connect(m_currentWidget, SIGNAL(openRegistration()),
                this, SLOT(slotOpenRegistration()));
        connect(m_currentWidget, SIGNAL(succesfulEntry(User*)),
                this, SLOT(slotOpenMainWindow(User*)));
    }

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setMargin(0);
    layout->addWidget(m_currentWidget);
    setLayout(layout);
}


MainWidget::~MainWidget()
{
    delete m_currentWidget;
}

void MainWidget::slotOpenAuthorization()
{
    delete m_currentWidget;
    m_currentWidget = new SignIn(this);
    connect(m_currentWidget, SIGNAL(openRegistration()),
            this, SLOT(slotOpenRegistration()));
    connect(m_currentWidget, SIGNAL(succesfulEntry(User*)),
            this, SLOT(slotOpenMainWindow(User*)));

    layout()->addWidget(m_currentWidget);
}

void MainWidget::slotOpenRegistration()
{
    delete m_currentWidget;
    m_currentWidget = new SignUp(SignUp::Passenger, this);
    connect(m_currentWidget, SIGNAL(openAuthorization()),
            this, SLOT(slotOpenAuthorization()));
    layout()->addWidget(m_currentWidget);
}

void MainWidget::slotOpenMainWindow(User *user)
{
    delete m_currentWidget;
    m_currentWidget = new MainWindow(*user, this);

    this->resize(900, 400);
    connect(m_currentWidget, SIGNAL(changeUser()),
            this, SLOT(slotOpenAuthorization()));
    layout()->addWidget(m_currentWidget);
}
