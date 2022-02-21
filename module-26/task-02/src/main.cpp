#include <iostream>
#include "phone.h"

int main(int, char**) {
        
   Phone phone;

   std::string command;
   std::string name;
   std::string number;
   std::string name_number;
   std::string message;

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

            if (!phone.add(name, number)) {
                std::cout << "Error"<<std::endl;
            }
            
            continue;
        } 

        if (command == "call") {

            std::cout<<"Input contact/number: ";
            std::cin >> name_number;

            if (!phone.call(name_number)) {
                std::cout << "Input data wrong"<<std::endl;
            }

            continue;
        } 


         if (command == "sms") {

            std::cout<<"Input contact/number: ";
            std::cin >> name_number;

            std::cout<<"Input message: ";
            std::cin >> message;

            if (!phone.sms(name_number, message)) {
                std::cout << "Input data wrong"<<std::endl;
            }

            continue;

        }


        std::cout << "Input command not found :(" << std::endl; 



   }         

    return 0;
}
