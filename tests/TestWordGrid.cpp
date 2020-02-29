//
// Created by jordan on 2/25/20.
//

#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <algorithm>
#include "WordGrid.hpp"
#include "FileReader.hpp"
#include "Point.hpp"

#define WORD_GRID_ROWS 15
#define WORDS_IN_PROVIDED_WORD_SEARCH 7

TEST(WordGridTests, TestWordGridConstructor)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> word_grid = nullptr;
    word_grid = std::make_unique<WordGrid>(file_lines);
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

    // Test an empty string should be invalid.
    ASSERT_THROW(grid->addWord(""), std::invalid_argument);

    // Test that a string must be bigger than 1 character.
    ASSERT_THROW(grid->addWord("A"), std::invalid_argument);

    // Test that a string cannot be larger than the size of the grid
    ASSERT_THROW(grid->addWord("ABCDEFGHIJKLMNOPQRSTUVWXYZ"), std::invalid_argument);

    // Test that a string cannot be duplicated. Note + 1 because of adding PICARD above.
    ASSERT_THROW(grid->addWord("SPOCK"), std::invalid_argument);
    ASSERT_EQ(grid->getSearchWords().size(), WORDS_IN_PROVIDED_WORD_SEARCH + 1);
}

TEST(WordGridTests, TestProcessSearchWordsWithInvalidTokens)
{
    FileReader reader("./data/WordSearchInvalidSearchWordsDosCommas.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;

    // Test that we don't get any errors in construction.
    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));

    // Test that after construction we have the right number of words, even if warnings are thrown.
    std::vector<std::string> words = grid->getSearchWords();
    ASSERT_EQ(words.size(), WORDS_IN_PROVIDED_WORD_SEARCH);

}
TEST(WordGridTests, TestProcessSearchWordsWithInvalidWordLength)
{
    FileReader reader("./data/WordSearchInvalidSearchWordsLength.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;
    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));
    std::vector<std::string> words = grid->getSearchWords();
    ASSERT_EQ(words.size(), WORDS_IN_PROVIDED_WORD_SEARCH);
}

TEST(WordGridTests, TestGetGridData)
{
    FileReader reader("./data/WordSearchInvalidSearchWordsLength.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;
    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));
    Point p = {.x = 0,
               .y= 0
    };

    char point_val = grid->getPoint(p);
    ASSERT_EQ(point_val, 'U');


}
