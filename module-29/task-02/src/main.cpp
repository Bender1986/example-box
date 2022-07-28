#include <iostream>
#include <memory>
#include "shape.h"


void printParams(IShape* shape)
{
    std::cout <<"Type:   " << shape->type() << std::endl;
    std::cout <<"Square: " << shape->square() << std::endl;
    std::cout <<"Bound:  " << shape->dimensions() << std::endl;
    std::cout << std::endl;
}


int main(int, char**) {
    
    std::vector<std::unique_ptr<IShape>> vec;

    vec.emplace_back(std::make_unique<Circle>(2.0));

    vec.emplace_back(std::make_unique<Rectangle>(2, 5));

    vec.emplace_back(std::make_unique<Triangle>(3, 4, 5));

    for(const auto& it: vec)
    {
        printParams(&(*it));
    }  
    

    exit(0);
}
