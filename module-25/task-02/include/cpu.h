#ifndef CPU_H
#define CPU_H

#include "ram.h"

int compute(const Ram &ram);

class Cpu {

    private:
    static int m_buf[8];
   
    public:
    static const int compute(const Ram &ram);

};


#endif