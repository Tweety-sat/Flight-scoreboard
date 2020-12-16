#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include "users.h"
#include <flight.h>
#include <QTableWidgetItem>
class InfoUser;

namespace Ui {
class MainWindow;
}
/*!
    \brief Класс главного окна.
    Главное окно - основное окно пользователя, оно содержит в себе основные кнопки управления пользователями, рейсами и информации о личном кабинете.
*/
class MainWindow : public QWidget
{
    Q_OBJECT

public:
    /*!
    Конструктор класса главного окна
    \param user ссылка на пользователя со всеми данными о нем
    \param parent ссылка на родительский объект
    */
    explicit MainWindow(User &user, QWidget *parent = nullptr);
    ~MainWindow();

    ///Список рейсов
    const QList<Flight> &listFlight() const;

public slots:
    /*! \brief Функция добавления рейса
             \param flight рейс
        */
    void addFlight(Flight flight);
    /*! \brief Функция редактирования рейса
             \param row строка, выбранного рейса
             \param flight рейс
        */
    void editFlight(int row, Flight flight);
    /*! \brief Функция удаления рейса
             \param row строка, выбранного рейса
        */
    void deleteFlight(int row);

private slots:

    void on_infoUser_clicked();
    void on_controlflight_clicked();
    void on_controlusers_clicked();
    void on_lineFind_textChanged(const QString &arg1);

    void on_pushButton_clicked();

signals:
    void changeUser(); ///< Сигнал сообщающий об смене пользователя (закрытие текущего окна и открытие окна авторизации)


private:
    Ui::MainWindow *mUi;

    //Текущий пользователь. Ссылка, чтобы не было необходимости очищать память после передачи данных
    User &m_user;

    InfoUser *m_infoDialog;

    //Список рейсов
    QList<Flight> m_listFlight;
    void loadFlights();

};
#endif // MAINWINDOW_H

