#ifndef MANAGEFLIGHT_H
#define MANAGEFLIGHT_H

#include <QDialog>
#include "flight.h"

namespace Ui {
class ManageFlight;
}
// Окно для управления рейсами
class ManageFlight : public QDialog
{
    Q_OBJECT

public:

    //конструктор получит: ссылку на список рейсов из mainwindow
    explicit ManageFlight(const QList<Flight> &listFlight, QWidget *parent = nullptr);
    ~ManageFlight();

private slots:

    void on_lineFind_textChanged(const QString &arg1);

    void on_add_clicked();

    void on_del_clicked();

    void on_edit_clicked();

private:
    Ui::ManageFlight *mUi;
    const QList<Flight> &m_listFlight;

signals:    
    void addFlight(Flight); //Сигнал отправляемый при добавлении нового рейса, посылает добавленный рейс
    void editFlight(int, Flight); //Сигнал отправляемый при редактировании рейса, посылает номер редактируемой строки, а также новые данные о поезде
    void deleteFlight(int); //Сигнал отправляемый при удалении рейса, посылает номер удаляемой строки

};



#endif // MANAGEFLIGHT_H


