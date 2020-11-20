#ifndef FLIGHT_H
#define FLIGHT_H

#include <QString>
#include <QDate>
#include <QTime>
#include "users.h"
#include <QDataStream>
#include <QTextStream>

class Flight
{
public:
    Flight();
    /*- номер рейса;
    - время прилета по расписанию;
    - ожидаемое время прилета;
    - пункт вылета;
    - пункт назначения;
    - статус рейса (отложен, вылетел, прилетел).*/

    Flight(QString number, const QTime scheduled_arrival_time, const QTime expected_time , const QString departure, const QString destination, const QString status);
    void setData(QString number, const QTime scheduled_arrival_time, const QTime expected_time, const QString departure, const QString destination, const QString status);

    QString number() const;
    void setNumber(const QString &number);

    QTime scheduled_arrival_time() const;
    void setScheduled_arrival_time(const QTime &scheduled_arrival_time);

    QTime expected_time() const;
    void setExpected_time(const QTime &expected_time);

    QString departure() const;
    void setDeparture(const QString &departure);

    QString destination() const;
    void setDDestination(const QString &destination);

    QString status() const;
    void setSStatus(const QString &status);


private:
    QString m_number;
    QTime m_scheduled_arrival_time;
    QTime m_expected_time;
    QString m_departure;
    QString m_destination;
    QString m_status;
};

// Запись в файл
inline QDataStream &operator<< (QDataStream &ost, const Flight &flight)
{
    ost << flight.number() << flight.scheduled_arrival_time() << flight.expected_time() << flight.departure() << flight.destination() << flight.status();
    return ost;
}

// Чтение из файла
inline QDataStream &operator>> (QDataStream &ist, Flight &flight)
{
    QString number;
    QTime scheduled_arrival_time;
    QTime expected_time;
    QString departure;
    QString destination;
    QString status;

    ist >> number >> scheduled_arrival_time >> expected_time >> departure >> destination >> status;
    flight.setData(number, scheduled_arrival_time, expected_time, departure, destination, status);
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
        << QString("______Конец Рейса______");
    return ost;
}


#endif // FLIGHT_H
