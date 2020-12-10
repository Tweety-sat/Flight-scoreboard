#include <QtTest>
#include <flight.h>
// add necessary includes here

class TestFlights : public QObject
{
    Q_OBJECT

public:
    TestFlights();
    ~TestFlights();

private slots:
    void get_set_data();
    void test_to_string_from();
    void copy_action();
    void test_of_returned();
    void Checking_for_equalization();
};

TestFlights::TestFlights()
{

}

TestFlights::~TestFlights()
{

}

void TestFlights::get_set_data()
{
    const QString test_string = "test";
    const QTime test_time(10,32);

    Flight object;

    object.setNumber(test_string);
    QCOMPARE(object.number(), test_string);

    object.setScheduled_arrival_time(test_time);
    QCOMPARE(object.scheduled_arrival_time(), test_time);

    object.setExpected_time(test_time);
    QCOMPARE(object.expected_time(), test_time);

    object.setDeparture(test_string);
    QCOMPARE(object.departure(), test_string);

    object.setDDestination(test_string);
    QCOMPARE(object.destination(), test_string);

    object.setSStatus(test_string);
    QCOMPARE(object.status(), test_string);

    object.setedit(test_string);
    QCOMPARE(object.edit(), test_string);
}
void TestFlights::Checking_for_equalization()
{
    const QString test_string = "test";
    const QTime test_time(10,32);

    Flight object;

    object.setNumber(test_string);
    object.setScheduled_arrival_time(test_time);
    object.setExpected_time(test_time);
    object.setDeparture(test_string);
    object.setDDestination(test_string);
    object.setSStatus(test_string);
    object.setedit(test_string);

    Flight object2;
    object2 = object;

    QCOMPARE(object.number(), object2.number());
    QCOMPARE(object.scheduled_arrival_time(), object2.scheduled_arrival_time());
    QCOMPARE(object.expected_time(), object2.expected_time());
    QCOMPARE(object.departure(), object2.departure());
    QCOMPARE(object.destination(), object2.destination());
    QCOMPARE(object.status(), object2.status());
    QCOMPARE(object.edit(), object2.edit());
}
void TestFlights::copy_action()
{
    const QString test_string = "test";
    const QTime test_time(10,32);

    Flight object;

    object.setNumber(test_string);
    object.setScheduled_arrival_time(test_time);
    object.setExpected_time(test_time);
    object.setDeparture(test_string);
    object.setDDestination(test_string);
    object.setSStatus(test_string);
    object.setedit(test_string);

    Flight object2(object);

    QCOMPARE(object.number(), object2.number());
    QCOMPARE(object.scheduled_arrival_time(), object2.scheduled_arrival_time());
    QCOMPARE(object.expected_time(), object2.expected_time());
    QCOMPARE(object.departure(), object2.departure());
    QCOMPARE(object.destination(), object2.destination());
    QCOMPARE(object.status(), object2.status());
    QCOMPARE(object.edit(), object2.edit());
}

void TestFlights::test_to_string_from()
{

    const QTime test_time(10,32);
    const QString test_string="10:32";
    const QString test=" asd ";
    Flight object;

    object.setScheduled_arrival_time(test_time);
    QCOMPARE(object.scheduled_arrival_time().toString("hh:mm"), test_string);
    object.setExpected_time(test_time);
    QCOMPARE(object.expected_time().toString("hh:mm"), test_string);

    object.setData(test,test_time, test_time, test,   test,   test,  test);
    QCOMPARE(object.expected_time().toString("hh:mm"), test_string);
    QCOMPARE(object.expected_time().toString("hh:mm"), test_string);
}

void TestFlights::test_of_returned()
{
    const QString test_string = "test";
    const QString test_string2 = "test1";
    const QString test_string3 = "test2";
    const QString test_string4 = "test3";
    const QString test_string5 = "test4";

    const QTime test_time(10,32);
    const QTime test_time2(10,33);

    Flight obj(test_string, test_time, test_time2, test_string2, test_string3, test_string4, test_string5);
    Flight obj2(test_string, test_time, test_time2,  test_string2, test_string3, test_string4, test_string5);
    Flight obj3(test_string, test_time, test_time2,  test_string2, test_string3, test_string4, test_string5);

    QCOMPARE(obj.number(), test_string);
    QCOMPARE(obj.scheduled_arrival_time(), test_time);
    QCOMPARE(obj.expected_time(), test_time2);
    QCOMPARE(obj.departure(), test_string2);
    QCOMPARE(obj.destination(), test_string3);
    QCOMPARE(obj.status(), test_string4);
    QCOMPARE(obj.edit(), test_string5);

    QCOMPARE(obj2.number(), test_string);
    QCOMPARE(obj2.scheduled_arrival_time(), test_time);
    QCOMPARE(obj2.expected_time(), test_time2);
    QCOMPARE(obj2.departure(), test_string2);
    QCOMPARE(obj2.destination(), test_string3);
    QCOMPARE(obj2.status(), test_string4);
    QCOMPARE(obj2.edit(), test_string5);

    QCOMPARE(obj3.number(), test_string);
    QCOMPARE(obj3.scheduled_arrival_time(), test_time);
    QCOMPARE(obj3.expected_time(), test_time2);
    QCOMPARE(obj3.departure(), test_string2);
    QCOMPARE(obj3.destination(), test_string3);
    QCOMPARE(obj3.status(), test_string4);
    QCOMPARE(obj3.edit(), test_string5);
}

QTEST_APPLESS_MAIN(TestFlights)

#include "tst_testflights.moc"
