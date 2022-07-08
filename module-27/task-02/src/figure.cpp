#include "figure.h"



/* Circle: get square */
double Circle::getSquare() const {

    return m_pi * m_radius * m_radius;
}


/* Triangle: get square */
double Triangle::getSquare() const {

    return (std::sqrt(3) * m_edge * m_edge) / 4.0;
}

/* Square: get square */
double Square::getSquare() const {

    return m_edge * m_edge;
}


/* Rectangle: get square */
double Rectangle::getSquare() const {

    return m_width * m_height;
}