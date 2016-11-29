#include "processhandler.h"

using namespace std;

ProcessHandler::ProcessHandler(){

}

// Only with awk
void ProcessHandler::generateFirstProcessesStructure(){
    system("awk -F \":\t\" '/^Pid:/ {print $2}' /proc/*/status > pida.txt");
    system("awk -F \":\t\" '/^Name:/ {print $2}' /proc/*/status > names.txt");
    system("awk -F \":\t\" '/^Threads:/ {print $2}' /proc/*/status > threads.txt");
    system("paste -d '  ' pida.txt names.txt threads.txt > temp.txt && sort -nk 1 temp.txt >> output1.txt");
}

void ProcessHandler::cleanArbitraryFiles(){
    system("rm *.txt");
}

void ProcessHandler::deleteLinesOfFile(string file, int times, string location){
    for(int i = 0; i < times; ++i){
        string query = "sed '" + location + "d' " + file + " > tempfile.txt && cat tempfile.txt > " + file + " && rm tempfile.txt";
        system(query.c_str());
    }
}

// Only with ps
void ProcessHandler::generatePsDataAcquisition(){
    system("ps -eo pid > temp.txt && tr -d ' \t' < temp.txt > pidb.txt && rm temp.txt");
    system("ps -eo %mem > temp.txt && tr -d ' \t' < temp.txt >  mem.txt && rm temp.txt");
    system("ps -eo %cpu > temp.txt && tr -d ' \t' < temp.txt >  cpu.txt && rm temp.txt");
    system("ps -eo ppid > temp.txt && tr -d ' \t' < temp.txt >  ppid.txt && rm temp.txt");
}

void ProcessHandler::rmFilesWithSomeExtension(string extension){
    string query = "rm *." + extension;
    system(query.c_str());
}

vector<Process> ProcessHandler::generateData(){
    rmFilesWithSomeExtension("data");

    generateFirstProcessesStructure();
    deleteLinesOfFile("output1.txt", 4, "$");

    generatePsDataAcquisition();

    system("paste -d '   ' pidb.txt mem.txt cpu.txt ppid.txt >> output2.txt");
    deleteLinesOfFile("output2.txt", 1, "1");
    deleteLinesOfFile("output2.txt", 2, "$");

    system("paste -d ' ' output2.txt output1.txt >> output.data");
    deleteLinesOfFile("output2.txt", 1, "$");

    rmFilesWithSomeExtension("txt");

    vector<vector<string>> rawProcess = parseProcessFile("output.data");
    vector<Process> processes;

    for(int i = 0; i < rawProcess.size(); i++){
        vector<string> process = rawProcess[i];
        if(process.size() == 7){
            if(process[0] == process[4]){
                std::string::size_type sz;
                processes.push_back(Process(stoi(process[0], &sz), process[5], stod(process[1], &sz), stod(process[2], &sz), stoi(process[3], &sz), stoi(process[6], &sz)));
            }
        }
    }

    for(int i = 0; i < processes.size(); i++){
        for(int j = i; j < processes.size(); j++){
            if(processes[i].getId() == processes[j].getPpid()){
                processes[i].addChidren(processes[j]);
                break;
            }
        }
    }

    return processes;
}

void ProcessHandler::generateJson(OperationType operationtype){
    vector<Process> processes = generateData();

    string header =  "{\n ";
           header += " \"name\": \"processes\", \n";
           header += " \"children\": \n";
           header += " [\n";

    string jsonClose = " ]\n}";
    string content = "";

    for(int i = 0; i < processes.size(); i++){
        Process p = processes[i];

        if(i == processes.size()-1)
            content+=p.getJson(operationtype)+"\n";
        else
            content+=p.getJson(operationtype)+",\n";
    }

    string jsonCompleto = header + content + jsonClose;

    ofstream out;
    out.open("processes.json");
    out << jsonCompleto << endl;
    out.close();
}

vector<vector<string>> ProcessHandler::parseProcessFile(string path){

    vector<vector<string>> rawProcess;
    ifstream ifPid (path, ifstream::in);
    char c = ifPid.get();
    string aux = "";

    while (ifPid.good()) {
        if(c!='\n'){
            aux = aux + c;
        } else {
            stringstream ss(aux);
            string item;
            vector<string> processData;
            while (getline(ss, item, ' ')) {
                processData.push_back(item);
            }

            rawProcess.push_back(processData);
            aux = "";
        }

        c = ifPid.get();
    }
    ifPid.close();
    return rawProcess;
}
