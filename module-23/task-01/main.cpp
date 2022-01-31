#include <iostream>

#define MONTHDAY    "Monthday"
#define TUESDAY     "Tuesday"
#define WEDNESDAY   "Wednesday"
#define THURSDAY    "Thursday"
#define FRIDAY      "FRIDAY"
#define SATURDAY    "Saturday"
#define SUNDAY      "Sunday"

using namespace std;

int main() {

cout<<"Task1. Days of the week"<<endl;

int day;

while (1)
{
    cout<<"Input number week (1-7 - week, any - exit):";
    

    switch (day)
    {
    case 1:
        cout<<MONTHDAY<<endl;
        break;

    case 2:
        cout<<TUESDAY<<endl;
        break;

    case 3:
        cout<<WEDNESDAY<<endl;
        break;

    case 4:
        cout<<THURSDAY<<endl;
        break;

    case 5:
        cout<<FRIDAY<<endl;
        break;

    case 6:
        cout<<SATURDAY<<endl;
        break;

    case 7:
        cout<<SUNDAY<<endl;
        break;


    
    default:
        return 0;
        break;
    }
}


}