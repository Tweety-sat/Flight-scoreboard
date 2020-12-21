#include "ManageUsers.h"
#include "ui_ManageUsers.h"
#include "config.h"
#include "addusers.h"

#include <QFile>
#include <QDataStream>
#include <QMessageBox>
#include <QDebug>

ManageUsers::ManageUsers(QWidget *parent) :
    QDialog(parent),
    mUi(new Ui::ManageUsers)
{
    mUi->setupUi(this);

    // Считывание данных о пользователях из файла и перенос их в таблицу
    QFile file(Config::Usersbin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);
        int row = 0; //столбец
        //Пока файл не считан до конца, считываются данные о пользователе
        while (!ist.atEnd()) {
            User user;
            ist >> user;
            m_listUsers.append(user);

            // Создание элементов таблицы с нужным текстом
            QTableWidgetItem *item_login = new QTableWidgetItem(user.login()); //Логин
            QTableWidgetItem *item_status = new QTableWidgetItem(user.statusString()); //статус

            mUi->TableUsers->insertRow(row);// Вставка строки
            // Установка элементов в таблицу
            mUi->TableUsers->setItem(row, 0, item_login);
            mUi->TableUsers->setItem(row, 1, item_status);
            row++;
        }
    }
}

ManageUsers::~ManageUsers()
{
    delete mUi;
}

void ManageUsers::slotUpDownStatus()
{
    //Используем один общий слот для повышения и понижения статуса
    // qobject_cast<> преобразует объект к нужному типу.
    // sender() — функция, возвращающая указатель на объект который вызвал этот слот.
    // По умолчанию sender() возвращает объект типа QObject, именно поэтому мы преобразуем его в QPushButton.
    QPushButton *btn = qobject_cast<QPushButton*>(sender());

    int currentRow = mUi->TableUsers->currentRow();
    if (currentRow != -1) //currentRow возвращает -1, те если строка не выбрана. Т.е. данная строка проверяет выбран ли пользователь
    {
        // Получаем данные из выбранной строки
        const QString login = mUi->TableUsers->item(currentRow, 0)->text();
        const QString status = mUi->TableUsers->item(currentRow, 1)->text();

        if (status == "Администратор" && countAdmins() <= 1) //если выбранный пользователь имеет статус администратора, но при этом это единственный администратор в системе,
        {
            QMessageBox::warning(this, windowTitle(), "Ошибка: не удалось изменить статус пользователя!"); //то выводится ошибка о невозможности понизить пользователя
            return;
        }

        // Перезапись_Данных
        // Открываем файл со всеми пользователями и одновременно создаем буфер-файл в который в дальнейшем будем переписывать данные из основного файла.
        // После удаляем основной файл с пользователями, а буфер-файл переименуем под название основного файла.

        //Перезапись данных
        QFile file(Config::Usersbin); //Основной файл
        if (file.open(QIODevice::ReadOnly)) { //Открываем его для чтения
            QFile write_file("buf_file_users"); //буфер-файл
            write_file.open(QIODevice::WriteOnly); //Открываем его для записи

            //Создание потоков
            QDataStream read_ist(&file);
            QDataStream write_ist(&write_file);

            //Начало считывание
            while (!read_ist.atEnd())
            {
                User user;
                read_ist >> user;

                if (user.login() == login)
                {    // Если логин считанного пользователя совпал с логином редактируемого пользователя
                    if (btn->objectName() == "up") //если была нажата кнопка повышения статуса (проверка через имя объекта)
                    {


                        if (!user.upStatus())
                        {
                            QMessageBox::warning(this, windowTitle(),
                                                 "Ошибка: невозможно повысить статус!\n"
                                                 "Данный статус является максимальным.");
                        }
                    }
                    else
                    {
                        if (!user.downStatus())  //если была нажата кнопка понижения статуса (проверка через имя объекта)
                        {
                            QMessageBox::warning(this, windowTitle(),
                                                 "Ошибка: невозможно понизить статус!\n"
                                                 "Данный статус является минимальным.");
                        }
                    }

                    mUi->TableUsers->item(currentRow, 1)->setText(user.statusString()); //изменение статуса в таблице
                }
                write_ist << user; //запсь пользователя в файл-буфер
            }
            //Закрываем основной файли и удаляем его
            file.close();
            file.remove();
            //Закрываем файл-буфер и переименовываем его
            write_file.close();
            write_file.rename(Config::Usersbin);
        }
    }
    else
    {
        QMessageBox::warning(this, windowTitle(),
                             "Ошибка: не удалось повысить/понизить пользователя!");
    }
}		

