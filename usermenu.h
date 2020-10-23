#ifndef USERMENU_H
#define USERMENU_H

#include <QDialog>


namespace Ui {
class UserMenu;
}

class UserMenu : public QDialog
{
    Q_OBJECT

public:

    explicit UserMenu(QWidget *parent = nullptr);
    ~UserMenu();


private slots:

    void on_info_clicked();

    void on_author_clicked();

    void on_registr_clicked();

private:
    Ui::UserMenu *mUi;
};

#endif // USERMENU_H
