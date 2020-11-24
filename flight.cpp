#include "flight.h"

Flight::Flight()
{
     m_number="";
     m_departure="";
     m_destination="";
}

Flight::Flight(QString number, const QTime scheduled_arrival_time, const QTime expected_time, const QString departure, const QString destination)
{
    setData(number, scheduled_arrival_time, expected_time, departure, destination);
}

void Flight::setData(QString number, const QTime scheduled_arrival_time, const QTime expected_time, const QString departure, const QString destination)
{
    m_number = number;
    m_scheduled_arrival_time=scheduled_arrival_time;
    m_expected_time=expected_time;
    m_departure=departure;
    m_destination=destination;
}

QString Flight::number() const
{
    return m_number;
}

void Flight::setNumber(const QString &number)
{
    m_number = number;
}


QTime Flight::scheduled_arrival_time() const
{
    return m_scheduled_arrival_time;
}

void Flight::setScheduled_arrival_time(const QTime &scheduled_arrival_time)
{
    m_scheduled_arrival_time = scheduled_arrival_time;
}

QTime Flight::expected_time() const
{
    return m_expected_time;
}

void Flight::setExpected_time(const QTime &expected_time)
{
    m_expected_time = expected_time;
}

QString Flight::departure() const
{
    return m_departure;
}

void Flight::setDeparture(const QString &departure)
{
    m_departure = departure;
}


QString Flight::destination() const
{
    return m_destination;
}

void Flight::setDDestination(const QString &destination)
{
    m_destination = destination;
}

