#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resourcesChart();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resourcesChart(){
    int i = 0;
    int n = cpu.getNumberOfCPU();

    ui->widget->legend->setVisible(true);

    while (i < n){
        ui->widget->addGraph(); // blue line
        ui->widget->graph(i)->setPen(QPen(QColor(gh.getColor1(), gh.getColor2(), gh.getColor3())));

        QString name = QString("CPU %1").arg(i);
        ui->widget->graph(i)->setName(name);

        gh.randomColors();

        i++;
    }

    QSharedPointer<QCPAxisTickerTime> timeTicker(new QCPAxisTickerTime);
    timeTicker->setTimeFormat("%h:%m:%s");
    ui->widget->xAxis->setTicker(timeTicker);
    ui->widget->axisRect()->setupFullAxesBox();
    ui->widget->yAxis->setRange(-1, 1);

    // make left and bottom axes transfer their ranges to right and top axes:
    connect(ui->widget->xAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui->widget->yAxis, SIGNAL(rangeChanged(QCPRange)), ui->widget->yAxis2, SLOT(setRange(QCPRange)));

    // setup a timer that repeatedly calls MainWindow::realtimeDataSlot:
    connect(&dataTimer, SIGNAL(timeout()), this, SLOT(realtimeDataSlot()));
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
          ui->widget->graph(i)->addData(key, qSin(key)+qrand()/(double)RAND_MAX*1*qSin(key/0.385));
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
    ui->widget->xAxis->setRange(key, 8, Qt::AlignRight);
    ui->widget->replot();
}

