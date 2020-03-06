/**
 * @file WordSolution.cpp
 *
 * Implementation details of the output stream operator.
 *
 * @author Jordan Sebastian
 */
#include "WordSolution.hpp"

#include <utility>

_WordSolution::_WordSolution(std::string  word, std::vector<Point>  points)
    : word(std::move(word)), points(std::move(points))
{

}

std::ostream& operator<<(std::ostream& out, const _WordSolution& ws)
{
    out << ws.word << ": ";
    if (ws.points.empty())
    {
        out << "Not Found";
        return out;
    }
    for (const Point& p : ws.points)
    {

        out << "(" << p.getX() << "," << p.getY() << ")";
        if (&p != &ws.points.back())
        {
            out << ",";
        }
    }

    return out;
}