//
// Created by jordan on 3/2/20.
//

#include "WordSolution.hpp"

std::ostream& operator<<(std::ostream& out, const _WordSolution& ws)
{
    out << ws.word << ": ";
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