#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cpuhandler.h>
#include <memoryhandler.h>
#include <batteryhandler.h>

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

private:
    Ui::MainWindow *ui;
    CPUHandler cpu;
    MemoryHandler memory;
    BatteryHandler battery;
    QTimer dataTimer;
};

#endif // MAINWINDOW_H
