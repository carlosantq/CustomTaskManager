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

int MemoryHandler::getUsedSwap(){
    return this->usedSwap;
}

int MemoryHandler::getTotalSwap(){
    return this->totalSwap;
}

void MemoryHandler::readMemory(){
    std::ifstream memoryFile;
    std::string memoryInfo;
    //ATTENTION: uncomment this and put your build directory/mem.txt
    //system("free -m > xxxxx");
    //ATTENTION: change to your build directory
    memoryFile.open("/Users/carlosant/Downloads/CustomTaskManager/build-CustomTaskManager-Desktop_Qt_5_7_0_clang_64bit-Debug/mem.txt");

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
    this->usedSwap=(atoi(memoryInfo.c_str()));
}
