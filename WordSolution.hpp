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

    /**
     * Enables directly outputting the formatted solution.
     *
     * @param out The output stream to use.
     * @param ws The solution structure to use.
     * @return The output stream with formatted data added.
     * @throws Anything ostream may throw, but nothing more.
     */
    friend std::ostream& operator<<(std::ostream& out, const _WordSolution& ws);

} WordSolution;


#endif //WORDSEARCHKATA_WORDSOLUTION_HPP
