#include <fstream>
#include "disk.h"


bool Disk::save(const Ram &ram) {
    
    std::ofstream file("disk.txt");

    int buf[8];

    ram.read(buf);

    for(const auto &it: buf){

        file << it<<std::endl;
    }

    file.close();

    return true;
}


bool Disk::load(Ram &ram) {
    
    std::ifstream file;

    file.open("disk.txt");
    
    while (!file.eof()) {
        
        file >> ram.write();
    }
    
    
    file.close();

    return true;
}


