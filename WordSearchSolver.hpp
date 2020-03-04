//
// Created by jordan on 3/3/20.
//

#ifndef WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
#define WORDSEARCHKATA_WORDSEARCHSOLVER_HPP

#include <vector>
#include "WordGrid.hpp"
#include "WordSolution.hpp"

class WordSearchSolver
{
public:
    explicit WordSearchSolver(const WordGrid& grid);
    virtual std::vector<WordSolution> solve() = 0;
    virtual ~WordSearchSolver() {};

protected:
    WordGrid _grid;
};


#endif //WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
