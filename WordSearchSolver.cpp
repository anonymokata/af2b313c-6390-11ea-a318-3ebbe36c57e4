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
    found_word += *(word.begin());
    res.push_back(starting_spot);
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

        if (value == *word_iter)
        {
            // Record the current point if this is our word.
            res.push_back(p);
        }
        else
        {
            // This isn't the letter we're looking for, bounce out.
            res.clear();
            break;
        }

        // Increment our iterator, and our point in the current direction.
        word_iter += 1;
        p = _grid.directionToOffset(dir) + p;
    }

    return res;
}
