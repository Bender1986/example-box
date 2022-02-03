#include <iostream>
#include <vector>
#include <map>
#include <ctime>
#include "LibDate.h"
#include <sstream>
#include <locale>
#include <iomanip>

using namespace std;

struct Item
{
    string name;
    time_t date;
};

int main() {

map<time_t, vector<string>> birthdayBook;

string name;
string strDate;
Date date;

while (1) {

    cout<<"Input name (exit - to quit this program): ";
    cin >> name;

    if (name == "exit")
       break;

    cout<<"Input birthday: ";
    cin >> strDate;

    /*Parser string date */
    istringstream ss(strDate);
    tm t = {};
    ss>>get_time(&t, "%Y/%m/%d");

    if (ss.fail()) {
        continue;
    }
    
    time_t loc = mktime(&t);


    /* Push item */
    auto it =  birthdayBook.find(loc);

    if (it == birthdayBook.end()) {
        birthdayBook[loc] = vector<string>{name};
    }
    else {
        it->second.push_back(name);        
    }
               
}

/* Print */
time_t curDateTime = time(nullptr);

tm* loc = localtime(&curDateTime);
loc->tm_min = 0;
loc->tm_hour =0;
loc->tm_sec = 0;
loc->tm_isdst = -1;

time_t curDate = mktime(loc); 


for (const auto &it: birthdayBook) {
  
  if (it.first < curDate) {
     cout<<"This names birthday completed: "<<endl;
     for (const auto &name: it.second) {
         cout<<name<<"\n";
     }
  }
  
  
  if (it.first == curDate) {
     
     cout<<"This names birthday now: "<<endl;
     for (const auto &name: it.second) {
         cout<<name<<"\n";
     }
  }


  if (it.first > curDate) {
     cout<<"This names birthday soon: "<<endl;
     for (const auto &name: it.second) {
         cout<<name<<"\n";
     }

     break;
  }

  

}



}