void ManageUsers::on_delete_2_clicked()
{
    int currentRow = mUi->TableUsers->currentRow();
    if (currentRow != -1) //currentRow возвращает -1, те если строка не выбрана. Т.е. данная строка проверяет выбран ли пользователь
    {
        const QString login = mUi->TableUsers->item(currentRow, 0)->text();
        const QString status = mUi->TableUsers->item(currentRow, 1)->text();

        if (status == "Администратор" && countAdmins() <= 1)
        { // Если выбранный пользователь единтсвенный администратор, то оповещаем об этом отедльным предупреждающим окном, действия не производятся
            QMessageBox::warning(this, windowTitle(),
                                 "Ошибка: не удалось изменить статус пользователя!");
            return;
        }
        mUi->TableUsers->removeRow(currentRow); // Удаление строки из таблицы с выбранным пользователем

        //перезапись данных
        QFile file(Config::Usersbin);
        if (file.open(QIODevice::ReadOnly))
        {
            QFile write_file("buf_file_users");
            write_file.open(QIODevice::WriteOnly);

            QDataStream read_ist(&file);
            QDataStream write_ist(&write_file);

            while (!read_ist.atEnd())
            {
                User user;
                read_ist >> user;

                if (user.login() != login) 	// Перезаписываем все данные кроме тех, когда логины совпадут. Таким образом, удалим выбранного пользователя
                {
                    write_ist << user;
                }
            }

            file.close();
            file.remove();
            write_file.close();
            write_file.rename(Config::Usersbin);
        }
    }
    else //если пользователь не выбран
    {
        QMessageBox::warning(this, windowTitle(),
                             "Ошибка: Необходимо выбрать пользователя!");
    }
}

void ManageUsers::on_add_clicked()
{
    // Создание окна для добавления пользователя
    AddUsers dialog(this);
    dialog.setWindowTitle(windowTitle());

    // Вызываем открытие окна, и если окно было успешно закрыто (был добавлен пользователь)
    if (dialog.exec() == QDialog::Accepted)
    {
        const User &user = dialog.getUser(); // Передаем из окна данные о пользователе

        // Записываем данные в файл
        QFile file(Config::Usersbin);
        file.open(QIODevice::Append);
        QDataStream ost(&file);
        ost << user;

        // Добавление данных о новом пользователе в таблицу
        QTableWidgetItem *item_login = new QTableWidgetItem(user.login());
        QTableWidgetItem *item_status = new QTableWidgetItem(user.statusString());

        int row = mUi->TableUsers->rowCount(); //создание строки
        //занесение данных в созданную строку таблицы
        mUi->TableUsers->insertRow(row);
        mUi->TableUsers->setItem(row, 0, item_login);
        mUi->TableUsers->setItem(row, 1, item_status);
    }
}

//Функция подсчета количества админов
int ManageUsers::countAdmins() const
{
    //считываем данные с довичного файла данные о каждом пользователе, увеличивая счетчик
    QFile file(Config::Usersbin);
    if (file.open(QIODevice::ReadOnly)) {
        QDataStream ist(&file);

        int count = 0;
        while (!ist.atEnd()) {
            User user;
            ist >> user;
            if (user.status() == User::Admin) count++;
        }
        return count;
    }
    else return 0;
}

//Поле поиска
void ManageUsers::on_lineFind_textChanged(const QString &arg1)
{
    QStringList listStr = arg1.split(" ");
    listStr.removeAll(QString());

    for (int i = 0; i < m_listUsers.size(); i++) {
        mUi->TableUsers->showRow(i);
    }

    int row = 0;
    foreach (const User &user, m_listUsers) {
        int count = 0;
        foreach (const QString &str, listStr) {
            if (user.login().contains(str) ||
                    user.statusString().contains(str)) {
                count++;
            }
        }
        if (count != listStr.size()) {
            mUi->TableUsers->hideRow(row);
        }
        row++;
    }
}

