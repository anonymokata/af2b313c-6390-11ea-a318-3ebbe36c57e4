//
// Created by jordan on 2/25/20.
//

#include "gtest/gtest.h"
#include <vector>
#include <string>
#include "WordGrid.hpp"
#include "FileReader.hpp"

#define WORD_GRID_ROWS 15

TEST(WordGridTests, TestWordGridConstructor)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_NO_THROW(WordGrid word_grid = WordGrid(file_lines, true));
}

TEST(WordGridTests, TestWordGridThrowsExceptionWhenNoLines)
{
    std::vector<std::string> empty_lines;
    ASSERT_THROW(WordGrid word_grid = WordGrid(empty_lines, true), std::logic_error);
}

TEST(WordGridTests, TestParseProvidedWordGrid)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid = WordGrid(file_lines, true);
    ASSERT_EQ(word_grid.size(), WORD_GRID_ROWS);

    // Ensure that we still get the right size if the lines we pass in do not include a header line.
    std::vector<std::string> file_lines_without_header(file_lines.begin() + 1, file_lines.end());
    word_grid = WordGrid(file_lines_without_header, false);

    ASSERT_EQ(word_grid.size(), WORD_GRID_ROWS);
}

TEST(WordGridTests, TestWrongNumberOfRowsThrowsException)
{
    FileReader reader("./data/WordSearchWrongNumberOfRows.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, true), std::logic_error);
    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, false), std::logic_error);
}

TEST(WordGridTests, TestWrongNumberOfColumnsThrowsException)
{
    FileReader reader("./data/WordSearchWrongNumberOfColumns.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, true), std::logic_error);
    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, false), std::logic_error);
}

TEST(WordGridTests, TestGridCharactersAreOnlyAThroughZAndComma)
{
    FileReader reader("./data/WordSearchWrongCharacters.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, true), std::logic_error);
    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, false), std::logic_error);
}

TEST(WordGridTests, TestGridMultipleCharactersBetweenDelimitersThrowsException)
{
    FileReader reader("./data/WordSearchMultipleDelimitersBetweenCharacters.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, true), std::logic_error);
    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines, false), std::logic_error);
}

TEST(WordGridTests, TestSearchWordsProcess)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid;

    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines, true));
    std::vector<std::string> search_words = grid->getSearchWords();
    ASSERT_GT(search_words.size(), 0);
}