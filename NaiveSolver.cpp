
#include "NaiveSolver.hpp"
#include "FileReader.hpp"
#include "WordGrid.hpp"


NaiveSolver::NaiveSolver(const WordGrid& grid) : WordSearchSolver(grid)
{

}

std::vector<Point> NaiveSolver::searchAtPointAndDir(const std::string& word, const Point& starting_point, const Direction dir)
{
    std::vector<Point> res;
    std::string found_word = "";
    auto word_iter = word.begin();
    char current_letter = '\0';
    char grid_letter = '\0';


    Point p(starting_point.getX(), starting_point.getY());

    do
    {
        current_letter = *word_iter;
        try
        {
            grid_letter = _grid.getPoint(p);
        }
        catch (std::out_of_range& ex)
        {
            // Ensure that if we go out of range this isn't the word we're looking for.
            res.clear();
            break;
        }

        if (grid_letter != current_letter)
        {
            // This isn't the letter we're looking for, bounce out.
            res.clear();
            break;
        }

        // Save off this current_letter, and its location.
        found_word += current_letter;
        res.push_back(p);

        // Increment our iterator, and our point in the current direction.
        word_iter += 1;
        p = _grid.directionToOffset(dir) + p;
    } while (found_word != word && word_iter != word.end());

    return res;
}

std::vector<Point> NaiveSolver::searchAtPoint(const std::string& word, const Point& starting_point, Direction& dir_found)
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

std::vector<Point> NaiveSolver::searchForWord(const std::string& word)
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


std::vector<WordSolution> NaiveSolver::solve()
{
    std::vector<WordSolution> res;

    for (auto& word : _grid.getSearchWords())
    {
        std::vector<Point> word_points = searchForWord(word);
        WordSolution tmp_sol = {
                .word = word,
                .points = word_points,
        };
        res.push_back(tmp_sol);

    }

    return res;
}