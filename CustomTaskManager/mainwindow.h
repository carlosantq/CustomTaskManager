#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cpuhandler.h>
#include <memoryhandler.h>
#include <batteryhandler.h>
#include <thread>
#include "operationtype.h"
#include "processhandler.h"
#include <csignal>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void resourcesChart();
    void realtimeDataSlot();
    void memoryChart();
    void realtimeDataSlot2();
    void batteryDischargeChart();
    void realtimeDataSlot3();
    void batteryChargeChart();
    void realtimeDataSlot4();

    void on_killButton_clicked();
    void on_processDisplay_currentIndexChanged(int index);
    void refreshHTML();

    void start();
    void run();

private:
    Ui::MainWindow *ui;
    CPUHandler cpu;
    MemoryHandler memory;
    BatteryHandler battery;
    QTimer dataTimer;
    std::thread cpuThread;
    std::thread memThread;
    std::thread chargeThread;
    std::thread dischargeThread;
    bool firstTime;
};

#endif // MAINWINDOW_H
