#ifndef CPUHANDLER_H
#define CPUHANDLER_H

#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>

class CPUHandler
{
public:
    CPUHandler();
    bool defineNumberOfCPU();
    int getNumberOfCPU();
    void randomColors();
    int getColor1();
    int getColor2();
    int getColor3();

private:
    int numberOfCPU;
    int color1;
    int color2;
    int color3;
};

#endif // CPUHANDLER_H
