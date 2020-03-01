//
// Created by jordan on 2/29/20.
//

#include "Directions.hpp"
Directions& operator++(Directions& d)
{
    switch(d)
    {
        case Directions::north: return d = Directions::north_east;
        case Directions::north_east: return d = Directions::east;
        case Directions::east: return d = Directions::south_east;
        case Directions::south_east: return d = Directions::south;
        case Directions::south: return d = Directions::south_west;
        case Directions::south_west: return d = Directions::west;
        case Directions::west: return d =Directions::north_west;
        case Directions::north_west: return d = Directions::direction_max;
        case Directions::direction_max: return d = Directions::north;
    }
    return d = Directions::north;
}