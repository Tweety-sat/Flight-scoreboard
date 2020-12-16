#ifndef MAINWIDJET_H
#define MAINWIDJET_H

#include <QWidget>
class User;

/*!
    \brief Класс сигналов.
    Данный класс определяет окно при запуске и содержит в себе в сигналы авторизации, регистрации и главного окна.
    Каждый сигнал определяет какое окно и когда будет открыто пользователю.
*/
class MainWidget : public QWidget
{
    Q_OBJECT

public:
    /*!
    Конструктор класса главного окна
    \param parent ссылка на родительский объект
    */
    MainWidget(QWidget *parent = nullptr);
    ~MainWidget();

private:
    QWidget *m_currentWidget; //Текущий виджет

private slots:
    void Authorization();
    void Registration();
    void slotMainWindow(User*);
};
#endif // MAINWIDGET_H


