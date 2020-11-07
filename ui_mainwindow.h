/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *push_cam;
    QPushButton *push_laser;
    QPushButton *push_CCW;
    QPushButton *push_CW;
    QLabel *opencvFrame;
    QLabel *labelDate;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 480);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        push_cam = new QPushButton(centralWidget);
        push_cam->setObjectName(QStringLiteral("push_cam"));
        push_cam->setGeometry(QRect(25, 148, 172, 89));
        push_laser = new QPushButton(centralWidget);
        push_laser->setObjectName(QStringLiteral("push_laser"));
        push_laser->setGeometry(QRect(25, 263, 172, 78));
        push_CCW = new QPushButton(centralWidget);
        push_CCW->setObjectName(QStringLiteral("push_CCW"));
        push_CCW->setGeometry(QRect(25, 372, 78, 78));
        push_CW = new QPushButton(centralWidget);
        push_CW->setObjectName(QStringLiteral("push_CW"));
        push_CW->setGeometry(QRect(119, 372, 78, 78));
        opencvFrame = new QLabel(centralWidget);
        opencvFrame->setObjectName(QStringLiteral("opencvFrame"));
        opencvFrame->setGeometry(QRect(220, 0, 580, 480));
        labelDate = new QLabel(centralWidget);
        labelDate->setObjectName(QStringLiteral("labelDate"));
        labelDate->setGeometry(QRect(43, 50, 146, 45));
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        push_cam->setText(QString());
        push_laser->setText(QString());
        push_CCW->setText(QString());
        push_CW->setText(QString());
        opencvFrame->setText(QString());
        labelDate->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
