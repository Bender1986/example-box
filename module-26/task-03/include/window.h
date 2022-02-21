#ifndef WIN_H
#define WIN_H

#include <iostream>

struct Point2D {
    int x, y;

    void operator +=(const Point2D& pos) {
        x += pos.x;
        y += pos.y;
    }

    friend void operator >> (std::istream& is, Point2D& pos) {
        is >> pos.x >> pos.y;
    }
};



class Window {

    private:

    Point2D m_pos;
    int m_width;
    int m_height;

    public:

    Window (const Point2D& pos, const int& width, const int& height): 
    m_pos{pos},  m_width{width}, m_height{height} {

    }    

    bool move(const Point2D& pos);

    bool resize(const int& width, const int& height);

    void display();

    void close();

};





#endif