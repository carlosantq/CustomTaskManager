#include "cpuhandler.h"

CPUHandler::CPUHandler()
{
    srand(time(NULL));
    this->color1=rand()%255;
    this->color2=rand()%255;
    this->color3=rand()%255;
    this->numberOfCPU = 0;
    setNumberOfCPU();
    this->previousUsage.resize(this->numberOfCPU*2);
    this->currentUsage.resize(this->numberOfCPU*2);
    this->totalUsage.resize(this->numberOfCPU);
    this->previousUsage.fill(0);
    this->currentUsage.fill(0);
    this->totalUsage.fill(0);
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

bool CPUHandler::openFile()
{
    bool returnInformation = false;
    // /proc/stat
    this->cpuInfo.setFileName("/proc/stat");

    if (this->cpuInfo.open(QIODevice::ReadOnly | QIODevice::Text)){
        returnInformation = true;
    }else{
        returnInformation = false;
    }

    return returnInformation;
}


void CPUHandler::setNumberOfCPU()
{
    int cont = 0;

    if (openFile() == true){
        QTextStream in(&this->cpuInfo);

        QString line = in.readLine();
        if (line.mid(0, 3) == "cpu"){
            ++cont;
        }

        while (!line.isNull()){
            line = in.readLine();
            if (line.mid(0, 3) == "cpu"){
                ++cont;
            }
        }

        cont-=1;
        this->numberOfCPU=cont;

        this->cpuInfo.close();
    }
}

int CPUHandler::getNumberOfCPU()
{
    return this->numberOfCPU;
}

//QVector<double> CPUHandler::getUsage()
//{
//    QVector<double> usagePerCPU(this->numberOfCPU, 0);

//    std::ifstream usageInfo;
//    std::string usage;
//    std::string::size_type sz;
//    int i = 0;
//    //ATTENTION: uncomment this and put your build directory/mem.txt after the >
//    //system("mpstat -P ALL 1 > xxxxx");
//    //ATTENTION: change to your build directory
//    usageInfo.open("/Users/carlosant/Documents/cpup.txt");

//    usageInfo >> usage;

//    while (usage != std::to_string(i) && i<this->numberOfCPU){
//        usageInfo >> usage;
//        if (usage == std::to_string(i)){
//            for (int j=0; j<8; j++){
//                usageInfo >> usage;
//                usagePerCPU[i] += std::stod(usage, &sz);
//            }
//            i++;
//        }
//    }

//    return usagePerCPU;
//}

QVector<double> CPUHandler::getUsage()
{
    if (openFile() == true){

        QTextStream in(&this->cpuInfo);
        QString line = in.readLine();
        int n = this->numberOfCPU;

//        std::cout << "Previous Usage: " << std::endl;
//        for (int i=0; i<this->previousUsage.size(); i++){
//            std::cout << previousUsage[0] << std::endl;
//        }
//        std::cout << "Current Usage: " << std::endl;
//        for (int i=0; i<this->currentUsage.size(); i++){
//            std::cout << currentUsage[0] << std::endl;
//        }

        for (int i=0; i<n; i++){
            line = in.readLine();
            QStringList cpuValues = line.split(" ");
            double user = cpuValues.at(1).toDouble();
            double nice = cpuValues.at(2).toDouble();
            double system = cpuValues.at(3).toDouble();
            double idle = cpuValues.at(4).toDouble();
            double iowait = cpuValues.at(5).toDouble();
            double softirq = cpuValues.at(7).toDouble();

            //qDebug() << "cpuValues: " << cpuValues;

            //25957

            this->currentUsage[i] = user + nice + system + softirq;
            this->currentUsage[i+n] = user + nice + system + softirq + idle + iowait;

            //usleep(50000);

            this->totalUsage[i] = (100*(this->currentUsage[i]-this->previousUsage[i]) / (this->currentUsage[i+n]-this->previousUsage[i+n]));
            qDebug() << i << ": " << totalUsage[i];

            this->previousUsage[i] = this->currentUsage[i];
            this->previousUsage[i+n] = this->currentUsage[i+n];
        }
        this->cpuInfo.close();
    }

    return this->totalUsage;
}
