#ifndef WORDSEARCHKATA_NAIVESOLVER_HPP
#define WORDSEARCHKATA_NAIVESOLVER_HPP

#include <tuple>
#include "WordGrid.hpp"
#include "Point.hpp"
#include "Direction.hpp"
#include "WordSolution.hpp"
#include "WordSearchSolver.hpp"
class NaiveSolver : public WordSearchSolver
{
public:
    /**
     * Constructs the NaiveSolver object.
     *
     * @param[in] grid The WordGrid to be used to solve.
     */
    explicit NaiveSolver(const WordGrid& grid);

    /**
     * Searchs for a word given a specific point.
     *
     * This will search in all directions.
     *
     * @param[in] word The word to search for.
     * @param[in] starting_point The starting point to start the search.
     * @param[out] dir_found The direction in which the word exists.
     *
     * @return An empty vector of points on failure to find the word in any direction. A vector with the points of the
     * word if the word is found. You can easily test with vector_name.empty().
     */
    std::vector<Point> searchAtPoint(const std::string& word, const Point& starting_point, Direction& dir_found);

    /**
     * Searches for a word in a specific direction.
     *
     * @note this will only check places that begin at the starting point.
     *
     * @param[in] word The word to search for.
     * @param[in] starting_point The point in the grid to start the search.
     * @param[in] dir The direction to search
     *
     * @return A vector of points representing the word if it was fond. Otherwise this is an empty vector of Points.
     */
    std::vector<Point> searchAtPointAndDir(const std::string& word, const Point& starting_point, const Direction dir);

    /**
     * Performs an exhaustive search for a word in the grid.
     *
     * @param[in] word The word to search for.
     *
     * @return A vector containing the Points of the word in the grid if the word was found. An empty vector otherwise.
     */
    std::vector<Point> searchForWord(const std::string& word);

    std::vector<WordSolution> solve() override;

    /**
     * Default destructor.
     */
    ~NaiveSolver() = default;
};


#endif //WORDSEARCHKATA_NAIVESOLVER_HPP
