#include "SinglePassSolver.hpp"

/**
 * A simple constructor.
 * @param grid - The word grid representing what we are searching.
 * @throws runtime_error if the grid provided has no words.
 */
SinglePassSolver::SinglePassSolver(const WordGrid& grid) : WordSearchSolver(grid)
{


}


std::vector<Point> SinglePassSolver::searchAtPointAndDir(std::string::iterator begin, std::string::iterator end,
                                                         const Point& start_point,    const Direction dir)
{

    std::vector<Point> res;

    char current_letter = *begin;
    char grid_letter = '\0';

    Point current_point = Point(start_point.getX(), start_point.getY());
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
            res.clear();
            break;
        }
        if (current_letter != grid_letter)
        {
            res.clear();
            break;
        }

        res.push_back(current_point);
        current_point = _grid.directionToOffset(dir) + current_point;
        begin++;
    } while (begin < end);

    return res;
}

std::vector<Point> SinglePassSolver::searchAtPointAndDirRange(std::string::iterator begin, std::string::iterator end,
                                            const Point& start_point,
                                            const Direction dir_start, const Direction dir_stop)
{
    std::vector<Point> res;
    for (auto current_direction = dir_start; current_direction < dir_stop; ++current_direction)
    {
        res = searchAtPointAndDir(begin, end, start_point, current_direction);
        if (!res.empty())
        {
            break;
        }
    }
    return res;
}



std::vector<WordSolution> SinglePassSolver::solve()
{
    throw std::runtime_error("Error: Not yet implemented.");
}


