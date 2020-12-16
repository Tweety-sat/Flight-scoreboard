#ifndef FLIGHT_H
#define FLIGHT_H

#include <QString>
#include <QDate>
#include <QTime>
#include "users.h"
#include <QDataStream>
#include <QTextStream>

/*!
    \brief Класс рейса.
    Данный класс существует для получения и записи данных о рейсе.
*/
class Flight
{
public:
    Flight();

    /*!
    Конструктор класса
    \param number номер рейса
    \param scheduled_arrival_time ожидаемое время прибытия рейса
    \param expected_time время прибытия рейса по расписанию
    \param departure пункт отправления рейса
    \param destination пункт назначения рейса
    \param status статус рейса
    \param edit последнее время редактирования информации о рейсе
    */
    Flight(QString number, const QTime scheduled_arrival_time, const QTime expected_time ,
           const QString departure, const QString destination, const QString status, const QString edit);
    /*!
    Метод установки данных:
    number: номер рейса
    scheduled_arrival_time: ожидаемое время прибытия рейса
    expected_time: время прибытия рейса по расписанию
    departure пункт: отправления рейса
    destination пункт: назначения рейса
    status статус рейса
    edit последнее время редактирования информации о рейсе
    */
    void setData(QString number, const QTime scheduled_arrival_time, const QTime expected_time,
                 const QString departure, const QString destination, const QString status, const QString edit);


    ///Метод получения номера рейса
    QString number() const;
    ///Метод получения ожидаемого времени прибытия
    QTime scheduled_arrival_time() const;
    ///Метод получения времени прибытия по расписанию
    QTime expected_time() const;
    ///Метод получения пункта отправления
    QString departure() const;
    ///Метод получения пункта назначения
    QString destination() const;
    ///Метод получения статуса рейса
    QString status() const;
    ///Метод получения последнего ремени редактирования информации о рейсе
    QString edit() const;

    ///Метод установки значения в поле номера рейса
    void setNumber(const QString &number);
    ///Метод установки значения в поле ожидаемого времени прибытия
    void setScheduled_arrival_time(const QTime &scheduled_arrival_time);
    ///Метод установки значения в поле времени прибытия рейса по расписанию
    void setExpected_time(const QTime &expected_time);
    ///Метод установки значения в поле пункта отправления
    void setDeparture(const QString &departure);
    ///Метод установки значения в поле пункта назначения
    void setDDestination(const QString &destination);
    ///Метод установки значения в поле статуса рейса
    void setSStatus(const QString &status);
    ///Метод установки значения в поле edit - последнее время редактирования информации о рейсе
    void setedit(const QString &status);


private:
    QString m_number;
    QTime m_scheduled_arrival_time;
    QTime m_expected_time;
    QString m_departure;
    QString m_destination;
    QString m_status;
    QString m_edit;
};

/// Запись в файл
inline QDataStream &operator<< (QDataStream &ost, const Flight &flight)
{
    ost << flight.number() << flight.scheduled_arrival_time() << flight.expected_time() << flight.departure() << flight.destination() << flight.status()<<flight.edit();
    return ost;
}

/// Чтение из файла
inline QDataStream &operator>> (QDataStream &ist, Flight &flight)
{
    QString number;
    QTime scheduled_arrival_time;
    QTime expected_time;
    QString departure;
    QString destination;
    QString status;
    QString edit;

    ist >> number >> scheduled_arrival_time >> expected_time >> departure >> destination >> status>>edit;
    flight.setData(number, scheduled_arrival_time, expected_time, departure, destination, status,edit);
    return ist;
}

inline QTextStream &operator<< (QTextStream &ost, const Flight &flight)
{
    ost << QString("______Начало Рейса______")
        << QString("Номер рейса: ") << flight.number()
        << QString("Пункт Отправления: ") << flight.departure()
        << QString("Пункт назначения: ") << flight.destination()
        << QString("Ожидаемое время прилета: ") << flight.expected_time().toString("hh:mm")
        << QString("Время прилета по расписанию: ") << flight.scheduled_arrival_time().toString("hh:mm")
        << QString("\nСтатус рейса: ") << flight.status()
        << QString("\nВремя ищменения рейса: ") << flight.edit()
        << QString("______Конец Рейса______");
    return ost;
}


#endif // FLIGHT_H
