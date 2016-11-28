#include "processhandler.h"

using namespace std;

ProcessHandler::ProcessHandler(){

}

vector<Process> ProcessHandler::generateData(){
    system("rm *.data");

    system("awk -F \":\t\" '/^Pid:/ {print $2}' /proc/*/status > pid1.txt");
    system("awk -F \":\t\" '/^Name:/ {print $2}' /proc/*/status > names.txt");
    system("awk -F \":\t\" '/^Threads:/ {print $2}' /proc/*/status > threads.txt");
    system("paste -d '  ' pid1.txt names.txt threads.txt > temp.txt && sort -nk 1 temp.txt >> saida1.txt");

    for(int i = 0; i < 4; i++){
        system("sed '$d' saida1.txt > temp.txt && cat temp.txt > saida1.txt && rm temp.txt");
    }

    system("ps -eo pid > temp.txt && tr -d ' \t' < temp.txt > pid2.txt && rm temp.txt");
    system("ps -eo %mem > temp.txt && tr -d ' \t' < temp.txt >  mem.txt && rm temp.txt");
    system("ps -eo %cpu > temp.txt && tr -d ' \t' < temp.txt >  cpu.txt && rm temp.txt");
    system("ps -eo ppid > temp.txt && tr -d ' \t' < temp.txt >  ppid.txt && rm temp.txt");

    system("paste -d '   ' pid2.txt mem.txt cpu.txt ppid.txt >> saida2.txt");

    system("sed '1d' saida2.txt > temp.txt && cat temp.txt > saida2.txt && rm temp.txt");
    system("sed '$d' saida2.txt > temp.txt && cat temp.txt > saida2.txt && rm temp.txt");
    system("sed '$d' saida2.txt > temp.txt && cat temp.txt > saida2.txt && rm temp.txt");

    system("paste -d ' ' saida2.txt saida1.txt >> saida.data");
    system("sed '$d' saida.data > temp.txt && cat temp.txt > saida.data && rm temp.txt");
    system("rm *.txt");

    vector<vector<string>> listProcess = parseProcessFile("saida.data");
    vector<Process> processos;

    for(int i = 0; i < listProcess.size(); i++){
        vector<string> process = listProcess[i];
        if(process.size() == 7){
            if(process[0] != process[4]){
                // ERROR. Ignore it.
            }else{
                std::string::size_type sz;
                processos.push_back(Process(stoi(process[0], &sz), process[5], stod(process[1], &sz), stod(process[2], &sz), stoi(process[3], &sz), stoi(process[6], &sz)));
            }
        }else{
            // ERROR. Ignore it.
        }
    }

    for(int i = 0; i < processos.size(); i++){
        for(int j = i; j < processos.size(); j++){
            if(processos[i].getId() == processos[j].getPpid()){
                processos[i].addChidren(processos[j]);
            }
        }
    }

    return processos;
}

void ProcessHandler::generateJson(OperationType operationtype){
    vector<Process> processos = generateData();

    string init =  "{\n ";
           init += " \"name\": \"processos\", \n";
           init += " \"children\": \n";
           init += " [\n";

    string end = " ]\n}";

    string mid = "";

    for(int i = 0; i < processos.size(); i++){
        Process p = processos[i];

        if(i == processos.size()-1)
            mid+=p.getJson(operationtype)+"\n";
        else
            mid+=p.getJson(operationtype)+",\n";
    }

    string jsonCompleto = init + mid + end;

    ofstream out;
    out.open("processes.json");
    out << jsonCompleto << endl;
    out.close();
}

vector<vector<string>> ProcessHandler::parseProcessFile(string path){

    ifstream ifPid (path, ifstream::in);
    char c = ifPid.get();
    string ids = "";

    vector<vector<string>> listProcess;

    while (ifPid.good()) {
        if(c=='\n'){
            stringstream ss(ids);
            string item;
            vector<string> processData;
            while (getline(ss, item, ' ')) {
                processData.push_back(item);
            }

            listProcess.push_back(processData);
            ids = "";
        }else{
            ids = ids + c;
        }
        c = ifPid.get();
    }
    ifPid.close();
    return listProcess;
}
