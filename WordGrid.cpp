//
// Created by jordan on 2/25/20.
//

#include <stdexcept>
#include "WordGrid.hpp"
#include <iostream>

#define MIN_GRID_LINES 2

WordGrid::WordGrid(const std::vector<std::string> &grid_lines)
{
    if (grid_lines.size() < MIN_GRID_LINES)
    {
        throw std::logic_error("Error: Grid Line creation failed as the grid is not large enough.");
    }

    std::vector<std::string> letters_only_grid(grid_lines.begin() + 1, grid_lines.end());
    _processGrid(letters_only_grid);
    _processSearchWords(*(grid_lines.begin()));

}

void WordGrid::_processGrid(const std::vector<std::string>& grid)
{
    for (const std::string &line : grid)
    {
        // We can recover from this.
        if (line.empty())
        {
            continue;
        }
        _2dGrid.emplace_back(_processLine(line));
    }

    unsigned int column_length = _2dGrid.begin()->size();
    if (column_length != _2dGrid.size())
    {
        throw std::logic_error("Error: The grid is not a square.");
    }
}

std::vector<char> WordGrid::_processLine(const std::string& line)
{
    std::vector<char> ret;
    bool should_be_delim = false;
    for (char token : line)
    {
        if (token >= 'A' && token <= 'Z' && !should_be_delim)
        {
            ret.push_back(token);
            should_be_delim = true;
        }
        else if (token == ',' && should_be_delim)
        {
            should_be_delim = false;
            continue;
        }
        else
        {
            throw std::logic_error("Error: Invalid characters or delimiters found out of place in the grid.");
        }
    }

    if (_expectedColumnLength == 0)
    {
        // On the first line, record how long it is. We'll expect all other lines to
        // be the same length.
        _expectedColumnLength = line.size();
    }
    else if (line.size() != _expectedColumnLength)
    {
        // In the case that we already have a line length set, and this line doesn't match, raise an exception.
        throw std::logic_error("Error: Not all columns are the same size.");
    }
    return ret;
}

void WordGrid::_processSearchWords(const std::string& wordsLine)
{
    std::string delimiter = ",";
    std::string token = "";
    unsigned long int next = wordsLine.find(delimiter, 0);
    unsigned long int last = 0;
    while (next != std::string::npos)
    {
        token = wordsLine.substr(last, next - last);
        last = next + 1;
        next = wordsLine.find(delimiter, last);
        try
        {
            addWord(token);
        }
        catch (std::invalid_argument& ex)
        {
            std::cout << "Warning: Invalid word provided: " + token + " check input file." << std::endl;
            continue;
        }
    }

    std::string final_word = wordsLine.substr(last);
    try
    {
        addWord(final_word);
    }
    catch (std::invalid_argument& ex)
    {
        std::cout << "Warning: The last word on the search-words line is invalid. Is there an extra comma?" << std::endl;
    }
}

unsigned int WordGrid::size()
{
    return _2dGrid.size();
}

std::vector<std::string> WordGrid::getSearchWords()
{
    return _searchWords;
}

void WordGrid::addWord(const std::string& new_word)
{
    if (new_word.empty())
    {
        throw std::invalid_argument("Error: The word provided to addWord() cannot be an empty string.");
    }
    if (new_word.length() < 2)
    {
        throw std::invalid_argument("Error: The word provided to addWord() must be at least two characters in length"
                                    " and fit inside of the grid.");
    }
    if (new_word.length() > size())
    {
        throw std::invalid_argument("Error: The word provided to addWord() cannot be larger than the width/height of"
                                    " the grid. Words cannot wrap around.");
    }

    for (const std::string& word : _searchWords)
    {
        if (word == new_word)
        {
            throw std::invalid_argument("Error: The word provided to addWord cannot be added as it is a duplicate.");
        }
    }
    _searchWords.push_back(new_word);
}