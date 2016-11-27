#include "batteryhandler.h"

BatteryHandler::BatteryHandler()
{
    this->charge = 0;
    this->discharge = 0;
    this->status = "Discharging";
}

double BatteryHandler::getCharge(){
    return this->charge;
}

double BatteryHandler::getDischarge(){
    return this->discharge;
}

QString BatteryHandler::getStatus(){
    return this->status;
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
        }else if (line.mid(0, 20) == "POWER_SUPPLY_STATUS="){
            this->status = line.mid(20, line.length());
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
            }else if (line.mid(0, 20) == "POWER_SUPPLY_STATUS="){
                this->status = line.mid(20, line.length());
            }
        }

        if (this->status == "Charging"){
            this->discharge = double (pschf-pschn)/pscn;
            this->discharge*=60;
        }else if (this->status == "Full"){
            this->discharge =  0;
        }else{
            this->discharge = double (pschn)/pscn;
            this->discharge*=60;
        }

        this->charge = double (pschn)/pschf;

        returnInformation = true;
    }else{
        returnInformation = false;
    }

    return returnInformation;
}
