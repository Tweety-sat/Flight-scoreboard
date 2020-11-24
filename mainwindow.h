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

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(User &user, QWidget *parent = nullptr);
    ~MainWindow();


    const QList<Flight> &listFlight() const;

public slots:
    void addFlight(Flight flight);
    void editFlight(int row, Flight flight);
    void deleteFlight(int row);

private slots:

    void on_infoUser_clicked();

    void on_controlflight_clicked();

    void on_controlusers_clicked();

    void on_lineFind_textChanged(const QString &arg1);


signals:
    void changeUser(); // Сигнал сообщающий об смене пользователя (закрытие текущего окна и открытие окна авторизации)


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
