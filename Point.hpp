//
// Created by jordan on 2/29/20.
//

#ifndef WORDSEARCHKATA_POINT_HPP
#define WORDSEARCHKATA_POINT_HPP

class Point {
public:
    Point(unsigned int x, unsigned int y);
    ~Point() = default;

    unsigned int getX();
    unsigned int x;
    unsigned int y;

private:

};

#endif //WORDSEARCHKATA_POINT_HPP
