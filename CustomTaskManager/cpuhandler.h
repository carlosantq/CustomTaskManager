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

private:
    int numberOfCPU;
};

#endif // CPUHANDLER_H
