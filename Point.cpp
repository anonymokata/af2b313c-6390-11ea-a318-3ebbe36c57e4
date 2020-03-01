
#include "Point.hpp"
Point::Point(unsigned int x, unsigned int y) : x(x), y(y)
{
}

unsigned int Point::getX()
{
    return x;
}

unsigned int Point::getY()
{
    return y;
}