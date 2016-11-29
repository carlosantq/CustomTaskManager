#ifndef PROCESSHANDLER_H
#define PROCESSHANDLER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

#include "process.h"
#include "operationtype.h"

using namespace std;

class ProcessHandler{

private:
    vector< vector<string> > parseProcessFile(string path);
    vector<Process> generateData();

    void generateFirstProcessesStructure();
    void cleanArbitraryFiles();
    void deleteLinesOfFile(string file, int times, string location);
    //void generateJson(OperationType operationtype);
    void generatePsDataAcquisition();
    void rmFilesWithSomeExtension(string extension);

public:

    ProcessHandler();
    void generateJson(OperationType operationtype);
};



#endif // ProcessHandler_H
