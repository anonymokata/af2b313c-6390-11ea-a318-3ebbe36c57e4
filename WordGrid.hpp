//
// Created by jordan on 2/25/20.
//

#ifndef WORDSEARCHKATA_WORDGRID_HPP
#define WORDSEARCHKATA_WORDGRID_HPP
#include <vector>
#include <string>
#include "Point.hpp"

class WordGrid
{

public:



    /**
     * Construct a Word Grid Object.
     *
     * @param grid_lines A vector containing strings from a well formatted word search grid.
     */
    explicit WordGrid(const std::vector<std::string> &grid_lines);

    /**
     * Gets the size of the grid.
     *
     * @note If the object was successfully created, the rows and columns will be the same number (e.g. 12x12).
     * Therefore, only one integer is returned
     * .
     * @return The height and width of the word grid expressed as a single integer.
     */
    unsigned int size();

    /**
     * Get the words we are searching for.
     *
     * @return A vector containing the words we will search for. This may be an empty vector.
     */
    std::vector<std::string> getSearchWords();

    /**
     * Add a word to search for.
     *
     * @note The word provided must follow the following rules:
     *  - Must be at least two characters in length
     *  - Cannot be larger than the height/width of the grid.
     *  - Must not be a duplicate
     *
     * @param new_word The word to add to our list of words to search for.
     * @throws std::invalid_parameter If the word provided violates the rules above.
     * @throws std::exception If the word provided is an nullptr.
     */
    void addWord(const std::string& new_word);

    /**
     * Gets a specific point in the grid.
     *
     * This assumes that the top left of the grid is x: 0, y: 0.
     * Additionally and following typical convention, x refers to the column and y refers to the
     * row.
     *
     * @param p The point to get in the grid, x, y.
     * @return The value at the point provided.
     * @throws out_of_bounds if p contains an invalid x or y value.
     */
    char getPoint(Point& p);

    std::vector<char> getNearby(const Point& p);

    /**
     * Default destructor.
     */
    ~WordGrid() = default;
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
     * Parses and stors the words to search for.
     *
     * @param wordsLine A string representing the list of words (the first line of the word grid).
     * @throws Anything that is throwable by addWord(..).
     */
    void _processSearchWords(const std::string& wordsLine);

    /**
     * The main 2d grid that is used for processing.
     */
    std::vector<std::vector<char>> _2dGrid;

    /**
     * Our processed words that we are seraching for.
     */
    std::vector<std::string> _searchWords;
    unsigned long int _expectedColumnLength = 0;

};


#endif //WORDSEARCHKATA_WORDGRID_HPP
