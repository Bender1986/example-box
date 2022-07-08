#include <iostream>
#include <vector>
#include "swim.h"




int main(int, char**) {

    std::vector<Swimmer> vec_s;

    vec_s.emplace_back("Ivan", 3);
    vec_s.emplace_back("Petr", 1);
    vec_s.emplace_back("Alex", 1);
    vec_s.emplace_back("Jony", 2);
    vec_s.emplace_back("San", 1);
    vec_s.emplace_back("Max", 2);
    

    //SwimWrapper sw(vec_s);

    //sw.Start();  
    

}
