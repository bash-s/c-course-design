/********************************************************************************
** Form generated from reading UI file 'btn_5.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BTN_5_H
#define UI_BTN_5_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_btn_5Class
{
public:
    QWidget *centralWidget;
    QPushButton *pushButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_9;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_2;
    QLabel *label_8;
    QPushButton *pushButton_3;
    QLabel *label_10;
    QLineEdit *lineEdit_2;

    void setupUi(QMainWindow *btn_5Class)
    {
        if (btn_5Class->objectName().isEmpty())
            btn_5Class->setObjectName("btn_5Class");
        btn_5Class->resize(600, 543);
        centralWidget = new QWidget(btn_5Class);
        centralWidget->setObjectName("centralWidget");
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 0, 41, 41));
        pushButton->setStyleSheet(QString::fromUtf8("image: url(:/return/return.jpg);"));
        scrollArea = new QScrollArea(centralWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setGeometry(QRect(70, 250, 361, 271));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font.setPointSize(18);
        scrollArea->setFont(font);
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
        label_9 = new QLabel(scrollAreaWidgetContents);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(60, 30, 241, 201));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(28);
        label_9->setFont(font1);
        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 170, 161, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font2.setPointSize(20);
        label->setFont(font2);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(200, 170, 231, 41));
        lineEdit->setFont(font);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(470, 170, 75, 41));
        pushButton_2->setFont(font);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(60, 60, 131, 41));
        label_8->setFont(font2);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(470, 60, 75, 41));
        pushButton_3->setFont(font);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(60, 110, 521, 41));
        label_10->setFont(font2);
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(200, 60, 231, 41));
        lineEdit_2->setFont(font);
        btn_5Class->setCentralWidget(centralWidget);

        retranslateUi(btn_5Class);

        QMetaObject::connectSlotsByName(btn_5Class);
    } // setupUi

    void retranslateUi(QMainWindow *btn_5Class)
    {
        btn_5Class->setWindowTitle(QCoreApplication::translate("btn_5Class", "btn_5", nullptr));
        pushButton->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_9->setText(QString());
        label->setText(QCoreApplication::translate("btn_5Class", "\350\257\273\350\200\205ID\346\237\245\350\257\242\357\274\232", nullptr));
        lineEdit->setText(QString());
        pushButton_2->setText(QCoreApplication::translate("btn_5Class", "\346\237\245\350\257\242", nullptr));
        label_8->setText(QCoreApplication::translate("btn_5Class", "ISBN\346\237\245\350\257\242\357\274\232", nullptr));
        pushButton_3->setText(QCoreApplication::translate("btn_5Class", "\346\237\245\350\257\242", nullptr));
        label_10->setText(QString());
        lineEdit_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class btn_5Class: public Ui_btn_5Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BTN_5_H
