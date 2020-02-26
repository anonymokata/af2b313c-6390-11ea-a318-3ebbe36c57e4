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

    if (includes_header_row)
    {
        std::vector<std::string> letters_only_grid(grid_lines.begin() + 1, grid_lines.end());
        _processGrid(letters_only_grid);
    }
    else
    {
        _processGrid(grid_lines);
    }

}

void WordGrid::_processGrid(const std::vector<std::string>& grid)
{
    for (const std::string &line : grid)
    {
        if (line.empty())
        {
            continue;
        }
        _2dGrid.emplace_back(_processLine(line));
    }
}

std::vector<char> WordGrid::_processLine(const std::string& line)
{
    std::vector<char> ret;
    for (char token : line)
    {
        if (token != ',')
        {
            ret.push_back(token);
        }
    }

    return ret;
}

int WordGrid::size()
{
    return _2dGrid.size();
}