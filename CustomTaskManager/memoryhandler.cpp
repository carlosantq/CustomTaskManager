#include "memoryhandler.h"

MemoryHandler::MemoryHandler()
{
    this->usedMemory = 0;
    this->totalMemory = 0;
    this->usedSwap = 0;
    this->totalSwap = 0;
}

int MemoryHandler::getUsedMemory(){
    return this->usedMemory;
}

int MemoryHandler::getTotalMemory(){
    return this->totalMemory;
}

int MemoryHandler::getUsedSwap(){
    return this->usedSwap;
}

int MemoryHandler::getTotalSwap(){
    return this->totalSwap;
}

void MemoryHandler::readMemory(){
    //ATTENTION: uncomment this and put your build directory/mem.txt after the >
    system("free -m > /home/murilao/Documents/SO/cpps/u2/ProjetoVersaoFinal/CustomTaskManager/mem.txt");
    //ATTENTION: change to your build directory
    std::ifstream memoryFile("/home/murilao/Documents/SO/cpps/u2/ProjetoVersaoFinal/CustomTaskManager/mem.txt");
    std::string memoryInfo;

    if (memoryFile.is_open() == true){
        //RAM
        memoryFile >> memoryInfo;
        while (memoryInfo != "Mem:"){
            memoryFile >> memoryInfo;
        }

        memoryFile >> memoryInfo;
        this->totalMemory=(atoi(memoryInfo.c_str()));
        memoryFile >> memoryInfo;
        this->usedMemory=(atoi(memoryInfo.c_str()));

        //Swap
        memoryFile >> memoryInfo;
        while (memoryInfo != "Swap:"){
            memoryFile >> memoryInfo;
        }

        memoryFile >> memoryInfo;
        this->totalSwap=(atoi(memoryInfo.c_str()));
        memoryFile >> memoryInfo;
        this->usedSwap=(atoi(memoryInfo.c_str()));
    }
}
