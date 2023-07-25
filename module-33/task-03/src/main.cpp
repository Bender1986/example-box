#include <iostream>
#include <vector>
#include "registry.h"

int main(int, char**){
    
    Registry<int, std::string> reg;
      
    RegistryKeyValue<int, std::string> key_value1 = {1, "test1"};
    RegistryKeyValue<int, std::string> key_value2 = {2, "test2"};
    RegistryKeyValue<int, std::string> key_value3 = {3, "test3"};
    
    reg.add(key_value1);
    reg.add(key_value2);
    reg.add(key_value3);
       
    
    reg.print();

    try
    {
        reg.find(1);

        reg.find(5);
    }
    catch (std::exception& x)
    {
        std::cout<< x.what() << std::endl;
    }

    reg.remove(1);
}
