#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "config.h"
#include <QFile>
#include <QDataStream>
#include <QDebug>
#include <LK.h>
#include <ManageFlight.h>
#include <flight.h>
#include <ManageUsers.h>
#include <QDateTime>
#include <QMessageBox>
MainWindow::MainWindow(User &user, QWidget *parent) :
    QWidget(parent),
    mUi(new Ui::MainWindow),
    m_user(user)
{
    mUi->setupUi(this);
   // mUi->Board_flight->setStyleSheet("background-color: #FDF5E6");
    mUi->Board_flight->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents); //Установка ширины столбца под размер содержимого

    //Выделение памяти под окно с информацией о пользователе
    m_infoDialog = new InfoUser(m_user, this);
    m_infoDialog->setWindowTitle(Config::nameApplication);

    //Если пользователь имеет статус диспетчера, то прячем кнопку управления пользователями
    if (m_user.status() == User::Dispatcher)
        mUi->controlusers->hide();

    //Если пользователь имеет статус пассажира, то прячем кнопки управления пользователями и рейсами
    if (m_user.status() == User::Passenger)
    {
        mUi->controlflight->hide();
        mUi->controlusers->hide();
    }

    loadFlights(); // Загрузка списка рейсов из файла
    //Сортировка для главного окна
    mUi->Board_flight->sortByColumn(3,Qt::AscendingOrder);
}

MainWindow::~MainWindow()
{
    delete mUi;
    delete m_infoDialog;
    delete &m_user;
}

void MainWindow::on_controlflight_clicked()
{    
    //Получаем список рейсов из текущего окна
    const QList<Flight> &listFlight = qobject_cast<MainWindow*>(this)->listFlight();
    ManageFlight dialog(listFlight, this); // Создаем окно передавая в него список.
    dialog.setWindowTitle(windowTitle());
    // Подключаем сигналы, такие как:
        connect(&dialog, SIGNAL(addFlight(Flight)),
                this, SLOT(addFlight(Flight))); //Добавление

        connect(&dialog, SIGNAL(editFlight(int, Flight)),
                this, SLOT(editFlight(int, Flight))); //Редактирование

        connect(&dialog, SIGNAL(deleteFlight(int)),
                this, SLOT(deleteFlight(int))); //И удаление рейса

    dialog.exec(); //вызываем окно
}

void MainWindow::on_controlusers_clicked()
{
    ManageUsers dialog(this);
    dialog.setWindowTitle(windowTitle());
    dialog.show();
    dialog.exec();
}

void MainWindow::on_infoUser_clicked()
{
    // Если была нажата кнопка "Выйти из аккаунта" то окно вернет значение QDialog::Accepted
    // Иначе же QDialog::Rejected
    if (m_infoDialog->exec() == QDialog::Accepted)
         emit changeUser();  // Посылаем сигнал об необходимости сменить пользователя
}

void MainWindow::addFlight(Flight flight)
{
    m_listFlight.append(flight); //Добавление в лист

    // Сохранение в файл
    QFile file(Config::Flightbin);
    file.open(QIODevice::Append);
    QDataStream ost(&file);
    ost << flight;
    flight.edit()=QDateTime::currentDateTime().toString("hh.mm");
    // Добавление в таблицу
    QTableWidgetItem *item_number = new QTableWidgetItem(flight.number());
    QTableWidgetItem *item_scheduled_arrival_time = new QTableWidgetItem(flight.scheduled_arrival_time().toString("hh:mm"));
    QTableWidgetItem *item_expected_time = new QTableWidgetItem(flight.expected_time().toString("hh:mm"));
    QTableWidgetItem *item_departure = new QTableWidgetItem(flight.departure());
    QTableWidgetItem *item_destination= new QTableWidgetItem(flight.destination());
    QTableWidgetItem *item_status= new QTableWidgetItem(flight.status());
    QTableWidgetItem *item_st= new QTableWidgetItem(flight.edit());
    int row = mUi->Board_flight->rowCount();
    mUi->Board_flight->insertRow(row); //Вставление строки в таблицу
    //Установка элементов таблицы в саму таблицу
    mUi->Board_flight->setItem(row, 0, item_number);
    mUi->Board_flight->setItem(row, 1, item_departure);
    mUi->Board_flight->setItem(row, 2, item_destination);
    mUi->Board_flight->setItem(row, 3, item_scheduled_arrival_time );
    mUi->Board_flight->setItem(row, 4, item_expected_time );
    mUi->Board_flight->setItem(row, 5, item_status);
    mUi->Board_flight->setItem(row, 6, item_st);

}

void MainWindow::editFlight(int row, Flight flight)
{
    m_listFlight[row] = flight;//изменение данных в листе

    //Перезапись_Данных
    QFile read_file(Config::Flightbin); //основной файл
    if (read_file.open(QIODevice::ReadOnly)) //его открытие для чтения
    {
        QFile write_file("flight_file"); //Файл-буфер
        write_file.open(QIODevice::WriteOnly); //Файл-буфер открываем для записи

        //создание потоков для чтения  и записи
        QDataStream read_ist(&read_file);
        QDataStream write_ist(&write_file);

        int countSeats = 0;
        //Считывание и запись
        while (!read_ist.atEnd())
        {
            Flight bFlight;
            read_ist >> bFlight;

            if (countSeats++ == row)
            {
                bFlight = flight;
            }

            write_ist << bFlight;
        }
        // Закрытие основного файла и его удаление
        read_file.close();
        read_file.remove();
        //Закрытие буфер-файла и его переименовывание
        write_file.close();
        write_file.rename(Config::Flightbin);
    }
    //Посылаем данные в таблицу
    flight.edit()=QDateTime::currentDateTime().toString("hh.mm");
    mUi->Board_flight->item(row, 0)->setText(flight.number());
    mUi->Board_flight->item(row, 1)->setText(flight.departure());
    mUi->Board_flight->item(row, 2)->setText(flight.destination());
    mUi->Board_flight->item(row, 3)->setText(flight.scheduled_arrival_time().toString("hh:mm"));
    mUi->Board_flight->item(row, 4)->setText(flight.expected_time().toString("hh:mm") );
    mUi->Board_flight->item(row, 5)->setText(flight.status());
    mUi->Board_flight->item(row, 6)->setText(flight.edit());
}

