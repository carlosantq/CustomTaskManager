#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <cpuhandler.h>
#include <graphichandler.h>

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

private:
    Ui::MainWindow *ui;
    CPUHandler cpu;
    GraphicHandler gh;
    QTimer dataTimer;
};

#endif // MAINWINDOW_H
