//
// Created by jordan on 2/25/20.
//

#include <stdexcept>
#include "WordGrid.hpp"

#define MIN_GRID_LINES 2

WordGrid::WordGrid(const std::vector<std::string> &grid_lines, bool includes_header_row)
{
    if (grid_lines.size() < MIN_GRID_LINES)
    {
        throw std::logic_error("Error: Grid Line creation failed as the grid is not large enough.");
    }

    for (const std::string &line : grid_lines)
    {
        // Just an easy way of skipping the first row. This could also have
        // been done by incrementing an iterator, instead of C++'s foreach style loop.
        if (includes_header_row)
        {
            includes_header_row = false;
            continue;
        }

        if (line.empty())
        {
            continue;
        }

        // This looks strange but it's just creating an empty vector<char>, with no size.
        _2dGrid.emplace_back();
        for (char token : line)
        {
            if (token != ',')
            {
                _2dGrid.back().push_back(token);
            }
        }
    }
}

int WordGrid::size()
{
    return _2dGrid.size();
}