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
    /**
     * Construct a Word Grid Object.
     *
     * @param grid_lines A vector containing strings from a well formatted word search grid.
     * @param includes_header_row Defaults to false. When true, we will skip processing the first line in grid_lines.
     * When false, we will not skip the first line in grid_lines.
     */
    explicit WordGrid(const std::vector<std::string> &grid_lines, bool includes_header_row=false);

    /**
     * Gets the size of the grid.
     *
     * @note If the object was successfully created, the rows and columns will be the same number (e.g. 12x12).
     * Therefore, only one integer is returned
     * .
     * @return The height and width of the word grid expressed as a single integer.
     */
    int size();

private:

    /**
     * Process the grid passed in line by line.
     *
     * @note This function assumes that any header row or any other data is removed. The parameter grid should
     * contain only the word search matrix.
     *
     * @param grid A vector containing strings, that represent each line of the word grid. No header line is to be
     * provided, and it is assumed that no header line is provided.
     */
    void _processGrid(const std::vector<std::string>& grid);

    /**
     * Process a line of the word search grid.
     *
     * This function process each letter A-Z of the word search delimited by the ',' character.
     *
     * @param line The line from the word search matrix to process
     * @return A vector that contains all of the word search letters (A-Z, and removing delimiters).
     */
    std::vector<char> _processLine(const std::string& line);

    /**
     * The main 2d grid that is used for processing.
     */
    std::vector<std::vector<char>> _2dGrid;
};


#endif //WORDSEARCHKATA_WORDGRID_HPP
