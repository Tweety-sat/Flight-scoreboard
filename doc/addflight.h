#ifndef ADDFLIGHT_H
#define ADDFLIGHT_H

#include <QDialog>

namespace Ui {
class AddFlight;
}

class AddFlight : public QDialog
{
    Q_OBJECT

public:
    explicit AddFlight(QWidget *parent = nullptr);
    ~AddFlight();

private slots:


private:
    Ui::AddFlight *mUi;
};

#endif // ADDFLIGHT_H
