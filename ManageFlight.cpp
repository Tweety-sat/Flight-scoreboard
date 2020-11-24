#include "ManageFlight.h"
#include "ui_ManageFlight.h"

#include "config.h"
#include <addflight.h>
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include <mainwindow.h>
#include <QTimeEdit>
#include <QTime>
ManageFlight::ManageFlight(const QList<Flight> &listFlight, QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::ManageFlight),
    m_listFlight(listFlight)
{
    mUi->setupUi(this);
    mUi->TableFlight->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeMode::ResizeToContents); // Устанавливка ширины столбцов под размер содержимого

    // Заполнение таблицы данными
    int row = 0;
    foreach (const Flight &flight, m_listFlight)
    {
        // Создание элементов таблицы с нужным содержимым
        QTableWidgetItem *item_number = new QTableWidgetItem(flight.number());
        QTableWidgetItem *item_departure = new QTableWidgetItem(flight.departure());
        QTableWidgetItem *item_destination= new QTableWidgetItem(flight.destination());
        QTableWidgetItem *item_expected_time = new QTableWidgetItem(flight.expected_time().toString("hh:mm"));
        QTableWidgetItem *item_scheduled_arrival_time = new QTableWidgetItem(flight.scheduled_arrival_time().toString("hh:mm"));


        mUi->TableFlight->insertRow(row); //вставка строки
        //установка элементов таблицы в саму таблицу по строкам
        mUi->TableFlight->setItem(row, 0, item_number);
        mUi->TableFlight->setItem(row, 1, item_departure );
        mUi->TableFlight->setItem(row, 2, item_destination );
        mUi->TableFlight->setItem(row, 3,  item_scheduled_arrival_time);
        mUi->TableFlight->setItem(row, 4, item_expected_time );
        row++;
    }
}

ManageFlight::~ManageFlight()
{
    delete mUi;
}

//строка поиска
void ManageFlight::on_lineFind_textChanged(const QString &text)
{
    QStringList listStr = text.split(" ");
    listStr.removeAll(QString());
    for (int i = 0; i < m_listFlight.size(); i++)
    {
        mUi->TableFlight->showRow(i);
    }
    int row = 0;
    foreach (const Flight &flight, m_listFlight)
    {
        int count = 0;
        foreach (const QString &str, listStr)
        {
            if (flight.number().contains(str) ||
                flight.departure().contains(str) ||
                flight.destination().contains(str))
            {
                count++;
            }
        }
        if (count != listStr.size())
        {
            mUi->TableFlight->hideRow(row);
        }
        row++;
    }
}

void ManageFlight::on_add_clicked()
{
    Flight flight; // Создаем объект рейса

    //создаем окно, в котором будут изменяться данные созданного объекта и передаем лист рейсов для сравнения и значения того, что будет происходить создание рейса
    AddFlight dialog(&flight, m_listFlight, AddFlight::Create, this);
    dialog.setWindowTitle(windowTitle());

    //Вызов окна и проверка тогго, как оно было закрыто, если через "accepted"
    if (dialog.exec() == QDialog::Accepted)
    {
        //
        emit addFlight(flight); //подается сигнал, который подключен к MainWindow  на то, что был создан новый рейс

        //обновление таблицы в текущем окне
        //создание элементов таблицы с нужным содержимым
        QTableWidgetItem *item_number = new QTableWidgetItem(flight.number());
        QTableWidgetItem *item_departure = new QTableWidgetItem(flight.departure());
        QTableWidgetItem *item_destination= new QTableWidgetItem(flight.destination());
        QTableWidgetItem *item_scheduled_arrival_time = new QTableWidgetItem(flight.scheduled_arrival_time().toString("hh:mm"));
        QTableWidgetItem *item_expected_time = new QTableWidgetItem(flight.expected_time().toString("hh:mm"));
        int row = mUi->TableFlight->rowCount();
        mUi->TableFlight->insertRow(row); //вставка строки в таблицу
        //Установка элементов таблицы в саму таблицу
        mUi->TableFlight->setItem(row, 0, item_number);
        mUi->TableFlight->setItem(row, 1, item_departure );
        mUi->TableFlight->setItem(row, 2, item_destination );
        mUi->TableFlight->setItem(row, 3, item_scheduled_arrival_time);
        mUi->TableFlight->setItem(row, 4, item_expected_time  );
    }
}

void ManageFlight::on_del_clicked()
{
    int currentRow = mUi->TableFlight->currentRow();
    if (currentRow != -1)
    {

        emit deleteFlight(currentRow);


        mUi->TableFlight->removeRow(currentRow);
    }
    else
    {
        QMessageBox::warning(this, windowTitle(), "Ошибка: не выбран ни один рейс!");
    }
}

void ManageFlight::on_edit_clicked()
{
    int currentRow = mUi->TableFlight->currentRow(); // Определяем какая строка была выбрана для редактирования
    if (currentRow != -1) //если строка не будет выбрана, то будет currentRow=-1. Т.е. в данной строке проверяем выбрана ли строка
    {

        Flight flight = m_listFlight[currentRow];
        AddFlight dialog(&flight, m_listFlight, AddFlight::Edit, this);
        dialog.setWindowTitle(windowTitle());

        // Если окно было закрыто нажатием на кнопку "принять"
        if (dialog.exec() == QDialog::Accepted)
        {
            emit editFlight(currentRow, flight); //Посылается сигнал в главный класс, в котором будет выполнена перезапись в файл и обновлена таблица. Передаем изменяемую строку и новые данные рейса
            //изменение данных таблицы для текущего окна
            mUi->TableFlight->item(currentRow, 0)->setText(flight.number());
            mUi->TableFlight->item(currentRow, 1)->setText(flight.departure());
            mUi->TableFlight->item(currentRow, 2)->setText(flight.destination());
            mUi->TableFlight->item(currentRow, 3)->setText(flight.scheduled_arrival_time().toString("hh:mm") );
            mUi->TableFlight->item(currentRow, 4)->setText(flight.expected_time().toString("hh:mm"));

        }
    }
    else {
        QMessageBox::warning(this, windowTitle(), "Ошибка: не выбран ни один рейс!"); //Если пользователь не выбрал рейс, то он будет оповещен с помощью отдельного окна
    }
}