void MainWindow::deleteFlight(int row)
{
    m_listFlight.removeAt(row);// Удаляем рейс из листа

    //Перезапись данных
    QFile read_file(Config::Flightbin); //Основной файл
    if (read_file.open(QIODevice::ReadOnly)) //открываем его для чтения
    {
        QFile write_file("flight_file"); //файл-буфер
        write_file.open(QIODevice::WriteOnly); //открытие его для записи

        //создание потоков
        QDataStream read_ist(&read_file);
        QDataStream write_ist(&write_file);

        int countReads = 0;
        //Начало считывания
        while (!read_ist.atEnd())
        {
            Flight bFlight;
            read_ist >> bFlight;
            if (countReads++ != row)
            {
                write_ist << bFlight;
            }
        }
        //закрытие основного файла и его удаление
        read_file.close();
        read_file.remove();
        //Закрытие буфер-файла и его переименование
        write_file.close();
        write_file.rename(Config::Flightbin);
    }
    mUi->Board_flight->removeRow(row); //Удаление соответствующей строки из таблицы
}

const QList<Flight> &MainWindow::listFlight() const
{
    return m_listFlight;
}

// Загрузка рейсов
void MainWindow::loadFlights()
{
    m_listFlight.clear(); //очистка листа

    //считывание с файла
    QFile file(Config::Flightbin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        while (!ist.atEnd()) {
            Flight flight;
            ist >> flight;
            m_listFlight.append(flight);
        }
    }

    int row = 0;
    foreach (const Flight &flight, m_listFlight) {
    // Создаем элементы таблицы с нужным текстом
        QTableWidgetItem *item_number = new QTableWidgetItem(flight.number());
        QTableWidgetItem *item_departure  = new QTableWidgetItem(flight.departure());
        QTableWidgetItem *item_destination  = new QTableWidgetItem(flight.destination());
        QTableWidgetItem * item_expected_time= new QTableWidgetItem(flight.expected_time ().toString("hh:mm"));
        QTableWidgetItem *item_scheduled_arrival_time= new QTableWidgetItem(flight.scheduled_arrival_time().toString("hh:mm"));
        QTableWidgetItem *item_status= new QTableWidgetItem(flight.status());
        QTableWidgetItem *item_st= new QTableWidgetItem(flight.edit());
        mUi->Board_flight->insertRow(row);// Вставка строки в таблицу
        // Устанавка элементов таблицы в саму таблицу
        mUi->Board_flight->setItem(row, 0, item_number);
        mUi->Board_flight->setItem(row, 1, item_departure );
        mUi->Board_flight->setItem(row, 2, item_destination );
        mUi->Board_flight->setItem(row, 3, item_scheduled_arrival_time);
        mUi->Board_flight->setItem(row, 4, item_expected_time );
        mUi->Board_flight->setItem(row, 5, item_status);
        mUi->Board_flight->setItem(row, 6, item_st);
        row++;
    }
}

//Строка поиска по номеру, пункту отправления, пункту назначения и статусу
void MainWindow::on_lineFind_textChanged(const QString &text)
{
    QStringList listStr = text.split(" ");
    listStr.removeAll(QString());

    for (int i = 0; i < m_listFlight.size(); i++) {
        mUi->Board_flight->showRow(i);
    }

    int row = 0;
    foreach (const Flight &flight, m_listFlight) {
        int count = 0;
        foreach (const QString &str, listStr) {
            if (flight.number().contains(str) ||
                flight.departure().contains(str) ||
                flight.destination().contains(str) ||
                flight.status().contains(str)) {
                count++;
            }
        }
        if (count != listStr.size()) {
            mUi->Board_flight->hideRow(row);
        }
        row++;
    }
}

//Кнопка "Помощь" с информацией о приложении
void MainWindow::on_pushButton_clicked()
{
    QMessageBox aboutDlg(this);
     aboutDlg.setWindowTitle(Config::nameApplication);
     aboutDlg.setIcon(QMessageBox::Information);
     aboutDlg.setText(tr("<br> Автор: Билевич Анастасия Вячеславовна"
                         "<br> Группа: КИ19-09Б"
                         "<br> Добро пожаловать!"
                         "<br> Табло авиарейсов – это приложение, которое несет информационный характер о рейсах и подобна онлайн-табло в реальных аэропортах. "
                         "<br> Данная система позволяет получать актуальную информацию о рейсах всем пользователям и позволяет вносить изменения как в список пользователей, "
                         "так и в список рейсов для отдельных групп пользователей. "
                         "<br>Чтобы изменить статус или личные данные, обратитесь к администратору."));
      aboutDlg.exec();
}
