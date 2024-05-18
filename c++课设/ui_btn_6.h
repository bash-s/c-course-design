/********************************************************************************
** Form generated from reading UI file 'btn_6.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTN_6_H
#define UI_BTN_6_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_btn_6Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton_3;
    QLabel *label_10;
    QLabel *label_8;
    QTextEdit *textEdit;

    void setupUi(QMainWindow *btn_6Class)
    {
        if (btn_6Class->objectName().isEmpty())
            btn_6Class->setObjectName("btn_6Class");
        btn_6Class->resize(600, 543);
        centralWidget = new QWidget(btn_6Class);
        centralWidget->setObjectName("centralWidget");
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/return/return.jpg);"));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(180, 90, 231, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font.setPointSize(18);
        lineEdit_2->setFont(font);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(450, 90, 75, 41));
        pushButton_3->setFont(font);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(50, 140, 521, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(20);
        label_10->setFont(font1);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 90, 131, 41));
        label_8->setFont(font1);
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 190, 491, 311));
        textEdit->setFont(font);
        btn_6Class->setCentralWidget(centralWidget);

        retranslateUi(btn_6Class);

        QMetaObject::connectSlotsByName(btn_6Class);
    } // setupUi

    void retranslateUi(QMainWindow *btn_6Class)
    {
        btn_6Class->setWindowTitle(QCoreApplication::translate("btn_6Class", "btn_6", nullptr));
        pushButton->setText(QString());
        lineEdit_2->setText(QString());
        pushButton_3->setText(QCoreApplication::translate("btn_6Class", "\346\237\245\350\257\242", nullptr));
        label_10->setText(QString());
        label_8->setText(QCoreApplication::translate("btn_6Class", "ISBN\346\237\245\350\257\242\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class btn_6Class: public Ui_btn_6Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTN_6_H
