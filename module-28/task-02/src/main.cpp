#include <iostream>
#include <vector>
#include "train.h"



int main(int, char**) {
    
    std::vector times(0, 0);

    times.push_back(3);
    times.push_back(4);
    times.push_back(1); 

    TrainWrapper tw(times);
    tw.Start();
    
}
