//
// Created by jordan on 2/25/20.
//

#ifndef WORDSEARCHKATA_WORDGRID_HPP
#define WORDSEARCHKATA_WORDGRID_HPP
#include <vector>
#include <string>


class WordGrid
{
public:
    explicit WordGrid(const std::vector<std::string> &grid_lines, bool includes_header_row=false);
    int size();
private:
    std::vector<std::vector<char>> _2dGrid;
};


#endif //WORDSEARCHKATA_WORDGRID_HPP
