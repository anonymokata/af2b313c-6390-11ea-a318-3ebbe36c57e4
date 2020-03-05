/**
 * @file TestWordGrid.cpp
 *
 * Tests the creation and manipulation of the WordGrid object.
 *
 * @author Jordan Sebastian
 */
#include "gtest/gtest.h"
#include <vector>
#include <string>
#include <algorithm>
#include "src/WordGrid.hpp"
#include "src/FileReader.hpp"
#include "src/Point.hpp"
#include "src/Direction.hpp"
#include "TestConstants.hpp"


/**
 * Test that the WordGrid constructor does not throw an excpetion,
 * when provided valid data, and that the size, and words are interpreted
 * from the data correctly.
 */
TEST(WordGridTests, TestWordGridConstructor)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> word_grid = nullptr;
    ASSERT_NO_THROW(word_grid = std::make_unique<WordGrid>(file_lines));
    ASSERT_EQ(word_grid->size(), WORD_GRID_ROWS);
    ASSERT_EQ(word_grid->getSearchWords().size(), WORDS_IN_PROVIDED_WORD_SEARCH);
}

/**
 * Test that the word grid properly throws an exception if the
 * data it's provided is empty.
 */
TEST(WordGridTests, TestWordGridThrowsExceptionWhenNoLines)
{
    std::vector<std::string> empty_lines;
    ASSERT_THROW(WordGrid word_grid = WordGrid(empty_lines), std::logic_error);
}

/**
 * Test that the Size of the provided word grid is correct.
 */
TEST(WordGridTests, TestParseProvidedWordGrid)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> word_grid;

    ASSERT_NO_THROW(word_grid = std::make_unique<WordGrid>(file_lines));
    ASSERT_EQ(word_grid->size(), WORD_GRID_ROWS);
}

/**
 * Test that the constructor will throw a logic_error when the
 * number of rows does not match the number of columns.
 */
