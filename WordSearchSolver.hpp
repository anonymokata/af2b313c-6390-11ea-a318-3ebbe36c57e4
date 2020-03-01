//
// Created by jordan on 3/1/20.
//

#ifndef WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
#define WORDSEARCHKATA_WORDSEARCHSOLVER_HPP

#include "WordGrid.hpp"
#include "Point.hpp"
#include <tuple>

class WordSearchSolver
{
public:
    explicit WordSearchSolver(const WordGrid& grid);
    std::vector<std::tuple<std::string, std::vector<Point>>> naiveSearch();
    ~WordSearchSolver() = default;
private:
    WordGrid _grid;
};


#endif //WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
