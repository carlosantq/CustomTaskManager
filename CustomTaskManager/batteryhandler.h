#ifndef BATTERYHANDLER_H
#define BATTERYHANDLER_H

#include <QFile>
#include <iostream>
#include <QTextStream>
#include <QDebug>
#include <fstream>
#include <QString>

class BatteryHandler
{
public:
    BatteryHandler();
    double getCharge();
    double getDischarge();
    bool readBattery();
private:
    double charge;
    double discharge;
    QString teste;
};

#endif // BATTERYHANDLER_H
