//
// Created by jordan on 2/25/20.
//

#include <stdexcept>
#include "WordGrid.hpp"

#define MIN_GRID_LINES 2

WordGrid::WordGrid(const std::vector<std::string> &grid_lines)
{
    if (grid_lines.size() < MIN_GRID_LINES)
    {
        throw std::logic_error("Error: Grid Line creation failed as the grid is not large enough.");
    }

}

int WordGrid::size()
{
    return 15;
}