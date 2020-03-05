/**
 * @file WordSearchSolver.hpp
 *
 * An abstract object for algorithms which solve a word search.
 * In reality, I thought I'd use more here. Either way it made sense to have
 * a sane interface for the fact that there are multiple solvers.
 *
 * @author Jordan Sebastian
 */
#ifndef WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
#define WORDSEARCHKATA_WORDSEARCHSOLVER_HPP

#include <vector>
#include "WordGrid.hpp"
#include "WordSolution.hpp"

class WordSearchSolver
{
public:
    /**
     * Main constructor.
     *
     * @param grid The main word grid
     */
    explicit WordSearchSolver(const WordGrid& grid);

    /**
     * Solve interface.
     *
     * This called whenever any solver wants to solve the puzzle. Main logic goes here.
     *
     * @return A vector of solutions.
     */
    virtual std::vector<WordSolution> solve() = 0;
    virtual ~WordSearchSolver() {};

protected:
    WordGrid _grid;
};


#endif //WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
