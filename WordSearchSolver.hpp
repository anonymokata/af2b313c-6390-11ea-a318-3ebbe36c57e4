//
// Created by jordan on 3/1/20.
//

#ifndef WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
#define WORDSEARCHKATA_WORDSEARCHSOLVER_HPP

#include "WordGrid.hpp"

class WordSearchSolver
{
public:
    explicit WordSearchSolver(const WordGrid& grid);
    ~WordSearchSolver() = default;
private:
    WordGrid _grid;
};


#endif //WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
