/********************************************************************************
** Form generated from reading UI file 'auth.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTH_H
#define UI_AUTH_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_auth
{
public:
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *map;
    QLabel *label;
    QTextEdit *about;

    void setupUi(QWidget *auth)
    {
        if (auth->objectName().isEmpty())
            auth->setObjectName(QString::fromUtf8("auth"));
        auth->resize(702, 313);
        layoutWidget = new QWidget(auth);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(30, 20, 657, 274));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        map = new QLabel(layoutWidget);
        map->setObjectName(QString::fromUtf8("map"));
        map->setPixmap(QPixmap(QString::fromUtf8("logo.png")));

        horizontalLayout->addWidget(map);

        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setPixmap(QPixmap(QString::fromUtf8("../3.png")));
        label->setScaledContents(true);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        horizontalLayout->addWidget(label);

        about = new QTextEdit(layoutWidget);
        about->setObjectName(QString::fromUtf8("about"));
        about->setEnabled(false);
        about->setMinimumSize(QSize(300, 0));
        about->setMouseTracking(true);

        horizontalLayout->addWidget(about);


        retranslateUi(auth);

        QMetaObject::connectSlotsByName(auth);
    } // setupUi

    void retranslateUi(QWidget *auth)
    {
        auth->setWindowTitle(QCoreApplication::translate("auth", "\320\230\320\275\321\204\320\276\321\200\320\274\320\260\321\206\320\270\321\217 \320\276\320\261 \320\260\320\262\321\202\320\276\321\200\320\260\321\205", nullptr));
        map->setText(QString());
        label->setText(QString());
        about->setHtml(QCoreApplication::translate("auth", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0055ff;\">\320\220\320\262\321\202\320\276\321\200: \320\221\320\270\320\273\320\265\320\262\320\270\321\207 \320\220\320\275\320\260\321\201\321\202\320\260\321\201\320\270\321\217 \320\222\321\217\321\207\320\265\321\201\320\273\320\260\320\262\320\276\320\262\320\275\320\260</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0055ff;\">\320\241\321\202\321\203\320\264\320\265\320\275\321\202"
                        " \320\263\321\200\321\203\320\277\320\277\321\213: \320\232\320\23019-09\320\221</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; color:#0055ff;\">\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\321\207\320\265\321\202\320\275\320\276\320\271 \320\272\320\275\320\270\320\266\320\272\320\270: 031940905</span></p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class auth: public Ui_auth {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTH_H
