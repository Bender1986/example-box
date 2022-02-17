#include <iostream>
#include "phone.h"

int main(int, char**) {
        
   Phone phone;

   std::string command;
   std::string name;
   std::string number;
   std::string name_number;

   while(command != "exit") {

        std::cout << "Input command (add, call, sms, exit): ";
        std::cin >> command;

        if (command == "exit")
          return 0;
        
        if (command == "add") {

            std::cout<<"Input contact: ";
            std::cin >> name;

            std::cout<<"Input number: ";
            std::cin >> number;

            if (!phone.setContact(name, number)) {
                std::cout << "Error"<<std::endl;
            }
            
        } 

        if (command == "call") {

            std::cout<<"Input contact/number: ";
            std::cin >> name_number;
                                                         


        } 



   }         

    return 0;
}
