#ifndef CPUHANDLER_H
#define CPUHANDLER_H

#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include <QVector>
#include <QStringList>

class CPUHandler
{
public:
    CPUHandler();
    bool openFile();
    int getNumberOfCPU();
    void randomColors();
    int getColor1();
    int getColor2();
    int getColor3();
    QVector<double> getUsage();

private:
    void setNumberOfCPU();
    QFile cpuInfo;
    int numberOfCPU;
    int color1;
    int color2;
    int color3;
    QVector<double> previousUsage;
    QVector<double> currentUsage;
    QVector<double> totalUsage;
};

#endif // CPUHANDLER_H
