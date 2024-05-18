/********************************************************************************
** Form generated from reading UI file 'btn_7.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTN_7_H
#define UI_BTN_7_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_btn_7Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QTextEdit *textEdit;
    QLabel *label;
    QPushButton *pushButton_2;

    void setupUi(QMainWindow *btn_7Class)
    {
        if (btn_7Class->objectName().isEmpty())
            btn_7Class->setObjectName("btn_7Class");
        btn_7Class->resize(600, 543);
        centralWidget = new QWidget(btn_7Class);
        centralWidget->setObjectName("centralWidget");
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/return/return.jpg);"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(40, 110, 521, 411));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font.setPointSize(18);
        textEdit->setFont(font);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(230, 10, 101, 51));
        label->setFont(font);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(240, 60, 75, 41));
        pushButton_2->setFont(font);
        btn_7Class->setCentralWidget(centralWidget);

        retranslateUi(btn_7Class);

        QMetaObject::connectSlotsByName(btn_7Class);
    } // setupUi

    void retranslateUi(QMainWindow *btn_7Class)
    {
        btn_7Class->setWindowTitle(QCoreApplication::translate("btn_7Class", "btn_7", nullptr));
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("btn_7Class", "\351\200\276\346\234\237\345\220\215\345\215\225", nullptr));
        pushButton_2->setText(QCoreApplication::translate("btn_7Class", "\346\230\276\347\244\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class btn_7Class: public Ui_btn_7Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTN_7_H
