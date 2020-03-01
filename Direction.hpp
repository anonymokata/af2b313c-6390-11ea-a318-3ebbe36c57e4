//
// Created by jordan on 2/29/20.
//

#ifndef WORDSEARCHKATA_DIRECTION_HPP
#define WORDSEARCHKATA_DIRECTION_HPP

enum class Direction {
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

Direction& operator++(Direction& d);
#endif //WORDSEARCHKATA_DIRECTION_HPP
