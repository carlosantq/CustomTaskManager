#ifndef MEMORYHANDLER_H
#define MEMORYHANDLER_H


#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <fstream>

class MemoryHandler
{
public:
    MemoryHandler();
    int getUsedMemory();
    int getTotalMemory();
    int getUsedSwap();
    int getTotalSwap();
    void readMemory();
private:
    int usedMemory;
    int totalMemory;
    int usedSwap;
    int totalSwap;
};

#endif // MEMORYHANDLER_H
