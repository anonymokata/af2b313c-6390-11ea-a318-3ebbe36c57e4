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
    int getX() const;

    /**
     * Gets the Y coordinate of the Point.
     *
     * @return An unsigned integer representing the Y coordinate of the Point.
     */
    int getY() const;

    /**
     * Set the X value.
     *
     * @param new_x The new x value this Point should have.
     */
    void setX(int new_x);

    /**
     * Set the Y value
     *
     * @param new_y The new y value this Point should have.
     */
    void setY(int new_y);

    /**
     * Adds two Points together.
     *
     * @note This simply adds X to X and Y to Y
     * Example (assuming a and b are valid Points):
     * Point c = a + b;
     *
     * @param rhs - The right hand side of the equation.
     * @return A new point object that is the addition of of two points.
     */
    Point operator+(const Point& rhs);

    /**
     * Adds one point to another setting the final value to the first.
     *
     * Example
     * Point a(5, 5);
     * Point b(1, 1);
     * a += b;
     *
     * @param rhs The right hand side of the equation.
     * @return A reference to this, don't think too much about it. Just use as in the example above.
     */
    Point& operator+=(const Point& rhs);

    /**
     * Compare two points for equality.
     *
     * This simply compares the X and Y values. If they both match then they are equal. Otherwise they are not equal.
     *
     * @param rhs - The right hand side of the comparison.
     * @return True if the two points are equal. False otherwise.
     */
    bool operator==(const Point& rhs);

    /**
     * Compare two points for inequality.
     *
     * @param rhs The right hand side of the inequality.
     * @return True of the two points are not equal. False if they are equal.
     */
    bool operator!=(const Point& rhs);


private:
    int x;
    int y;
};

#endif //WORDSEARCHKATA_POINT_HPP
