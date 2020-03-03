//
// Created by jordan on 3/2/20.
//

#ifndef WORDSEARCHKATA_WORDSOLUTION_HPP
#define WORDSEARCHKATA_WORDSOLUTION_HPP
#include <string>
#include <vector>
#include <iostream>
#include "Point.hpp"


typedef struct _WordSolution
{
    std::string word;
    std::vector<Point> points;

    friend std::ostream& operator<<(std::ostream& out, const _WordSolution& ws);

} WordSolution;


#endif //WORDSEARCHKATA_WORDSOLUTION_HPP
