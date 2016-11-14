/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTabWidget *tabWidget;
    QWidget *processos;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QLabel *label;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QCustomPlot *widget_2;
    QWidget *recursos;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QCustomPlot *widget;
    QWidget *widget_3;
    QGroupBox *groupBox_2;
    QCustomPlot *widget_4;
    QWidget *energia;
    QCustomPlot *charge;
    QCustomPlot *discharge;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(591, 463);
        MainWindow->setAcceptDrops(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout_2 = new QVBoxLayout(centralWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
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
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        label = new QLabel(processos);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_3->addWidget(label, 0, Qt::AlignHCenter);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(processos);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        plainTextEdit = new QPlainTextEdit(processos);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        horizontalLayout_2->addWidget(plainTextEdit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        pushButton = new QPushButton(processos);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_3->addWidget(pushButton);

        pushButton_2 = new QPushButton(processos);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout_3->addWidget(pushButton_2);

        comboBox = new QComboBox(processos);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_3->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 400, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_3->addLayout(verticalLayout_3);

        widget_2 = new QCustomPlot(processos);
        widget_2->setObjectName(QStringLiteral("widget_2"));

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
        widget = new QCustomPlot(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 20, 521, 151));
        widget_3 = new QWidget(widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        widget_3->setGeometry(QRect(420, 10, 81, 31));

        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(recursos);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        widget_4 = new QCustomPlot(groupBox_2);
        widget_4->setObjectName(QStringLiteral("widget_4"));
        widget_4->setGeometry(QRect(0, 20, 521, 151));

        verticalLayout->addWidget(groupBox_2);

        tabWidget->addTab(recursos, QString());
        energia = new QWidget();
        energia->setObjectName(QStringLiteral("energia"));
        charge = new QCustomPlot(energia);
        charge->setObjectName(QStringLiteral("charge"));
        charge->setGeometry(QRect(40, 10, 201, 311));
        discharge = new QCustomPlot(energia);
        discharge->setObjectName(QStringLiteral("discharge"));
        discharge->setGeometry(QRect(300, 10, 221, 291));
        tabWidget->addTab(energia, QString());

        horizontalLayout->addWidget(tabWidget);


        verticalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 591, 22));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        label->setText(QApplication::translate("MainWindow", "Finalizar Processo", 0));
        label_2->setText(QApplication::translate("MainWindow", "PID", 0));
        pushButton->setText(QApplication::translate("MainWindow", "Kill", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Atualizar", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Filtro por Mem\303\263ria", 0)
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
