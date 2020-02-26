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

    ASSERT_NO_THROW(WordGrid word_grid = WordGrid(file_lines));
}

TEST(WordGridTests, TestWordGridThrowsExceptionWhenNoLines)
{
    std::vector<std::string> empty_lines;
    ASSERT_THROW(WordGrid word_grid = WordGrid(empty_lines), std::logic_error);
}

TEST(WordGridTests, TestParseProvidedWordGrid)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid = WordGrid(file_lines);
    ASSERT_EQ(word_grid.size(), WORD_GRID_ROWS);
}