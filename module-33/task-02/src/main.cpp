#include <iostream>
#include "fish.h"


int main(int, char**){

    Fish fish; 

    try
    {
        fish.take(7);
    }   
    catch (std::invalid_argument& x)
    {
        std::cerr<<"Invalid argument: " << x.what() << std::endl;
    }
    catch(int code)
    {
        if (code == 1)
        {
            std::cout<< "This fish is found" << std::endl;
        }
        if (code == 0)
        {
            std::cout<< "This empty" << std::endl;
        }
        if (code == -1)
        {
            std::cout<< "This boot is found" << std::endl;
        }
    } 
}
