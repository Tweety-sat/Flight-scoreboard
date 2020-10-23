#ifndef CONTROLLFLIGHTS_H
#define CONTROLLFLIGHTS_H

#include <QDialog>

namespace Ui {
class ControlFlights;
}

class ControlFlights : public QDialog
{
    Q_OBJECT

public:
    explicit ControlFlights(QWidget *parent = nullptr);
    ~ControlFlights();


private slots:
    void on_butAdd_clicked();

private:
    Ui::ControlFlights *mUi;
};

#endif // CONTROLLFLIGHTS_H
