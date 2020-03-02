//
// Created by jordan on 3/1/20.
//

#include "WordSearchSolver.hpp"
WordSearchSolver::WordSearchSolver(const WordGrid& grid) : _grid(grid)
{

}

std::vector<Point> WordSearchSolver::findWordInDirection(const std::string& word, const Point& starting_spot, const Direction dir)
{
    std::vector<Point> res;
    std::string found_word = "";

    // Ensure that our starting spot is actually a good place to begin.
    if (_grid.getPoint(starting_spot) != *(word.begin()))
    {
        return res;
    }

    // Start with the first letter.
    found_word += *(word.begin());
    res.push_back(starting_spot);

    // p will start off in a particular direction.
    Point p = _grid.directionToOffset(dir) + starting_spot;
    auto word_iter = word.begin() + 1;
    while (found_word != word && word_iter != word.end())
    {
        char value = '\0';
        try
        {
            value = _grid.getPoint(p);
        }
        catch (std::out_of_range& ex)
        {
            // Ensure that if we go out of range this isn't the word we're looking for.
            res.clear();
            break;
        }

        if (value != *word_iter)
        {
            // This isn't the letter we're looking for, bounce out.
            res.clear();
            break;
        }

        // Save off this value, and its location.
        found_word += value;
        res.push_back(p);

        // Increment our iterator, and our point in the current direction.
        word_iter += 1;
        p = _grid.directionToOffset(dir) + p;
    }

    return res;
}

std::vector<Point> WordSearchSolver::findWordInAnyDirection(const std::string& word, const Point& starting_spot, Direction& dir_found)
{
    std::vector<Point> res;
    Direction current_direction = Direction::north;
    for (current_direction = Direction::north; current_direction < Direction::direction_max; ++current_direction)
    {
        res = findWordInDirection(word, starting_spot, current_direction);
        if (!res.empty())
        {
            dir_found = current_direction;
            return res;
        }
    }

    return res;
}
