#ifndef FISH_H
#define FISH_H

#include <iostream>


class Fish
{
    private:

    int m_field[9] = {0};    
    
    public:

    Fish();

    void take(int number);   
};




#endif