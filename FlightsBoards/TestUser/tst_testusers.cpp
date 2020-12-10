#include <QtTest>
#include <users.h>

// add necessary includes here

class TestUsers : public QObject
{
    Q_OBJECT

public:
    TestUsers();
    ~TestUsers();

private slots:
        void get_set_data();
        void Checking_for_equalization();
        void action_with_strings();
        void copy_action();
        void test_returned();
};

TestUsers::TestUsers()
{

}

TestUsers::~TestUsers()
{

}

void TestUsers::get_set_data()
{
    User object;

    object.setLogin("Test");
    QCOMPARE(object.login(), "Test");

    object.setPassword("Test2");
    QCOMPARE(object.login(), "Test2");

    object.setStatus(User::Admin);
    QCOMPARE(object.status(), User::Admin);

    object.setStatus(User::Dispatcher);
    QCOMPARE(object.status(), User::Dispatcher);

    object.setStatus(User::Passenger);
    QCOMPARE(object.status(), User::Passenger);
}

void TestUsers::Checking_for_equalization()
{
    User receive("test_login", "test_password", User::Passenger);
    User equal;
    equal = receive;

    QCOMPARE(receive.login(), equal.login());
    QCOMPARE(receive.password(), equal.password());
    QCOMPARE(receive.status(), equal.status());
}

void TestUsers::action_with_strings()
{
    const QString test_string = "test_login";
    const QString test_string2 = "test_password";

    User obj(test_string, test_string2, User::Admin);
    User obj2(test_string, test_string2, User::Dispatcher);
    User obj3(test_string, test_string2, User::Passenger);

    QCOMPARE(obj.login(), test_string);
    QCOMPARE(obj.password(), test_string2);

    QCOMPARE(obj2.login(), test_string);
    QCOMPARE(obj2.password(), test_string2);

    QCOMPARE(obj3.login(), test_string);
    QCOMPARE(obj3.password(), test_string2);

}
void TestUsers::copy_action()
{
    const QString test_string = "test_login";
    const QString test_string2 = "test_password";

    User object1(test_string,test_string2, User::Admin);
    User object2(object1);
    QCOMPARE(object1.login(), object2.login());
    QCOMPARE(object1.password(), object2.password());
    QCOMPARE(object1.status(), object2.status());
}
void TestUsers::test_returned()
{

    User object1("test_login","test_password", User::Admin);

    object1.downStatus();
    QVERIFY2(object1.status()==User::Dispatcher, "some errors with change status");

    object1.downStatus();
    QVERIFY2(object1.status()==User::Passenger, "some errors with change status");

    object1.upStatus();
    QVERIFY2(object1.status()==User::Dispatcher, "some errors with change status");

    object1.upStatus();
    QVERIFY2(object1.status()==User::Admin, "some errors with change status");

}


QTEST_APPLESS_MAIN(TestUsers)

#include "tst_testusers.moc"
