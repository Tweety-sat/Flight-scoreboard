#include "addflight.h"
#include "ui_addflight.h"

#include "config.h"
#include "flight.h"
#include <QComboBox>

AddFlight::AddFlight(Flight *flight, const QList<Flight> &listFlight, Type type, QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::AddFlight),
    m_flight(flight),
    m_listflight(listFlight)
{
    mUi->setupUi(this);
    m_startNumberFlight = flight->number();

    // Проверка типа использования окна
    if (type == Edit)
    {
        mUi->label_7->setText("Редактирование рейса"); // Изменяем заголовок

        //Устанавливка нужных занчений в виджеты
        mUi->Number->setText(m_flight->number());
        mUi->time_1->setTime(m_flight->scheduled_arrival_time());
        mUi->time_2->setTime(m_flight->expected_time());
        mUi->Otpr->setText(m_flight->departure());
        mUi->Nazn->setText(m_flight->destination());
        mUi->Status_box->setCurrentText(m_flight->status());
    }
    else
    {
        // Иначе, при добавлении, меняем заголовок и оставляем виджеты пустыми
        mUi->label_7->setText("Добавление рейса");
    }
}


AddFlight::~AddFlight()
{
    delete mUi;
}

void AddFlight::accept()
{
    mUi->error->clear(); //Очищаем строку с ошибками

    //Определяем индекс выбранного статуса рейса и с помощью switch определяем значение в строку
    int row = mUi->Status_box->currentIndex();
    QString status2;
            switch(row)
            {
            case 1:
                status2="Отложен";
                break;
            case 2:
                 status2="Вылетел";
                break;
            case 3:
                status2="Прибыл";
                break;
            }
    // Перенос значений из виджетов в переменные
    QString number = mUi->Number->text();
    QTime scheduled_arrival_time = mUi->time_1->time();
    QTime expected_time = mUi->time_2->time();
    QString departure = mUi->Otpr->text();
    QString destination = mUi->Nazn->text();
    QString status = status2;
    QString edit = QDateTime::currentDateTime().toString("hh.mm");
    //Проверка введенных данных
    if (number.isEmpty() ||
        destination.isEmpty()||
        departure.isEmpty() ||
        status2.isEmpty())
    {
        mUi->error->setText("Ошибка: заполните все поля!");
    }
    //При успешной проверке, устанавливаем данные в наш указатель
    else
    {
        m_flight->setData(number, scheduled_arrival_time, expected_time, departure, destination, status, edit);
        QDialog::accept(); //Сообщаем окну, что оно может успешно закрыться
    }
}
