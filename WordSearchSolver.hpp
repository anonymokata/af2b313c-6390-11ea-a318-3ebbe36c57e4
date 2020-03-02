//
// Created by jordan on 3/1/20.
//

#ifndef WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
#define WORDSEARCHKATA_WORDSEARCHSOLVER_HPP

#include <tuple>
#include "WordGrid.hpp"
#include "Point.hpp"
#include "Direction.hpp"

class WordSearchSolver
{
public:
    explicit WordSearchSolver(const WordGrid& grid);
    std::vector<std::tuple<std::string, std::vector<Point>>> naiveSearch();
    std::tuple<std::string, std::vector<Point>> naiveSearchWord(const std::string& word);
    std::vector<Point> findWordInAnyDirection(const std::string& word, const Point& starting_spot, Direction& dir_found);
    std::vector<Point> findWordInDirection(const std::string& word, const Point& starting_spot, const Direction dir);
    std::vector<Point> findWord(const std::string& word);
    ~WordSearchSolver() = default;
private:
    WordGrid _grid;
};


#endif //WORDSEARCHKATA_WORDSEARCHSOLVER_HPP
