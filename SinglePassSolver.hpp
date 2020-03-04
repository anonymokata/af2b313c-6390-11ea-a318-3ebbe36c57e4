#ifndef WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
#define WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
#include <vector>
#include <list>
#include "WordSearchSolver.hpp"
#include "WordGrid.hpp"

class SinglePassSolver: public WordSearchSolver
{
public:

    explicit SinglePassSolver(const WordGrid& grid);

    template <class T>
    std::vector<Point> searchAtPointAndDir(T begin, T end, const Point& start_point, const Direction dir);
    template <class T>
    std::vector<Point> searchAtPointAndDirRange(T begin, T end,
                                                const Point& start_point,
                                                const Direction dir_start, const Direction dir_stop);

    std::vector<WordSolution> searchWordsInGridAtPoint(const std::list<std::string>& words, Point start_point);
    std::vector<WordSolution> solve() override;
    ~SinglePassSolver() override = default;
private:
    std::vector<std::string> _words;
};


#endif //WORDSEARCHKATA_SINGLEPASSSOLVER_HPP
