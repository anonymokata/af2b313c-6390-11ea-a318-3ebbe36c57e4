//
// Created by jordan on 3/1/20.
//

#include "WordSearchSolver.hpp"
WordSearchSolver::WordSearchSolver(const WordGrid& grid) : _grid(grid)
{

}

std::vector<Point> WordSearchSolver::searchAtPointAndDir(const std::string& word, const Point& starting_point, const Direction dir)
{
    std::vector<Point> res;
    std::string found_word = "";
    auto word_iter = word.begin();
    char value = '\0';

    // Ensure that our starting spot is actually a good place to begin.
    try
    {
        value = _grid.getPoint(starting_point);

    }
    catch (std::out_of_range& ex)
    {
        return res;
    }

    if (value != *word_iter)
    {
        return res;
    }

    // Start with the first letter.
    found_word += *(word.begin());
    res.push_back(starting_point);

    // p will start off in a particular direction.
    Point p = _grid.directionToOffset(dir) + starting_point;
    word_iter += 1;
    while (found_word != word && word_iter != word.end())
    {
        value = '\0';
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

std::vector<Point> WordSearchSolver::searchAtPoint(const std::string& word, const Point& starting_point, Direction& dir_found)
{
    std::vector<Point> res;
    Direction current_direction = Direction::north;
    for (current_direction = Direction::north; current_direction < Direction::direction_max; ++current_direction)
    {
        res = searchAtPointAndDir(word, starting_point, current_direction);
        if (!res.empty())
        {
            dir_found = current_direction;
            return res;
        }
    }

    return res;
}

std::vector<Point> WordSearchSolver::searchForWord(const std::string& word)
{
    std::vector<Point> res;
    Direction direction = Direction::direction_max;
    char first_letter = *(word.begin());
    for (unsigned int y = 0; y < _grid.size(); y++)
    {
        for (unsigned int x = 0; x < _grid.size(); x++)
        {
            Point p(x, y);

            // Determine if we have found the first letter.
            char current_letter = _grid.getPoint(p);
            if (current_letter == first_letter)
            {
                res = searchAtPoint(word, p, direction);
                if (!res.empty())
                {
                    return res;
                }
            }
        }
    }
    return res;
}