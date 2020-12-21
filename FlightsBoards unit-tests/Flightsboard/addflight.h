#ifndef ADDFLIGHT_H
#define ADDFLIGHT_H

#include <QDialog>

//Класс рейса
class Flight;

namespace Ui {
class AddFlight;
}
/*!
    \brief Класс добавления/редактирования рейса.
    Данный класс существует для добавления рейса или его редактирования.
*/
class AddFlight : public QDialog
{
    Q_OBJECT

public:
    /// Набор действий с рейсами
    enum Type { Create, ///< Указывает, что производится создание
                Edit ///< Указывает, что производится редактирование
              };

    /*!
    Конструктор класса добавления рейса
    \param flight рейс, с его содержимым
    \param listFlight список рейсов
    \param type тип действия, прозиводимого над рейсом
    \param parent ссылка на родительский объект
    */
    explicit AddFlight(Flight *flight, const QList<Flight> &listFlight, Type type, QWidget *parent = nullptr);
    ~AddFlight();

private:
    //Указатель главного класса
    Ui::AddFlight *mUi;
    //Начальный номер рейса для проверки свободен ли номер
    QString m_startNumberFlight;
    //Указатель на переданный объект рейса
    Flight *m_flight;
    //Список рейсов
    const QList<Flight> &m_listflight;

public slots:
    ///Кнопка "Принять" для добавления рейса
    void accept();

private slots:

};

#endif // ADDFLIGHT_H

