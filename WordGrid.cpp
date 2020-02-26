//
// Created by jordan on 2/25/20.
//

#include <stdexcept>
#include "WordGrid.hpp"

WordGrid::WordGrid(const std::vector<std::string> &grid_lines)
{
    if (grid_lines.size() < 2)
    {
        throw std::logic_error("Error: Grid Line creation failed as the grid is not large enough.");
    }
    
}