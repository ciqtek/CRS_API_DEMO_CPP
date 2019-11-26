/********************************************************************************
** Form generated from reading UI file 'TestCRSDll.ui'
**
** Created by: Qt User Interface Compiler version 5.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCRSDLL_H
#define UI_TESTCRSDLL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestCRSDllClass
{
public:
    QWidget *centralWidget;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QWidget *widget_5;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestCRSDllClass)
    {
        if (TestCRSDllClass->objectName().isEmpty())
            TestCRSDllClass->setObjectName(QStringLiteral("TestCRSDllClass"));
        TestCRSDllClass->resize(917, 474);
        centralWidget = new QWidget(TestCRSDllClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(20, 10, 170, 391));
        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(200, 10, 170, 391));
        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(380, 10, 170, 391));
        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(560, 10, 170, 391));
        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QStringLiteral("widget_5"));
        widget_5->setGeometry(QRect(740, 10, 170, 391));
        TestCRSDllClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TestCRSDllClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 917, 23));
        TestCRSDllClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TestCRSDllClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TestCRSDllClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TestCRSDllClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TestCRSDllClass->setStatusBar(statusBar);

        retranslateUi(TestCRSDllClass);

        QMetaObject::connectSlotsByName(TestCRSDllClass);
    } // setupUi

    void retranslateUi(QMainWindow *TestCRSDllClass)
    {
        TestCRSDllClass->setWindowTitle(QApplication::translate("TestCRSDllClass", "TestCRSDll", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TestCRSDllClass: public Ui_TestCRSDllClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCRSDLL_H
