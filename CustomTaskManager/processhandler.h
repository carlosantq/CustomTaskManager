#ifndef PROCESSHANDLER_H
#define PROCESSHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

#include "process.h"
#include "operationtype.h"

using namespace std;

class ProcessHandler{

private:
    vector< vector<string> > parseProcessFile(string path);
    vector<Process> generateData();

public:

    ProcessHandler();
    void generateJson(OperationType operationtype);
};



#endif // ProcessHandler_H
