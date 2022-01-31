#include <iostream>

#define WINTER


int main() {

std::cout<<"Task3. Season "<<std::endl;

#ifdef SPRING
    std::cout<<"Spring"<<std::endl;
#endif

#ifdef SUMMER
    std::cout<<"Summer"<<std::endl;
#endif


#ifdef AUTUMN
    std::cout<<"Autumn"<<std::endl;
#endif

#ifdef WINTER
    std::cout<<"Winter"<<std::endl;
#endif


}