#include <iostream>

#include "my_shared_ptr.h"

#include "toy.h"


int main(int, char**){
    
        
    MySharedPtr::MySharedPtr<Toy> toy_ptr = MySharedPtr::make_shared<Toy>("Ball");
    
    std::cout << "Toy is: " << toy_ptr->GetName() << std::endl;

    std::cout << "Owners count: "<< toy_ptr.count() << std::endl;
    
    {
    MySharedPtr::MySharedPtr<Toy> toy_ptr2 (toy_ptr);

    std::cout << "Toy is: " << toy_ptr2->GetName() << std::endl;

    std::cout << "Owners count: "<< toy_ptr2.count() << std::endl;
    }

    std::cout << "Owners count: "<< toy_ptr.count() << std::endl;
}
