#ifndef CONTROLLUSERS_H
#define CONTROLLUSERS_H

#include <QDialog>

namespace Ui {
class ControlUsers;
}

class ControlUsers : public QDialog
{
    Q_OBJECT

public:
    explicit ControlUsers(QWidget *parent = nullptr);
    ~ControlUsers();


private slots:
    void on_butaddw_clicked();

private:
    Ui::ControlUsers *mUi;
};

#endif // CONTROLLUSERS_H
