#include "memoryhandler.h"

MemoryHandler::MemoryHandler()
{
}

int MemoryHandler::getUsedMemory(){
    return this->usedMemory;
}

int MemoryHandler::getTotalMemory(){
    return this->totalMemory;
}

void MemoryHandler::setUsedMemory(int usedMemory){
    this->usedMemory = usedMemory;
}

void MemoryHandler::setTotalMemory(int totalMemory){
    this->totalMemory = totalMemory;
}

void MemoryHandler::readMemory(){
    std::ifstream memoryFile;
    std::string memoryInfo;
    //system("free -m > xxxxx");
    memoryFile.open("/Users/carlosant/Downloads/CustomTaskManager/build-CustomTaskManager-Desktop_Qt_5_7_0_clang_64bit-Debug/mem.txt");
    //Memória
    for (int j = 0; j<7; j++) {
        memoryFile >> memoryInfo;
    }
    memoryFile >> memoryInfo;
    this->totalMemory=(atoi(memoryInfo.c_str()));
    memoryFile >> memoryInfo;
    this->usedMemory=(atoi(memoryInfo.c_str()));

    //std::cout << this->usedMemory << std::endl;
    //std::cout << this->totalMemory << std::endl;
}
