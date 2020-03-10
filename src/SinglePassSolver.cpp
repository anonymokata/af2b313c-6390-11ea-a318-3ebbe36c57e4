/**
 * @file SinglePassSolver.cpp
 *
 * Implementation details for member functions of the SinglePassSolver.
 *
 * @author Jordan Sebastian
 */
#include <iostream>
#include <algorithm>
#include "SinglePassSolver.hpp"

SinglePassSolver::SinglePassSolver(const WordGrid& grid) : WordSearchSolver(grid)
{
}

template <class T>
void SinglePassSolver::searchAtPointAndDir(T begin, T end, const Point &start_point, const Direction dir,
                                                         std::vector<Point> &points)
{
    // If we are in this function, we are already certain that the first letter matches.
    points.push_back(start_point);
    begin += 1;

    char current_letter = *begin;
    char grid_letter = '\0';

    Point current_point = _grid.directionToOffset(dir) + start_point;

    do
    {
        current_letter = *begin;
        try
        {
            grid_letter = _grid.getPoint(current_point);
        }
        catch (std::out_of_range& ex)
        {
            // We have gone out of bounds. Get out.
            points.clear();
            break;
        }
        if (current_letter != grid_letter)
        {
            points.clear();
            break;
        }

        points.emplace_back(current_point);
        current_point = _grid.directionToOffset(dir) + current_point;
        begin++;
    } while (begin < end);

}

template <class T>
void
SinglePassSolver::searchAtPointAndDirRange(T begin, T end, const Point &start_point, const Direction dir_start,
                                           const Direction dir_stop, std::vector<Point> &points)
{
    for (auto current_direction = dir_start; current_direction < dir_stop; ++current_direction)
    {
        searchAtPointAndDir(begin, end, start_point, current_direction, points);
        if (!points.empty())
        {
            break;
        }
    }
}

int SinglePassSolver::searchWordsInGridAtPoint(const std::list<std::string> &words, const Point& start_point,
                                               std::vector<WordSolution> &solutions)
{
    std::vector<Point> pts;
    // Pre-allocate the room that our points will need.
    int count = 0;
    pts.reserve(_grid.getLongestWordLength());
    for (const auto& word : words)
    {
        char current_val = _grid.getPoint(start_point);
        if (current_val == word.cbegin()[0])
        {
            searchAtPointAndDirRange(word.cbegin(), word.cend(), start_point, Direction::east,
                                     Direction::west,pts);
        }
        if (current_val == word.crbegin()[0])
        {
            searchAtPointAndDirRange(word.crbegin(), word.crend(), start_point, Direction::east,
                                     Direction::west, pts);
        }
        if (!pts.empty())
        {
            // We found this word, continue on.

            solutions.emplace_back(word, pts);
            pts.clear();
            count++;
            break;
        }
    }
    return count;
}

std::vector<WordSolution> SinglePassSolver::solve()
{
    std::vector<std::string> words_vec = _grid.getSearchWords();
    std::list<std::string> words(words_vec.begin(), words_vec.end());
    std::vector<WordSolution> solutions;


    // We know how many solutions we ought to have.
    solutions.reserve(words.size());
    Point current_point(0, 0);
    for (unsigned int y = 0; y < _grid.size(); y++)
    {
        for (unsigned int x = 0; x < _grid.size(); x++)
        {
            current_point.setY(y);
            current_point.setX(x);
            int count = searchWordsInGridAtPoint(words, current_point, solutions);
            // Remove any words that were found.
            for (int i = 0; i < count; i++)
            {
                auto it = solutions.rbegin() + i;
                words.remove(it->word);
            }
        }
    }
    return solutions;
}

template void SinglePassSolver::searchAtPointAndDirRange(
        std::string::iterator begin, std::string::iterator end,
        const Point &start_point, const Direction dir_start,
        const Direction dir_stop, std::vector<Point> &points);

template void SinglePassSolver::searchAtPointAndDirRange(
        std::string::reverse_iterator begin, std::string::reverse_iterator end,
        const Point &start_point, const Direction dir_start,
        const Direction dir_stop, std::vector<Point> &points);

