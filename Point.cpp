
#include "Point.hpp"
Point::Point(unsigned int x, unsigned int y) : x(x), y(y)
{
}

int Point::getX() const
{
    return x;
}

int Point::getY() const
{
    return y;
}

void Point::setX(int new_x)
{
    x = new_x;
}

void Point::setY(int new_y)
{
    y = new_y;
}

Point Point::operator+(const Point& rhs)
{
    Point res(x, y);
    res.setX(rhs.x + this->x);
    res.setY(rhs.y + this->y);
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

bool Point::operator!=(const Point& rhs)
{
    return !(*this == rhs);
}
