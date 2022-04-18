#include <iostream>
#include <vector>
#include "figure.h"

void getDataFigure(const Figure& figure) {

    std::cout << "Square: " << figure.getSquare() << std::endl;

    DescribeRect desc = figure.getRectangle();

    std::cout << "Descibe rectangle: (" << desc.width << ", " << desc.height << ")" << std::endl;
}


int main() {

    Circle  circle = {3, Point{1, 2}, Color::GREEN};

    Triangle  triangle = {5, Point{3, 3}, Color::RED};

    Square square = {7, Point{1, 4}, Color::BLUE};

    Rectangle rect = {10, 11, Point{5, 5}};

    std::string command;

    while (command != "exit")
    {
        std::cout << "Input command (circle, triangle, square, rect, exit): ";
        std::cin >> command;
        
        if (command == "circle") {
            getDataFigure(circle);
            continue;
        }

        if (command == "triangle") {
            getDataFigure(triangle);
            continue;
        }

        if (command == "square") {
            getDataFigure(square);
            continue;
        }

        if (command == "rect") {
            getDataFigure(rect);
            continue;
        }

    }
    

    return 0;
}