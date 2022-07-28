#ifndef SHAPE_H
#define SHAPE_H


#include <iostream>
#include <cmath>
#include <vector>
#include <boost/type_index.hpp>


/* Struct bounding box */
struct BoundingBoxDimensions
{
    double width;

    double height;
       
    friend std::ostream& operator<< (std::ostream& o, const BoundingBoxDimensions& b)
    {
        o << "width (" << b.width << ")" << " height ("<< b.height << ")";

        return o;
    }
};



/* Class Shape */
class IShape
{

    public:

    virtual double square() = 0; 

    virtual BoundingBoxDimensions dimensions() = 0;

    virtual std::string type() = 0;     
    
};



/* Class Circle */
class Circle: public IShape
{

    private:

    const double m_radius;

    public: 
    
    constexpr Circle(double radius) noexcept: m_radius{radius}{};

    virtual double square() override;

    virtual BoundingBoxDimensions dimensions() override;

    virtual std::string type() override;
};



/* Class Rectangle */
class Rectangle: public IShape
{

    private:

    const double m_width;

    const double m_height;

    public: 
    
    constexpr Rectangle(double width, double height) noexcept: m_width{width}, m_height{height}{};

    virtual double square() override;

    virtual BoundingBoxDimensions dimensions() override;

    virtual std::string type() override;
};


/* Class Rectangle */
class Triangle: public IShape
{

    private:

    const double m_a;

    const double m_b;

    const double m_c;

    public: 
    
    constexpr Triangle(double a, double b, double c) noexcept: m_a{a}, m_b{b}, m_c{c}{};

    virtual double square() override;

    virtual BoundingBoxDimensions dimensions() override;

    virtual std::string type() override;
};














#endif