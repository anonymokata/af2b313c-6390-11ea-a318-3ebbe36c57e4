//
// Created by jordan on 2/29/20.
//

#ifndef WORDSEARCHKATA_DIRECTION_HPP
#define WORDSEARCHKATA_DIRECTION_HPP

enum class Direction {
    north           = 0,
    north_east      = 1,
    east            = 2,
    south_east      = 3,
    south           = 4,
    south_west      = 5,
    west            = 6,
    north_west      = 7,
    direction_max   = 8,
};

Direction& operator++(Direction& d);
#endif //WORDSEARCHKATA_DIRECTION_HPP
