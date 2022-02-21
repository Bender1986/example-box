#include <iostream>
#include "window.h"

int main(int, char**) {

    Window w = {Point2D{.x =0, .y = 0}, 80, 50};

    std::string command;
    Point2D pos;
    int width;
    int height;
  
    while(command != "close") {

        std::cout << "Input command (move, resize, display, close): ";
        std::cin >> command;

        if (command == "close") {
            return 0;
        }

        if (command == "move") {
            std::cout << "Input value (x, y) movable: ";
            std::cin >> pos;

            if (!w.move(pos)) {
                std::cout << "Input data is wriong" << std::endl;
            }

            continue;
        }


        if (command == "resize") {
            std::cout << "Input value (w, h) to resize: ";
            std::cin >> width >> height;

            if (!w.resize(width, height)) {
                std::cout << "Input data is wriong" << std::endl;
            }

            continue;
        }

        if (command == "display") {
            w.display();

            continue;
        }
        
        std::cout << "Input command not found :(" << std::endl;

    }


}
