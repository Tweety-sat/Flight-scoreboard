#ifndef LKUSER_H
#define LKUSER_H

#include <QDialog>

class User;

namespace Ui {
class InfoUser;
}

class InfoUser : public QDialog
{
    Q_OBJECT

public:

    explicit InfoUser(QWidget *parent = nullptr);
    ~InfoUser();


private slots:

private:
    Ui::InfoUser *mUi;
};
#endif // LKUSER_H

