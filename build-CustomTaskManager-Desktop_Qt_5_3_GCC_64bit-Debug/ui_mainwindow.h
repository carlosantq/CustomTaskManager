/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWebKitWidgets/QWebView>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *processos;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_6;
    QLineEdit *strPid;
    QPushButton *killButton;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *processDisplay;
    QVBoxLayout *verticalLayout_3;
    QWebView *myWebView;
    QWidget *recursos;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QCustomPlot *cpuHistory;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QCustomPlot *memoryHistory;
    QWidget *energia;
    QHBoxLayout *horizontalLayout_5;
    QCustomPlot *charge;
    QCustomPlot *discharge;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(739, 535);
        MainWindow->setAcceptDrops(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout_4 = new QHBoxLayout(centralWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        processos = new QWidget();
        processos->setObjectName(QStringLiteral("processos"));
        horizontalLayout_3 = new QHBoxLayout(processos);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        widget_2 = new QWidget(processos);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        strPid = new QLineEdit(widget_2);
        strPid->setObjectName(QStringLiteral("strPid"));

        horizontalLayout_6->addWidget(strPid);

        killButton = new QPushButton(widget_2);
        killButton->setObjectName(QStringLiteral("killButton"));

        horizontalLayout_6->addWidget(killButton);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        processDisplay = new QComboBox(widget_2);
        processDisplay->setObjectName(QStringLiteral("processDisplay"));
        processDisplay->setMaximumSize(QSize(162, 27));

        horizontalLayout_7->addWidget(processDisplay);


        verticalLayout_2->addLayout(horizontalLayout_7);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setSizeConstraint(QLayout::SetMinimumSize);
        myWebView = new QWebView(widget_2);
        myWebView->setObjectName(QStringLiteral("myWebView"));
        myWebView->setProperty("url", QVariant(QUrl(QStringLiteral("file:///home/murilao/Documents/SO/cpps/u2/ProjetoVersaoFinal/build-CustomTaskManager-Desktop_Qt_5_3_GCC_64bit-Debug/index2.html"))));

        verticalLayout_3->addWidget(myWebView);


        verticalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_3->addWidget(widget_2);

        tabWidget->addTab(processos, QString());
        recursos = new QWidget();
        recursos->setObjectName(QStringLiteral("recursos"));
        verticalLayout = new QVBoxLayout(recursos);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(recursos);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        cpuHistory = new QCustomPlot(groupBox);
        cpuHistory->setObjectName(QStringLiteral("cpuHistory"));

        verticalLayout_4->addWidget(cpuHistory);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(recursos);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        memoryHistory = new QCustomPlot(groupBox_2);
        memoryHistory->setObjectName(QStringLiteral("memoryHistory"));

        verticalLayout_5->addWidget(memoryHistory);


        verticalLayout->addWidget(groupBox_2);

        tabWidget->addTab(recursos, QString());
        energia = new QWidget();
        energia->setObjectName(QStringLiteral("energia"));
        horizontalLayout_5 = new QHBoxLayout(energia);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        charge = new QCustomPlot(energia);
        charge->setObjectName(QStringLiteral("charge"));

        horizontalLayout_5->addWidget(charge);

        discharge = new QCustomPlot(energia);
        discharge->setObjectName(QStringLiteral("discharge"));

        horizontalLayout_5->addWidget(discharge);

        tabWidget->addTab(energia, QString());

        horizontalLayout->addWidget(tabWidget);


        horizontalLayout_4->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 739, 20));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        killButton->setText(QApplication::translate("MainWindow", "Kill", 0));
        processDisplay->clear();
        processDisplay->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Display by CPU usage", 0)
         << QApplication::translate("MainWindow", "Display by number of threads", 0)
         << QApplication::translate("MainWindow", "Display by RAM", 0)
         << QApplication::translate("MainWindow", "Display by Gourmet schedule", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(processos), QApplication::translate("MainWindow", "Processos", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Hist\303\263rico de CPU", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Hist\303\263rico de Mem\303\263ria", 0));
        tabWidget->setTabText(tabWidget->indexOf(recursos), QApplication::translate("MainWindow", "Recursos", 0));
        tabWidget->setTabText(tabWidget->indexOf(energia), QApplication::translate("MainWindow", "Energia", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
