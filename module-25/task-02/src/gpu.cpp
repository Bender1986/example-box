#include <iostream>
#include "gpu.h"



void Gpu::display(const Ram &ram) {

    int buf[8];

    if (ram.read(buf)) {

        for(const auto &it: buf) {

            std::cout << it <<" ";
        }

       std::cout<<std::endl;
    }
}
