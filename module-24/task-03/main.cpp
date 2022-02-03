#include <iostream>
#include <ctime>

using namespace std;


int main() {

int min;
int sec;

cout<<"Input begin time (min sec): \n";
cin >> min;
cin >> sec;

const int difMax = min * 60 + sec;

int difCur = 0;
int difTmp = 0;

time_t t_begin = time(nullptr);

cout<<"Timer start!"<<endl;

while (difCur < difMax) {
    difCur =  difftime(time(nullptr), t_begin);
    
    /* Print current timer */
    if (difCur - difTmp > 0) {
        cout<<"min: " << difCur / 60 <<" sec: "<< difCur % 60<<endl;
    }

    difTmp = difCur;
}

cout<<"DING! DING! DING!";


}