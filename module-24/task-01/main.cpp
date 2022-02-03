#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

enum Status
{
    ACTIVE = 1,
    COMPLETED = 2
};

struct Item
{
    time_t dateBeg;
    time_t dateEnd;

    Status status;
};


string Time(const time_t &t)
{
    string time;

    time = ":" + to_string(t % 60);

    time = ":" + to_string((t / 60) % 60) + time;

    time = to_string(t / 3600) + time;
    

    return time;
}


int main() {

cout<<"Task1. Task account"<<endl;

map<string, Item> taskAccount;

string command;

string taskName;
string taskCurr = "";

while (1) {

    cout<<"Input command (begin - new task, end - off current task, status -  info tasks, exit - quit from this program): \n";
    cin >> command;

    /* Exit this program */
    if (command == "exit") {
        break;
    }

    /* Init new task  */ 
    if (command == "begin") {
        
        cout<<"Input name task: ";
        cin >> taskName;
        
        auto it = taskAccount.insert(pair<string, Item>(taskName, {.dateBeg = time(nullptr), .status = Status::ACTIVE}));
        
        if (!it.second) {
           cout<<"This task is exist!"<<endl;
        }
        else {            
                /* Complete this current task */
                if (taskCurr != "") {
                    auto itFind = taskAccount.find(taskCurr);
                    
                    if (itFind != taskAccount.end()) {

                        itFind->second.dateEnd = time(nullptr);
                        itFind->second.status = Status::COMPLETED;
                    }                       
                }  
            
            taskCurr = it.first->first;
        }
        
        continue;
    }


    /* Current task is COMPLETED */
    if (command == "end") {
       /* Complete this current task */
        if (taskCurr != "") {
            auto itFind = taskAccount.find(taskCurr);
            
            if (itFind != taskAccount.end()) {

                itFind->second.dateEnd = time(nullptr);
                itFind->second.status = Status::COMPLETED;
            }                       
        } 

        continue; 
    }


    /* Info from tasks */ 
    if (command == "info")  {
        cout<<left<<setw(10)<<"Name:"; 
        cout<<setw(30)<<"Time exicute(h:m:s):"; 
        cout<<setw(10)<<"Status:";
        cout<<endl;
        
        for (const auto& it: taskAccount) {
            
            string str_dif = "n/a";
            
            if (it.second.status == Status::COMPLETED) {
                double d = difftime(it.second.dateEnd, it.second.dateBeg);
                time_t t = static_cast<time_t>(d);
                str_dif = Time(t);
            }
            
            cout<<setw(10)<<left<<it.first;
            cout<<setw(30)<<str_dif;
            cout<<setw(10)<<(it.second.status == Status::ACTIVE ? "ACTIVE" : "COMPLETED")<<endl;
        }

        continue;
    }


    /* Not support */ 
    cout<<"This command not supported :("<<endl;
}



}