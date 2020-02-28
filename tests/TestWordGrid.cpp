//
// Created by jordan on 2/25/20.
//

#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <algorithm>
#include "WordGrid.hpp"
#include "FileReader.hpp"

#define WORD_GRID_ROWS 15
#define WORDS_IN_PROVIDED_WORD_SEARCH 7
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
    std::unique_ptr<WordGrid> word_grid;

    ASSERT_NO_THROW(word_grid = std::make_unique<WordGrid>(file_lines));
    ASSERT_EQ(word_grid->size(), WORD_GRID_ROWS);
}

TEST(WordGridTests, TestWrongNumberOfRowsThrowsException)
{
    FileReader reader("./data/WordSearchWrongNumberOfRows.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

TEST(WordGridTests, TestWrongNumberOfColumnsThrowsException)
{
    FileReader reader("./data/WordSearchWrongNumberOfColumns.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

TEST(WordGridTests, TestGridCharactersAreOnlyAThroughZAndComma)
{
    FileReader reader("./data/WordSearchWrongCharacters.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

TEST(WordGridTests, TestGridMultipleCharactersBetweenDelimitersThrowsException)
{
    FileReader reader("./data/WordSearchMultipleDelimitersBetweenCharacters.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

TEST(WordGridTests, TestSearchWordsProcess)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid;

    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));
    std::vector<std::string> search_words = grid->getSearchWords();
    ASSERT_GT(search_words.size(), 0);
    ASSERT_EQ(search_words.size(), WORDS_IN_PROVIDED_WORD_SEARCH);

    ASSERT_STREQ("BONES", search_words.begin()->c_str());
    ASSERT_STREQ("SCOTTY", search_words[3].c_str());

    file_lines[0] += ",PICARD,WORF";
    grid = std::make_unique<WordGrid>(file_lines);
    search_words = grid->getSearchWords();
    ASSERT_EQ(search_words.size(), WORDS_IN_PROVIDED_WORD_SEARCH + 2);
    ASSERT_STREQ("PICARD", (search_words.end() - 2)->c_str());
    ASSERT_STREQ("WORF", search_words.back().c_str());
}

TEST(WordGridTests, TestAddSearchWord)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    auto grid = std::make_unique<WordGrid>(file_lines);
    grid->addWord("PICARD");
    std::vector<std::string> names = grid->getSearchWords();
    auto pos = std::find(names.begin(), names.end(), "PICARD");
    ASSERT_NE(pos, names.end());
}