TEST(WordGridTests, TestWrongNumberOfRowsThrowsException)
{
    FileReader reader("./data/WordSearchWrongNumberOfRows.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

/**
 * Test that the constructor throws a logic_error exception when the
 * number of columns does not match the number of rows.
 */
TEST(WordGridTests, TestWrongNumberOfColumnsThrowsException)
{
    FileReader reader("./data/WordSearchWrongNumberOfColumns.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

/**
 * Ensure that the word grid will throw an exception if letters other than
 * A-Z and , are encountered.
 */
TEST(WordGridTests, TestGridCharactersAreOnlyAThroughZAndComma)
{
    FileReader reader("./data/WordSearchWrongCharacters.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

/**
 * Test that the WordGrid constructor detects invalid instances of the ',' delimiter
 * being encountered.
 */
TEST(WordGridTests, TestGridMultipleCharactersBetweenDelimitersThrowsException)
{
    FileReader reader("./data/WordSearchMultipleDelimitersBetweenCharacters.txt");
    std::vector<std::string> file_lines = reader.readFileLines();

    ASSERT_THROW(WordGrid word_grid = WordGrid(file_lines), std::logic_error);
}

/**
 * Test that the line containing the words to search for are properly
 * parsed.
 *
 * @note It appears that we are "adding" words after the fact. Instead, we
 * are adding words to the line that gets parsed, then re-parsing, to
 * ensure we can add things and they are parsed correctly.
 */
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

/**
 * Test that we can add words through an interface, and that
 * we cannot add invalid words (empty string, or words without the correct format).
 */
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

/**
 * Test that we can consume a few errors here and there. Ensure that we can
 * consume extra delimiters, by properly handling the exceptions.
 */
TEST(WordGridTests, TestProcessSearchWordsWithInvalidTokens)
{
    std::cout.setstate(std::ios_base::failbit);
    FileReader reader("./data/WordSearchInvalidSearchWordsDosCommas.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;

    // Test that we don't get any errors in construction.
    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));

    // Test that after construction we have the right number of words, even if warnings are thrown.
    std::vector<std::string> words = grid->getSearchWords();
    ASSERT_EQ(words.size(), WORDS_IN_PROVIDED_WORD_SEARCH);
    std::cout.setstate(std::ios_base::goodbit);
}

/**
 * Ensure that we will properly handle (without an exception) an invalid word being tossed
 * our way and that the word is simply consumed.
 *
 * @note A warning is also printed to the user telling them of the situation. However, that is something
 * that can be very difficult to test, and brittle at best. It's possible to do it with std::streambuf's. However,
 * the point is that we won't throw an exception and that the word gets eaten.
 */
TEST(WordGridTests, TestProcessSearchWordsWithInvalidWordLength)
{
    FileReader reader("./data/WordSearchInvalidSearchWordsLength.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;
    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));
    std::vector<std::string> words = grid->getSearchWords();
    ASSERT_EQ(words.size(), WORDS_IN_PROVIDED_WORD_SEARCH);
}

/**
 * Test that we can get an arbitrary point on the grid, and we
 * get an expected value.
 */
TEST(WordGridTests, TestGetGridValueAtPoint)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;
    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));
    Point p(0, 0);

    char point_val = grid->getPoint(p);
    ASSERT_EQ(point_val, 'U');
    p.setX(1);
    ASSERT_EQ(grid->getPoint(p), 'M');
}

/**
 * Test going out of bounds when attempting to get a point on the grid.
 * This should throw an out_of_range exception.
 */
TEST(WordGridTests, TestGetValueOutOfBounds)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = nullptr;
    ASSERT_NO_THROW(grid = std::make_unique<WordGrid>(file_lines));
    Point p(300, 300);
    ASSERT_THROW(grid->getPoint(p), std::out_of_range);
    p = Point(grid->size(), grid->size());

    ASSERT_THROW(grid->getPoint(p), std::out_of_range);

    p = Point(12, 15);
    ASSERT_THROW(grid->getPoint(p), std::out_of_range);

    p = Point(15, 10);
    ASSERT_THROW(grid->getPoint(p), std::out_of_range);

    p = Point(grid->size() - 1, grid->size() - 1);
    char value = '\0';
    ASSERT_NO_THROW(value = grid->getPoint(p));
    ASSERT_EQ(value, 'B');

    p = Point(-1, -5);
    ASSERT_THROW(grid->getPoint(p), std::out_of_range);

}

/**
 * Test converting a Direction enum to a point. This will be used for
 * something looking like vector math, allowing us to add two points together.
 *
 * This will ensure that we get the correct values, based on the input given.
 */
TEST(WordGridTests, TestDirectionToPointOffset)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = std::make_unique<WordGrid>(file_lines);

    Point p(5, 5);
    ASSERT_EQ(grid->getPoint(p), 'Y');

    p = Point(5, 5) + grid->directionToOffset(Direction::north);
    EXPECT_EQ(p.getX(), 5);
    EXPECT_EQ(p.getY(), 4);

    p = Point(5, 5) + grid->directionToOffset(Direction::north_east);
    EXPECT_EQ(p.getX(), 6);
    EXPECT_EQ(p.getY(), 4);

    p = Point(5, 5) + grid->directionToOffset(Direction::east);
    EXPECT_EQ(p.getX(), 6);
    EXPECT_EQ(p.getY(), 5);

    p = Point(5, 5) + grid->directionToOffset(Direction::south_east);
    EXPECT_EQ(p.getX(), 6);
    EXPECT_EQ(p.getY(), 6);

    p = Point(5, 5) + grid->directionToOffset(Direction::south);
    EXPECT_EQ(p.getX(), 5);
    EXPECT_EQ(p.getY(), 6);

    p = Point(5, 5) + grid->directionToOffset(Direction::south_west);
    EXPECT_EQ(p.getX(), 4);
    EXPECT_EQ(p.getY(), 6);

    p = Point(5, 5) + grid->directionToOffset(Direction::west);
    EXPECT_EQ(p.getX(), 4);
    EXPECT_EQ(p.getY(), 5);

    p = Point(5, 5) + grid->directionToOffset(Direction::north_west);
    EXPECT_EQ(p.getX(), 4);
    EXPECT_EQ(p.getY(), 4);

}
