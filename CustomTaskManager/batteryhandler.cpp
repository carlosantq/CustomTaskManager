#include "batteryhandler.h"

BatteryHandler::BatteryHandler()
{

    this->discharge = 0;
}

double BatteryHandler::getCharge(){
    return this->charge;
}

double BatteryHandler::getDischarge(){
    return this->discharge;
}

bool BatteryHandler::readBattery(){
    int pscn = 1;
    int pschf = 1;
    int pschn = 1;
    bool returnInformation = false;

    //Teste /Users/carlosant/Documents/battery.txt
    //Real /sys/class/power_supply/BAT0/uevent
    QFile batteryInfo("/sys/class/power_supply/BAT0/uevent");

    if (batteryInfo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&batteryInfo);

        QString line = in.readLine();

        if (line.mid(0,25) == "POWER_SUPPLY_CURRENT_NOW=" || line.mid(0,25) == "POWER_SUPPLY_POWER_NOW="){
            pscn = line.mid(25, line.length()).toInt();
        }else if (line.mid(0, 25) == "POWER_SUPPLY_CHARGE_FULL=" || line.mid(0,25) == "POWER_SUPPLY_ENERGY_NOW="){
            pschf = line.mid(25, line.length()).toInt();
        }else if (line.mid(0, 24) == "POWER_SUPPLY_CHARGE_NOW=" || line.mid(0, 24) == "POWER_SUPPLY_ENERGY_NOW="){
            pschn = line.mid(24, line.length()).toInt();
        }

        while (!line.isNull()){
            line = in.readLine();
            if (line.mid(0,25) == "POWER_SUPPLY_CURRENT_NOW="){
                pscn = line.mid(25, line.length()).toInt();
            }else if (line.mid(0,23) == "POWER_SUPPLY_POWER_NOW="){
                pscn = line.mid(23, line.length()).toInt();
            }else if (line.mid(0, 25) == "POWER_SUPPLY_CHARGE_FULL=" || line.mid(0,25) == "POWER_SUPPLY_ENERGY_FULL="){
                pschf = line.mid(25, line.length()).toInt();
            }else if (line.mid(0, 24) == "POWER_SUPPLY_CHARGE_NOW=" || line.mid(0, 24) == "POWER_SUPPLY_ENERGY_NOW="){
                pschn = line.mid(24, line.length()).toInt();
            }
        }

        this->discharge = double (pschf-pschn)/pscn;
        this->discharge*=60;

        this->charge = double (pschn)/pschf;

        returnInformation = true;
    }else{
        returnInformation = false;
    }

    return returnInformation;
}
