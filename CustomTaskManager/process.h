#ifndef PROCESS_H
#define PROCESS_H

#include <vector>
#include <iostream>

#include "operationtype.h"

using namespace std;

class Process{
private:
    int id;
    string name;
    double mem;
    double cpu;
    int ppid;
    int threads;

    vector<Process> children;

public:
    Process();
    Process(int id, string name, double mem, double cpu, int ppid, int threads);

    void addChidren(Process);
    vector<Process> getChildren();
    int getNumChidrens();

    string getJson(OperationType operationtype);

    void setId(int id);
    int getId();
    void setName(string name);
    string getName();
    void setMem(double mem);
    double getMem();
    void setCpu(double cpu);
    double getCpu();
    void setPpid(int ppid);
    int getPpid();
    void setThreads(int threads);
    int getThreads();
};

#endif // Process_H
