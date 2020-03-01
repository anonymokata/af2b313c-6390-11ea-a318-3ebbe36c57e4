
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

void Point::setX(unsigned int new_x)
{
    x = new_x;
}

void Point::setY(unsigned int new_y)
{
    y = new_y;
}