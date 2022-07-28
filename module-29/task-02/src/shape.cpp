#include "shape.h"



/* Circle */
double Circle::square()
{
    return 3.14 * m_radius * m_radius;
}

BoundingBoxDimensions Circle::dimensions()
{
    return {m_radius*2, m_radius*2};
}

std::string Circle::type()
{
    return "Circle (" +  boost::typeindex::type_id_with_cvr<decltype(this)>().pretty_name() + ")";
}



/* Rectangle */
double Rectangle::square()
{
    return m_width * m_height;
}

BoundingBoxDimensions Rectangle::dimensions()
{
    return {m_width, m_height};
}

std::string Rectangle::type()
{
    return "Rectangle (" +  boost::typeindex::type_id_with_cvr<decltype(this)>().pretty_name() + ")";
}



/* Triangle */
double Triangle::square()
{       
    double p = (m_a + m_b + m_c)/2.0;

    return sqrt(p * (p - m_a) * (p - m_b) * (p - m_c));
}

BoundingBoxDimensions Triangle::dimensions()
{
    double p = (m_a + m_b + m_c)/2.0;

    double w = 2 * (m_a * m_b * m_c / (4 * sqrt(p*(p - m_a)*(p - m_b)*(p - m_c))));
    
    return {w, w};
}

std::string Triangle::type()
{
    return "Triangle (" + boost::typeindex::type_id_with_cvr<decltype(this)>().pretty_name() + ")";
}
