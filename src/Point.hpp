/**
 * @file Point.hpp
 * This file contains the declaration of the Point class.
 *
 * The point class is used as an object to maintain a (X,Y) coordinate. In additon to simple storage,
 * it provides operator overloading for the +, +=, == and != operators, allowing for comparison, as well
 * as simple addition operations that mimic vector math.
 *
 * @author Jordan Sebastian
 */

#ifndef WORDSEARCHKATA_POINT_HPP
#define WORDSEARCHKATA_POINT_HPP

class Point {
public:
    /**
     * Simple constructor for a Point object
     * @param x The x coordinate
     * @param y The y coordinate
     */
    Point(int x, int y) noexcept;

    /**
     * Default destructor.
     */
    ~Point() = default;

    /**
     * Gets The X coordinate of the Point.
     *
     * @return An unsigned integer representing the X coordinate of the Point.
     */
    int getX() const noexcept;

    /**
     * Gets the Y coordinate of the Point.
     *
     * @return An unsigned integer representing the Y coordinate of the Point.
     */
    int getY() const noexcept;

    /**
     * Set the X value.
     *
     * @param[in] new_x The new x value this Point should have.
     */
    void setX(int new_x) noexcept;

    /**
     * Set the Y value
     *
     * @param new_y The new y value this Point should have.
     */
    void setY(int new_y) noexcept;

    /**
     * Adds two Points together.
     *
     * @note This simply adds X to X and Y to Y
     * Example (assuming a and b are valid Points):
     * Point c = a + b;
     *
     * @param[in] rhs - The right hand side of the equation.
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
     * @param[in] rhs The right hand side of the equation.
     * @return A reference to this, don't think too much about it. Just use as in the example above.
     */
    Point& operator+=(const Point& rhs);

    /**
     * Compare two points for equality.
     *
     * This simply compares the X and Y values. If they both match then they are equal. Otherwise they are not equal.
     *
     * @param[in] rhs - The right hand side of the comparison.
     * @return True if the two points are equal. False otherwise.
     */
    bool operator==(const Point& rhs);

    /**
     * Compare two points for inequality.
     *
     * @param[in] rhs The right hand side of the inequality.
     * @return True of the two points are not equal. False if they are equal.
     */
    bool operator!=(const Point& rhs);


private:
    int x;
    int y;
};

#endif //WORDSEARCHKATA_POINT_HPP
