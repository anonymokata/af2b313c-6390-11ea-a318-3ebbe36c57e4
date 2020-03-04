#ifndef WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
#define WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
#include <vector>
#include "WordSearchSolver.hpp"
#include "WordGrid.hpp"

class SinglePassSolver: public WordSearchSolver
{
public:

    explicit SinglePassSolver(const WordGrid& grid);
    std::vector<Point> searchAtPointAndDir(std::string::iterator begin, std::string::iterator end, const Point& start_point, const Direction dir);
    std::vector<Point> searchAtPointAndDirRange(std::string::iterator begin, std::string::iterator end,
                                                const Point& start_point,
                                                const Direction dir_start, const Direction dir_stop);

    std::vector<WordSolution> solve() override;
    ~SinglePassSolver() override = default;
private:
    std::vector<std::string> _words;
};


#endif //WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
