/**
 * @file WordGrid.hpp
 *
 * This file contains the declaration of the WordGrid class, its members and properties.
 *
 * The WordGrid object is the in-memory representation of our word search puzzle. It is designed to allow
 * access to individual members, and be constructed from a vector of text file lines.
 *
 * @author Jordan Sebastian
 */

#ifndef WORDSEARCHKATA_WORDGRID_HPP
#define WORDSEARCHKATA_WORDGRID_HPP
#include <vector>
#include <string>
#include "Point.hpp"
#include "Direction.hpp"

class WordGrid
{

public:
    /**
     * Construct a Word Grid Object.
     *
     * @param[in] grid_lines A vector containing strings from a well formatted word search grid.
     * @throws logic_error If the number of lines available is not large enough, the grid isn't square, or the grid
     * has rows with different column sizes or there are unacceptable characters / delimiters or general formatting
     * errors in the provided data.
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
    char getPoint(const Point& p);

    /**
     * Converts a direction enumeration into a point that can be used as an offset.
     *
     * This can be used to do point math in the same way one might do vector math. E.g.
     * Point a = Point(5, 5) + directionToOffset(Direction::north).
     *
     * The pointer returned from directionToOffset(Direction::north) would be Point(-1, 0). Meaning
     * adding this to Point(5, 5) would create a = Point(4, 5).
     *
     * @param dir The cardinal direction to provide an offset for.
     * @return A Point object representing an offset in the correct cardinal direction.
     */
    Point directionToOffset(Direction dir);

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
     * @param[in] grid A vector containing strings, that represent each line of the word grid. No header line is to be
     * provided, and it is assumed that no header line is provided.
     */
    void _processGrid(const std::vector<std::string>& grid);

    /**
     * Process a line of the word search grid.
     *
     * This function process each letter A-Z of the word search delimited by the ',' character.
     *
     * @param[in] line The line from the word search matrix to process
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
    std::vector<std::vector<char>> _2d_grid;

    /**
     * Our processed words that we are seraching for.
     */
    std::vector<std::string> _search_words;
    unsigned long int _expected_column_length = 0;

};


#endif //WORDSEARCHKATA_WORDGRID_HPP
