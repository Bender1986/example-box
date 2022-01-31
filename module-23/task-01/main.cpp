#include <iostream>

#define DAY_1  "Monthday"
#define DAY_2  "Tuesday"
#define DAY_3  "Wednesday"
#define DAY_4  "Thursday"
#define DAY_5  "FRIDAY"
#define DAY_6  "Saturday"
#define DAY_7  "Sunday"

#define DAY(n1, n2) n1 ## _ ## n2


using namespace std;

int main() {

cout<<"Task1. Days of the week"<<endl;

int day{0};

while (1)
{
    cout<<"Input number week (1-7 - week, any - exit):";
    cin >> day;
    
    switch (day)
    {
    case 1:
        cout<<DAY(DAY, 1)<<endl;
        break;

    case 2:
        cout<<DAY(DAY, 2)<<endl;
        break;

    case 3:
        cout<<DAY(DAY, 3)<<endl;
        break;

    case 4:
        cout<<DAY(DAY, 4)<<endl;
        break;

    case 5:
        cout<<DAY(DAY, 5)<<endl;
        break;

    case 6:
        cout<<DAY(DAY, 6)<<endl;
        break;

    case 7:
        cout<<DAY(DAY, 7)<<endl;
        break;

    
    default:
        return 0;
        break;
    }
}


}