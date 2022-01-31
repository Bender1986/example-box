#include <iostream>

#define MAX 20
#define SIZE 10

#define CHECK(name, make) name ## _ ## make

#define IDX i
#define REPEAT int i = -1; while (++i < SIZE)


using namespace std;


void func_check(int a[])
{
   int count = 0;  

   REPEAT
   {
       count += a[IDX];

       if (a[IDX] == 0)
       {
           cout<<"Wagon #"<<IDX<<" is empty"<<endl;
       }

       if (a[IDX] >  MAX)
       {
           cout<<"Wagon #"<<IDX<<" is overflown"<<endl;
       }
   }   
   
   cout<<"Count people is "<<count<<endl;   
}




int main() {

cout<<"Task2. Analizing of the train"<<endl;

int wagons[10] = {3, 21, 15, 14, 30, 10, 0, 11, 12, 10};

CHECK(func, check)(wagons);


}