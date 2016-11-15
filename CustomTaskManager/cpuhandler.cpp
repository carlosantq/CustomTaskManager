#include "cpuhandler.h"

CPUHandler::CPUHandler()
{
    srand(time(NULL));
    this->color1=rand()%255;
    this->color2=rand()%255;
    this->color3=rand()%255;
}

void CPUHandler::randomColors(){
    this->color1=rand()%255;
    this->color2=rand()%255;
    this->color3=rand()%255;
}

int CPUHandler::getColor1(){
    return this->color1;
}

int CPUHandler::getColor2(){
    return this->color2;
}

int CPUHandler::getColor3(){
    return this->color3;
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
