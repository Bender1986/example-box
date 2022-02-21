#include "window.h"
#include <iostream>

bool Window::move(const Point2D& pos) {

    m_pos += pos;

    return true;
}


bool Window::resize(const int& width, const int& height){
     
     m_width = width;
     m_height = height;

     return true;
 }


void Window::display() {

     for (int i = 0; i < 50; i++) {
        for (int j = 0; j < 80; j++) {
            if (j  < m_pos.x || i < m_pos.y || i >= (m_height + m_pos.y) || j >= (m_width + m_pos.x)) 
                std::cout << "0";
            else std::cout << "1"; 
        }

        std::cout<<std::endl;
     }
}

void Window::close() {
    /*this work close */
}