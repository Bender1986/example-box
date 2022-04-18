#ifndef FIG_H
#define FIG_H

#include <cmath>

struct Point {
    double x;
    double y;
};


struct DescribeRect
{
    double height;
    double width;
};


enum class Color {
    RED   = 0,
    BLUE  = 1,
    GREEN = 2,
    NONE = 3
};

/* Figure */
class Figure {

    private:

    Point m_center;

    Color m_color;

    protected:

    DescribeRect m_rectangle;    

    public:

    Figure(Point center, Color color = Color::NONE): m_center{center}, m_color{color} 
    {

    }
    
    /* Get color */
    const Color& getColor() const {
        return m_color;
    }

    /* Get color */
    const DescribeRect& getRectangle() const {
        return m_rectangle;
    }

    /* Get square */
    virtual double getSquare() const = 0;
          
};



/* Circle */
class Circle: public Figure {
    
    private:

    const double m_pi = 3.14;

    double m_radius;

    
    public:

    Circle(double radius, Point center, Color color): Figure(center, color) 
    {
        m_radius = radius;

        m_rectangle = {.height = radius * 2, .width = radius *2};
    } 

    /* Get square a circle */    
    virtual double getSquare() const override; 
    
};



/* Triangle */
class Triangle: public Figure {
    
    private:

    double m_edge;
    
    public:

    Triangle(double edge, Point center, Color color): Figure(center, color) 
    {
        m_edge = edge;

        m_rectangle = {.height = (edge * std::sqrt(3))/2.0 , .width = edge};
    } 

    /* Get square a circle */    
    virtual double getSquare() const override; 
    
};


/* Square */
class Square: public Figure {
    
    private:

    double m_edge;
    
    public:

    Square(double edge, Point center, Color color): Figure(center, color) 
    {
        m_edge = edge;

        m_rectangle = {.height = edge, .width = edge};
    } 

    /* Get square a circle */    
    virtual double getSquare() const override; 
    
};


/* Square */
class Rectangle: public Figure {
    
    private:

    double m_width;
    double m_height;
    
    public:

    Rectangle(double width, double height, Point center, Color color = Color::NONE): Figure(center, color) 
    {
        m_width = width;
        m_height = height;
        m_rectangle = {.height = height, .width = width};
    } 

    /* Get square a circle */    
    virtual double getSquare() const override; 
    
};




#endif