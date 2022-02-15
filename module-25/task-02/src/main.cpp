#include <iostream>
#include "cpu.h"
#include "disk.h"
#include "ram.h"
#include "kbd.h"
#include "gpu.h"

int main(int, char**) {
    
    std::string command;

    Ram ram;
    Gpu gpu;
    Kbd Kbd;
    Disk disk;           

        
    while (command != "exit")
    {
        std::cout << " Input command (sum, save, load, input, display, exit): ";
        std::cin >> command;
    

        if (command == "exit")
          break;


        if (command == "input") {
            Kbd.input(ram);
        }


        if (command == "display") {
            gpu.display(ram);
        }


        if (command == "sum") {
            Cpu::compute(ram);
        }
        

        if (command == "save") {
            disk.save(ram);
        }

        if (command == "load") {

            ram.clear();

            disk.load(ram);
        }
        

    }
    
    

}
