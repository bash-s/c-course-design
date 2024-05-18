/********************************************************************************
** Form generated from reading UI file 'btn_2.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTN_2_H
#define UI_BTN_2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_btn_2Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;

    void setupUi(QMainWindow *btn_2Class)
    {
        if (btn_2Class->objectName().isEmpty())
            btn_2Class->setObjectName("btn_2Class");
        btn_2Class->resize(600, 543);
        centralWidget = new QWidget(btn_2Class);
        centralWidget->setObjectName("centralWidget");
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/return/return.jpg);"));
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, 70, 131, 41));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font.setPointSize(20);
        label->setFont(font);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(220, 70, 231, 41));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(18);
        lineEdit->setFont(font1);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(210, 150, 75, 31));
        pushButton_2->setFont(font1);
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(90, 210, 361, 271));
        scrollArea->setFont(font1);
        scrollArea->setAutoFillBackground(false);
        scrollArea->setWidgetResizable(false);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 500, 500));
        label_2 = new QLabel(scrollAreaWidgetContents);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(0, 0, 500, 30));
        label_3 = new QLabel(scrollAreaWidgetContents);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(0, 40, 500, 30));
        label_4 = new QLabel(scrollAreaWidgetContents);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(0, 80, 500, 30));
        label_5 = new QLabel(scrollAreaWidgetContents);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(0, 120, 500, 30));
        label_6 = new QLabel(scrollAreaWidgetContents);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(0, 160, 500, 30));
        label_7 = new QLabel(scrollAreaWidgetContents);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(0, 200, 500, 30));
        label_8 = new QLabel(scrollAreaWidgetContents);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(0, 240, 500, 30));
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 30, 241, 201));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font2.setPointSize(28);
        label_9->setFont(font2);
        scrollArea->setWidget(scrollAreaWidgetContents);
        btn_2Class->setCentralWidget(centralWidget);

        retranslateUi(btn_2Class);

        QMetaObject::connectSlotsByName(btn_2Class);
    } // setupUi

    void retranslateUi(QMainWindow *btn_2Class)
    {
        btn_2Class->setWindowTitle(QCoreApplication::translate("btn_2Class", "btn_2", nullptr));
        pushButton->setText(QString());
        label->setText(QCoreApplication::translate("btn_2Class", "ISBN\346\237\245\350\257\242\357\274\232", nullptr));
        lineEdit->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("btn_2Class", "\346\237\245\350\257\242", nullptr));
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class btn_2Class: public Ui_btn_2Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTN_2_H
