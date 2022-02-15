#ifndef DISK_H
#define DISK_H

#include "ram.h"

class Disk {

    public: 

    bool save(const Ram &ram);

    bool load(Ram &ram);
};

#endif