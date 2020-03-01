//
// Created by jordan on 3/1/20.
//

#include "WordSearchSolver.hpp"
WordSearchSolver::WordSearchSolver(const WordGrid& grid) : _grid(grid)
{

}

std::vector<std::tuple<std::string, std::vector<Point>>> WordSearchSolver::naiveSearch()
{
    return std::vector<std::tuple<std::string, std::vector<Point>>>(8);
}
