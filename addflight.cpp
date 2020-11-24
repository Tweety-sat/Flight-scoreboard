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
    if (type == Edit)
    {
        mUi->label_7->setText("Редактирование рейса"); // Изменяем заголовок


        mUi->Number->setText(m_flight->number());
        mUi->time_1->setTime(m_flight->scheduled_arrival_time());
        mUi->time_2->setTime(m_flight->expected_time());
        mUi->Otpr->setText(m_flight->departure());
        mUi->Nazn->setText(m_flight->destination());
        mUi->Status_box->setCurrentText(m_flight->status());
    }
    else
    {

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
    QString number = mUi->Number->text();
    QTime scheduled_arrival_time = mUi->time_1->time();
    QTime expected_time = mUi->time_2->time();
    QString departure = mUi->Otpr->text();
    QString destination = mUi->Nazn->text();
    QString edit = QDateTime::currentDateTime().toString("hh.mm");
    //Проверка введенных данных
    if (number.isEmpty() ||
        destination.isEmpty()||
        departure.isEmpty()  )
    {
        mUi->error->setText("Ошибка: заполните все поля!");
    }
    else
    {
        m_flight->setData(number, scheduled_arrival_time, expected_time, departure, destination);
        QDialog::accept();
    }
}
