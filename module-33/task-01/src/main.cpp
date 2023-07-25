#include <iostream>
#include "trash.h"

int main(int, char**){

    Trash trash;

    try
    {
        trash.add("apple", 100);
        trash.del("apple", 40000);
    }
    catch (std::invalid_argument& ia)
    {
        std::cerr<<"Invalid argument supplied: " << ia.what() << std::endl;
    }
    catch (std::runtime_error& re)
    {
         std::cerr<<"Full error!" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknow error" << std::endl;
    }
}
