#include "fish.h"
#include <exception>
#include <ctime>

void Fish::take(int number)
{   
    if (number < 1 || number > 9)
    {
        throw std::invalid_argument("number");
    }

    throw m_field[number - 1];
}

Fish::Fish()
{
   std::srand(std::time(nullptr));
   m_field[std::rand()%9] = 1;

   std::srand(std::time(nullptr));
   m_field[std::rand()%9] = -1;
   m_field[std::rand()%9] = -1;
   m_field[std::rand()%9] = -1;       
}
