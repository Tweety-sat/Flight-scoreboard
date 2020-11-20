#ifndef MAINWIDJET_H
#define MAINWIDJET_H

#include <QWidget>
class User;

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    QWidget *m_currentWidget; //Текущий виджет

private slots:
    void slotOpenAuthorization();
    void slotOpenRegistration();
    void slotOpenMainWindow(User*);
};
#endif // MAINWIDGET_H


