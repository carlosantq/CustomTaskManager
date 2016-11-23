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
    // /proc/stat
    //Teste /Users/carlosant/Documents/cpup.txt
    QFile cpuInfo("/Users/carlosant/Documents/arquivo.txt");

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

QVector<double> CPUHandler::getUsage()
{
    QVector<double> usagePerCPU(this->numberOfCPU, 0);

    std::ifstream usageInfo;
    std::string usage;
    std::string::size_type sz;
    int i = 0;
    //ATTENTION: uncomment this and put your build directory/mem.txt after the >
    //system("mpstat -P ALL 1 > xxxxx");
    //ATTENTION: change to your build directory
    usageInfo.open("/Users/carlosant/Documents/cpup.txt");

    usageInfo >> usage;

    while (usage != std::to_string(i) && i<this->numberOfCPU){
        usageInfo >> usage;
        if (usage == std::to_string(i)){
            for (int j=0; j<8; j++){
                usageInfo >> usage;
                usagePerCPU[i] += std::stod(usage, &sz);
            }
            i++;
        }
    }

    return usagePerCPU;
}
