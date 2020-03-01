//
// Created by jordan on 2/29/20.
//

#include "Direction.hpp"
Direction& operator++(Direction& d)
{
    switch(d)
    {
        case Direction::north: return d = Direction::north_east;
        case Direction::north_east: return d = Direction::east;
        case Direction::east: return d = Direction::south_east;
        case Direction::south_east: return d = Direction::south;
        case Direction::south: return d = Direction::south_west;
        case Direction::south_west: return d = Direction::west;
        case Direction::west: return d =Direction::north_west;
        case Direction::north_west: return d = Direction::direction_max;
        case Direction::direction_max: return d = Direction::north;
    }
    return d = Direction::north;
}