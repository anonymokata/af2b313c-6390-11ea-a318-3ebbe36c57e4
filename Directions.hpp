//
// Created by jordan on 2/29/20.
//

#ifndef WORDSEARCHKATA_DIRECTIONS_HPP
#define WORDSEARCHKATA_DIRECTIONS_HPP

enum class Directions {
    north,
    north_east,
    east,
    south_east,
    south,
    south_west,
    west,
    north_west,
    direction_max
};

Directions& operator++(Directions& d);
#endif //WORDSEARCHKATA_DIRECTIONS_HPP
