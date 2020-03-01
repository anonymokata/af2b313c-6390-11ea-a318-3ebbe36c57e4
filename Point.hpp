//
// Created by jordan on 2/29/20.
//

#ifndef WORDSEARCHKATA_POINT_HPP
#define WORDSEARCHKATA_POINT_HPP

class Point {
public:
    Point(unsigned int x, unsigned int y);
    ~Point() = default;

    /**
     * Gets The X coordinate of the Point.
     *
     * @return An unsigned integer representing the X coordinate of the Point.
     */
    unsigned int getX() const;

    /**
     * Gets the Y coordinate of the Point.
     *
     * @return An unsigned integer representing the Y coordinate of the Point.
     */
    unsigned int getY() const;

    /**
     * Set the X value.
     *
     * @param new_x The new x value this Point should have.
     */
    void setX(unsigned int new_x);

    /**
     * Set the Y value
     *
     * @param new_y The new y value this Point should have.
     */
    void setY(unsigned int new_y);

    Point operator+(const Point& other);


private:
    unsigned int x;
    unsigned int y;
};

#endif //WORDSEARCHKATA_POINT_HPP
