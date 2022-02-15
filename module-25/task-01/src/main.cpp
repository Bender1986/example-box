#include <iostream>
#include "Operation.h"

int main(int, char**) {

    std::string command = "scalpel";
    Line cut = {.pointBeg{.x = 1, .y = 1}, .pointEnd{.x = 1, .y = 10}};
      

    while (1) {

        std::cout << "Input command (hemostat, tweezers, suture, exit): \n";
        std::cin >> command;
    
        /* hemostat */
        if (command == "hemostat") {
            
            std::cout << "Input point: ";
            
            Point p;

            std::cin >> p;

            if (cut ^ p) {
                std::cout<<"This operation hemostat is successful"<<std::endl;
            }
            else std::cout<<"\033[1;31m"<<"This operation hemostat is fail"<<"\033[0m"<<std::endl;

            continue;
        }

        /* tweezers */
        if (command == "tweezers") {
            
            std::cout << "Input point: ";
            
            Point p;

            std::cin >> p;

            if (cut ^ p) {
                std::cout<<"This operation tweezers is successful"<<std::endl;
            }
            else std::cout<<"\033[1;31m"<<"This operation tweezers is fail"<<"\033[0m"<<std::endl;

            continue;
        }

        /* suture */
        if (command == "suture") {
            
            std::cout << "Input point begin: ";
            
            Point p1, p2;

            std::cin >> p1;

            std::cout << "Input point end: ";
            
            std::cin >> p2;

            if (cut ^ p1 && cut ^ p2) {
                std::cout<<"This operation suture is successful"<<std::endl;
            }
            else std::cout<<"\033[1;31m"<<"This operation suture is fail"<<"\033[0m"<<std::endl;
            

            if (p1 == cut.pointBeg && p2 == cut.pointEnd) {

                std::cout<<"This operation is complited"<<std::endl;
                break;
            }


            continue;
        }


        /* exit */
        if (command == "exit") {

            break;
        }


        std::cout<<"\033[1;31m"<<"This command not found"<<"\033[0m"<<std::endl;

    }

  



}
