#include <iostream>


template<typename T, int size>
T Calc(T mass[size])
{
    T summ = 0;

    for(int i =0; i < size; i++)
    {
        summ += mass[i];
    }

    return summ/8;
};



int main()
{

    int mass[8] = {1, 2, 3, 4, 5, 6 ,7 ,8};
    
    std::cout<<Calc<int, 8>(mass) << std::endl;

    return 0;
}