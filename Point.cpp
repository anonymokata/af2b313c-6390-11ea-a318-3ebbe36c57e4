
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

Point Point::operator+(const Point& rhs)
{
    Point res(x, y);
    res.setX(rhs.x + this->x);
    res.setY(rhs.x + this->y);
    return res;
}

Point& Point::operator+=(const Point& rhs)
{
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

bool Point::operator==(const Point& rhs)
{
    return (rhs.x == this->x && rhs.y == this->y);
}

