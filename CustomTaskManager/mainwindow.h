#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cpuhandler.h>
#include <memoryhandler.h>

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
    void realtimeDataSlot();
    void resourcesChart();
    void memoryChart();
    void realtimeDataSlot2();

private:
    Ui::MainWindow *ui;
    CPUHandler cpu;
    MemoryHandler memory;
    QTimer dataTimer;
};

#endif // MAINWINDOW_H
