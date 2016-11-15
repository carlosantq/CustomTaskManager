#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resourcesChart();
    memoryChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resourcesChart(){
    int i = 0;
    int n = cpu.getNumberOfCPU();

    ui->cpuHistory->legend->setVisible(true);

    while (i < n){
        ui->cpuHistory->addGraph(); // blue line
        ui->cpuHistory->graph(i)->setPen(QPen(QColor(cpu.getColor1(), cpu.getColor2(), cpu.getColor3())));

        QString name = QString("CPU %1").arg(i);
        ui->cpuHistory->graph(i)->setName(name);

        cpu.randomColors();

        i++;
    }

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->cpuHistory->xAxis->setTicker(timeTicker);
    ui->cpuHistory->axisRect()->setupFullAxesBox();
    ui->cpuHistory->yAxis->setRange(0, 1);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->cpuHistory->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->cpuHistory->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->cpuHistory->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->cpuHistory->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

void MainWindow::memoryChart(){

    ui->memoryHistory->legend->setVisible(true);

    ui->memoryHistory->addGraph();
    ui->memoryHistory->graph(0)->setPen(QColor(255, 110, 40));
    ui->memoryHistory->graph(0)->setName("RAM");
    ui->memoryHistory->addGraph();
    ui->memoryHistory->graph(1)->setPen(QColor(40, 110, 255));
    ui->memoryHistory->graph(1)->setName("Swap");

    memory.readMemory();

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->memoryHistory->xAxis->setTicker(timeTicker);
    ui->memoryHistory->axisRect()->setupFullAxesBox();
    ui->memoryHistory->yAxis->setRange(0, 100);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->memoryHistory->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->memoryHistory->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->memoryHistory->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->memoryHistory->yAxis2, SLOT(setRange(QCPRange)));

    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot2()));
    dataTimer.start(0); // Interval 0 means to refresh as fast as possible
}

void MainWindow::realtimeDataSlot(){
    int i = 0;
    int n = cpu.getNumberOfCPU();

    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.002) // at most add point every 2 ms
    {
      while(i < n){
          ui->cpuHistory->graph(i)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.385));
          i++;
      }
      // add data to lines:
      // ui->widget->graph(0)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.3843));
      // ui->widget->graph(1)->addData(key, qCos(key)+qrand()/(double)RAND_MAX*0.5*qSin(key/0.4364));
      // rescale value (vertical) axis to fit the current data:
      //ui->widget->graph(0)->rescaleValueAxis();
      //ui->widget->graph(1)->rescaleValueAxis(true);
      lastPointKey = key;
    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->cpuHistory->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->cpuHistory->replot();
}

void MainWindow::realtimeDataSlot2(){

    static QTime time(QTime::currentTime());
    // calculate two new data points:
    double key = time.elapsed()/1000.0; // time elapsed since start of demo, in seconds
    static double lastPointKey = 0;
    if (key-lastPointKey > 0.002) // at most add point every 2 ms
    {
      lastPointKey = key;

      memory.readMemory();

      double t = memory.getTotalMemory();
      double u = memory.getUsedMemory();

      ui->memoryHistory->graph(0)->addData(key, (u/t)*100);

    }
    // make key axis range scroll with the data (at a constant range size of 8):
    ui->memoryHistory->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->memoryHistory->replot();
}

