#include "cpuhandler.h"

CPUHandler::CPUHandler()
{
}

bool CPUHandler::defineNumberOfCPU()
{
    int cont = 0;
    bool returnInformation = false;

    //Teste /Users/carlosant/Documents/arquivo.txt
    QFile cpuInfo("/proc/stat");

    if (cpuInfo.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream in(&cpuInfo);

        QString line = in.readLine();
        if (line.mid(0, 3) == "cpu"){
            ++cont;
        }

        while (!line.isNull()){
            line = in.readLine();
            //std::cout << "Linha: ";
            //qDebug() << line.mid(0, 3);
            if (line.mid(0, 3) == "cpu"){
                ++cont;
            }
        }

        cont-=1;
        this->numberOfCPU=cont;

        returnInformation = true;
    }else{
        returnInformation = false;
    }

    return returnInformation;
}

int CPUHandler::getNumberOfCPU()
{
    if (defineNumberOfCPU() == true){
        return this->numberOfCPU;
    }else{
        return 0;
    }
}
