/********************************************************************************
** Form generated from reading UI file 'mywidget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYWIDGET_H
#define UI_MYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mywidgetClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;

    void setupUi(QMainWindow *mywidgetClass)
    {
        if (mywidgetClass->objectName().isEmpty())
            mywidgetClass->setObjectName("mywidgetClass");
        mywidgetClass->resize(750, 685);
        mywidgetClass->setAnimated(false);
        centralWidget = new QWidget(mywidgetClass);
        centralWidget->setObjectName("centralWidget");
        label = new QLabel(centralWidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 20, 531, 61));
        QFont font;
        font.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font.setPointSize(48);
        label->setFont(font);
        label->setTextFormat(Qt::AutoText);
        label->setWordWrap(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 130, 341, 71));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("\345\215\216\346\226\207\346\245\267\344\275\223")});
        font1.setPointSize(20);
        pushButton->setFont(font1);
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 270, 341, 71));
        pushButton_2->setFont(font1);
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(10, 420, 341, 71));
        pushButton_3->setFont(font1);
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 580, 341, 71));
        pushButton_4->setFont(font1);
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(410, 130, 341, 71));
        pushButton_5->setFont(font1);
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(410, 270, 331, 71));
        pushButton_6->setFont(font1);
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(410, 420, 341, 71));
        pushButton_7->setFont(font1);
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(410, 580, 341, 71));
        pushButton_8->setFont(font1);
        mywidgetClass->setCentralWidget(centralWidget);

        retranslateUi(mywidgetClass);

        QMetaObject::connectSlotsByName(mywidgetClass);
    } // setupUi

    void retranslateUi(QMainWindow *mywidgetClass)
    {
        mywidgetClass->setWindowTitle(QCoreApplication::translate("mywidgetClass", "mywidget", nullptr));
        label->setText(QCoreApplication::translate("mywidgetClass", "\345\233\276\344\271\246\345\200\237\351\230\205\347\256\241\347\220\206\347\263\273\347\273\237", nullptr));
        pushButton->setText(QCoreApplication::translate("mywidgetClass", "1.\345\275\225\345\205\245\345\233\276\344\271\246\344\277\241\346\201\257", nullptr));
        pushButton_2->setText(QCoreApplication::translate("mywidgetClass", "2.\346\237\245\350\257\242\345\233\276\344\271\246\344\277\241\346\201\257", nullptr));
        pushButton_3->setText(QCoreApplication::translate("mywidgetClass", "3.\344\277\256\346\224\271\345\233\276\344\271\246\344\277\241\346\201\257", nullptr));
        pushButton_4->setText(QCoreApplication::translate("mywidgetClass", "4.\345\200\237/\350\277\230\344\271\246", nullptr));
        pushButton_5->setText(QCoreApplication::translate("mywidgetClass", "5.\346\237\245\350\257\242\345\200\237\351\230\205\350\200\205\344\277\241\346\201\257", nullptr));
        pushButton_6->setText(QCoreApplication::translate("mywidgetClass", "6.\346\237\245\350\257\242\345\200\237\351\230\205\344\277\241\346\201\257", nullptr));
        pushButton_7->setText(QCoreApplication::translate("mywidgetClass", "7.\351\200\276\346\234\237\346\217\220\351\206\222", nullptr));
        pushButton_8->setText(QCoreApplication::translate("mywidgetClass", "8.\344\277\256\346\224\271\345\200\237\351\230\205\350\200\205\344\277\241\346\201\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class mywidgetClass: public Ui_mywidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYWIDGET_H
