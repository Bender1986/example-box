#include <iostream>
#include "cpu.h"

int Cpu::m_buf[];

const int Cpu::compute(const Ram &ram){
    
    ram.read(m_buf);

    int sum = 0;

    for (const auto &it: m_buf) {
        sum += it;
    }

    std::cout << "Sum = " << sum << std::endl;

    return sum;
}


