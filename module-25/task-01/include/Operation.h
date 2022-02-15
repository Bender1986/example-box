#ifndef OPER_H
#define OPER_H

#include<iostream>

/* Point struct */
struct Point
{
    int x;
    int y;

    bool operator == (const Point &point);    

    friend std::istream& operator >> (std::istream &in, Point &date);  
};


/* Line struct */
struct Line
{
    Point pointBeg;
    Point pointEnd;

    bool operator ^ (const Point &point);
};







#endif