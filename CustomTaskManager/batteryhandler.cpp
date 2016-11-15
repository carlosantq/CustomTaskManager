#include "batteryhandler.h"

BatteryHandler::BatteryHandler()
{

}

int BatteryHandler::getCharge(){
    return this->charge;
}

double BatteryHandler::getDischarge(){
    return this->discharge;
}

bool BatteryHandler::readBattery(){
    int pscn = 0;
    int pschf = 0;
    int pschn = 0;
    QString teste;
    bool returnInformation = false;

    //Teste /Users/carlosant/Documents/battery.txt
    //Real /sys/class/power_supply/BAT0/uevent
    QFile batteryInfo("/Users/carlosant/Documents/battery.txt");

    if (batteryInfo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&batteryInfo);

        QString line = in.readLine();

        if (line.mid(0,25) == "POWER_SUPPLY_CURRENT_NOW="){
            pscn = line.mid(25, line.length()).toInt();
        }else if (line.mid(0, 25) == "POWER_SUPPLY_CHARGE_FULL="){
            pschf = line.mid(25, line.length()).toInt();
        }else if (line.mid(0, 24) == "POWER_SUPPLY_CHARGE_NOW="){
            pschn = line.mid(24, line.length()).toInt();
        }

        while (!line.isNull()){
            line = in.readLine();
            if (line.mid(0,25) == "POWER_SUPPLY_CURRENT_NOW="){
                pscn = line.mid(25, line.length()).toInt();
            }else if (line.mid(0, 25) == "POWER_SUPPLY_CHARGE_FULL="){
                pschf = line.mid(25, line.length()).toInt();
            }else if (line.mid(0, 24) == "POWER_SUPPLY_CHARGE_NOW="){
                pschn = line.mid(24, line.length()).toInt();
            }
        }

        std::cout << pscn << std::endl;
        std::cout << pschf << std::endl;
        std::cout << pschn << std::endl;

        this->discharge = double (pschf-pschn)/pscn;
        this->discharge*=60;

        //std::cout << this->discharge << std::endl;

        returnInformation = true;
    }else{
        returnInformation = false;
    }

    return returnInformation;
}
