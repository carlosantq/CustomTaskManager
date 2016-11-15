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
    void setUsedMemory(int usedMemory);
    void setTotalMemory(int totalMemory);
    void readMemory();
private:
    int usedMemory;
    int totalMemory;
};

#endif // MEMORYHANDLER_H
