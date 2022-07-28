#include <iostream>
#include "dog.h"



int main(int, char**) {
    

      
    Dog dog("Barsik");


    dog.add_talent(new TalentSwim());
    dog.add_talent(new TalentDance());
    
    
    dog.show_talents();

}
