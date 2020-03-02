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

/**
 * Increment operator for Direction enum.
 *
 * @note The direction is incremented from it starting spot
 * though the various cardinal values listed above. After it hits
 * direction_max, it will wrap around to north.
 *
 * @param[in] d The current direction.
 *
 * @return d is incremented to the next cardinal value, or direction_max.
 */
Direction& operator++(Direction& d);
#endif //WORDSEARCHKATA_DIRECTION_HPP
