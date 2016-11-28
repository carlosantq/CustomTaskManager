#include "process.h"

using namespace std;

Process::Process(){

}

Process::Process(int id, string name, double mem, double cpu, int ppid, int threads){
    this->id = id;
    this->name = name;
    this->mem = mem;
    this->cpu = cpu;
    this->ppid = ppid;
    this->threads = threads;
}


void Process::setId(int id){
    this->id = id;
}

int Process::getId(){
    return this->id;
}

void Process::setName(string name){
    this->name = name;
}

string Process::getName(){
    return this->name;
}

void Process::setMem(double mem){
    this->mem = mem;
}

double Process::getMem(){
    return this->mem;
}

void Process::setCpu(double cpu){
    this->cpu = cpu;
}

double Process::getCpu(){
    return this->cpu;
}

void Process::setPpid(int ppid){
    this->ppid = ppid;
}

int Process::getPpid(){
    return this->ppid;
}

void Process::setThreads(int threads){
    this->threads = threads;
}

int Process::getThreads(){
    return this->threads;
}

void Process::addChidren(Process processChildren){
    this->childrens.push_back(processChildren);
}

vector<Process> Process::getChildrens(){
    return this->childrens;
}

int Process::getNumChidrens(){
    return this->childrens.size();
}

string Process::getJson(OperationType operationtype){
    string json = "  {\n";
    json += "    \"name\": \""+this->getName()+"\",\n";
    json += "    \"children\":\n";
    json += "    [\n";
    for(int i = 0; i < this->getChildrens().size(); i++){
        Process p = this->getChildrens()[i];

        string text;
        switch (operationtype) {
        case CPU:
            text = to_string((int) ((p.getCpu()+1)*(p.getCpu()+1)*10));
            break;
        case MEM:
            text = to_string((int) ((p.getMem()+1)*(p.getMem()+1)*10));
            break;
        case THREAD:
            text = to_string(p.getThreads()*p.getThreads()*2);
            break;
        case GOURMET:
            text = to_string((int) ((p.getCpu()+1)*p.getThreads()*(p.getMem()+1)));
            break;
        default:
            text = to_string((int) ((p.getCpu()+1)*(p.getCpu()+1)*10));
            break;
        }

        if(i == this->getChildrens().size()-1)
            json+= "      {\"name\": \""+p.getName()+"\", \"size\": "+text+", \"pid\": "+to_string(p.getId())+"}\n";
        else
            json+= "      {\"name\": \""+p.getName()+"\", \"size\": "+text+", \"pid\": "+to_string(p.getId())+"},\n";
    }
    json += "    ]\n";
    json +="  }";

    return json;
}
