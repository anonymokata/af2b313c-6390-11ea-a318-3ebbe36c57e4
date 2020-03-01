
#include "Point.hpp"
Point::Point(unsigned int x, unsigned int y) : x(x), y(y)
{
}

unsigned int Point::getX() const
{
    return x;
}

unsigned int Point::getY() const
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

Point Point::operator+(const Point &other)
{
    Point res(x, y);
    res.setX(other.getX() + x);
    res.setY(other.getY() + y);
    return res;
}