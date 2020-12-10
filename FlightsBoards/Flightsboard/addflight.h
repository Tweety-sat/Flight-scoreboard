#ifndef ADDFLIGHT_H
#define ADDFLIGHT_H

#include <QDialog>

class Flight;

namespace Ui {
class AddFlight;
}
// Окно добавления и редактирования рейсов
class AddFlight : public QDialog
{
    Q_OBJECT

public:
    enum Type { Create, //Создание рейса
                Edit }; //Редактирование рейса

    //Конструктор получит: указатель на рейс, лист рейсов, тип окна
    explicit AddFlight(Flight *flight, const QList<Flight> &listFlight, Type type, QWidget *parent = nullptr);
    ~AddFlight();

private:
    Ui::AddFlight *mUi;
    //Начальный номер рейса для проверки свободен ли номер
    QString m_startNumberFlight;
    //Указатель на переданный объект рейса
    Flight *m_flight;
    //Список рейсов
    const QList<Flight> &m_listflight;

public slots:
    void accept();

private slots:

};

#endif // ADDFLIGHT_H

