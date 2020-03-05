#include <algorithm>
#include "SinglePassSolver.hpp"

/**
 * A simple constructor.
 * @param grid - The word grid representing what we are searching.
 * @throws runtime_error if the grid provided has no words.
 */
SinglePassSolver::SinglePassSolver(const WordGrid& grid) : WordSearchSolver(grid)
{
}

template <class T>
std::vector<Point> SinglePassSolver::searchAtPointAndDir(T begin, T end,
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

template <class T>
std::vector<Point> SinglePassSolver::searchAtPointAndDirRange(T begin, T end,
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

std::vector<WordSolution> SinglePassSolver::searchWordsInGridAtPoint(const std::list<std::string>& words, Point start_point)
{
    std::vector<WordSolution> res;
    for (auto word : words)
    {
        std::vector<Point> pts;
        for (int i = 0; i < 2; i++)
        {
            WordSolution sol;
            if (i == 0)
            {
                pts = searchAtPointAndDirRange(word.begin(), word.end(), start_point, Direction::east, Direction::west);
            }
            else
            {
                pts = searchAtPointAndDirRange(word.crbegin(), word.crend(), start_point, Direction::east, Direction::west);
            }
            if (!pts.empty())
            {
                // We found this word, continue on.
                sol.word = word;
                sol.points = pts;
                res.push_back(sol);
                break;
            }
        }
    }
    return res;
}

std::vector<WordSolution> SinglePassSolver::solve()
{
    std::vector<std::string> words_vec = _grid.getSearchWords();
    std::list<std::string> words(words_vec.begin(), words_vec.end());
    std::vector<WordSolution> solutions;

    for (unsigned int y = 0; y < _grid.size(); y++)
    {
        for (unsigned int x = 0; x < _grid.size(); x++)
        {
            Point current_point(x, y);
            std::vector<WordSolution> tmp = searchWordsInGridAtPoint(words, current_point);
            if (!tmp.empty())
            {
                solutions.insert(solutions.end(), tmp.begin(), tmp.end());
                // A bit tricky, but not as bad as it may seem. This takes all of the solutions we just found,
                // and removes them from our list of words we are searching for. This way we don't keep looking
                // for words we've already found.
                std::for_each(tmp.begin(), tmp.end(), [&words](WordSolution& solution){ words.remove(solution.word);});
            }
        }
    }
    return solutions;
}


