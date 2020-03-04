#include "SinglePassSolver.hpp"

/**
 * A simple constructor.
 * @param grid - The word grid representing what we are searching.
 * @throws runtime_error if the grid provided has no words.
 */
SinglePassSolver::SinglePassSolver(const WordGrid& grid) : WordSearchSolver(grid)
{


}


std::vector<Point> SinglePassSolver::searchAtPointAndDir(
        std::string::iterator begin,
        std::string::iterator end,
        const Point& start_point,
        const Direction dir)
{

    std::vector<Point> res;

    char current_letter = *begin;
    char grid_letter = '\0';

    try
    {
        grid_letter = _grid.getPoint(start_point);
    }
    catch (std::out_of_range& ex)
    {
        return res;
    }

    if (current_letter != grid_letter)
    {
        return res;
    }

    res.push_back(start_point);
    Point current_point = _grid.directionToOffset(dir) + start_point;
    do
    {
        begin++;
        current_letter = *begin;
        try
        {
            grid_letter = _grid.getPoint(current_point);
        }
        catch (std::out_of_range& ex)
        {
            // We have gone out of bounds. Get out.
            res.clear();
            break;
        }
        if (current_letter != grid_letter)
        {
            res.clear();
            break;
        }
        current_point = _grid.directionToOffset(dir) + current_point;
        res.push_back(current_point);
    } while (begin < end - 1);

    return res;
}

std::vector<WordSolution> SinglePassSolver::solve()
{
    throw std::runtime_error("Error: Not yet implemented.");
}


