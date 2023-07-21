#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>
#include "nlohmann/json.hpp"

int main(int, char**){
    
    std::cout << "Hello, from FilmsProject!\n";

    nlohmann::json dictionary;

    std::ifstream file("film.json");

    file >> dictionary;

    std::string actor = "Дэвид Духовны";

    std::cout<< actor << std::endl; 
    
   
    for(const auto& it: dictionary.items())
    {       
        for(auto& it2: it.value()["actor"].items())
        {         

            if (it2.key() == actor)
            {
                std::cout << "Film: " << it.key() << " Character: " << it2.value()<< std::endl;
            }          
        }  
    }


    file.close();     
}
