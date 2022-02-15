#include <iostream>
#include "kbd.h"


bool Kbd::input(Ram &ram) {

    int val = 0;

    for (int i = 0; i < 8; i++) {
        std::cout << "Input number: ";
        std::cin >> val; 

        if (!std::cin.fail()) {        
            ram.write(val);
        }                  
    }    

    return true;
}
