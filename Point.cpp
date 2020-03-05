/**
 * @file Point.cpp
 *
 * Definition of member functions of the Point object.
 *
 * @author Jordan Sebastian
 */
#include "Point.hpp"
Point::Point(int x, int y) noexcept : x(x), y(y)
{
}

int Point::getX() const noexcept
{
    return x;
}

int Point::getY() const noexcept
{
    return y;
}

void Point::setX(int new_x) noexcept
{
    x = new_x;
}

void Point::setY(int new_y) noexcept
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
