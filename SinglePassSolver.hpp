#ifndef WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
#define WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
#include <vector>
#include <list>
#include "WordSearchSolver.hpp"
#include "WordGrid.hpp"

class SinglePassSolver: public WordSearchSolver
{
public:

    /**
     * Solver constructor.
     * @param grid The grid that the solver will solve.
     */
    explicit SinglePassSolver(const WordGrid& grid);

    /**
     * Searches for a word at a given a point and in a specific direction.
     *
     * @tparam T Type to work with, this is either a std::string::iterator or std::string::reverse_iterator.
     * @param begin The beginning of the type T. Effectively the beginning of the string (or the opposite in reverse).
     * @param end The ending iterator.
     * @param start_point The start point to begin the search.
     * @param dir The direction to search in.
     * @return A vector of points if the whole word is found. An empty vector if the word is not found.
     */
    template <class T>
    std::vector<Point> searchAtPointAndDir(T begin, T end, const Point& start_point, const Direction dir);

    /**
     * Searches for a word given a point and a range of directions to look in.
     *
     * @note The direction range refers to how the Direction enum works. It starts with north and proceeds
     * clockwise until it reaches 'direction_max' after north_west. In this instance the dir_start and
     * dir_stop parameters refer to the starting direction, and the ending direction (exclusive). For example,
     * if dir_start is Direction::north, and dir_stop is Direction::south, The directions north, north_east,
     * east, south_east will all be tested.
     *
     * @tparam T Type to work with, this is either a std::string::iterator or std::string::reverse_iterator.
     * @param begin The beginning of the iterator object
     * @param end The end of the iterator object
     * @param start_point The starting point on the grid to start the search.
     * @param dir_start The direction to start looking in (inclusive).
     * @param dir_stop The direction to stop looking (exclusive).
     * @return
     */
    template <class T>
    std::vector<Point> searchAtPointAndDirRange(T begin, T end,
                                                const Point& start_point,
                                                const Direction dir_start, const Direction dir_stop);

    /**
     * Searches for multiples words, given a starting spot.
     *
     * @note Internally, this only searches east though south_west, as
     * the solve routine will proceed sequentially through the grid, left
     * to right and top to bottom, eliminating the need to look at additional
     * grid locations.
     *
     *
     * @param words The words to search for
     * @param start_point The starting spot to start the search.
     * @return A vector of WordSelections, that were found at this point. This may be empty if none are found.
     */
    std::vector<WordSolution> searchWordsInGridAtPoint(const std::list<std::string>& words, Point start_point);

    /**
     * Solves the puzzle.
     *
     * @note Not currently implemented but needed to compile.
     *
     * @return Nothing as of yet.
     */
    std::vector<WordSolution> solve() override;
    ~SinglePassSolver() override = default;
private:
    std::vector<std::string> _words;
};


#endif //WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
