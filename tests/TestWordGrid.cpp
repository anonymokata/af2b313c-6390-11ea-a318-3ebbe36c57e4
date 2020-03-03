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
#include "Direction.hpp"
#include "TestConstants.hpp"


TEST(WordGridTests, TestWordGridConstructor)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> word_grid = nullptr;
    ASSERT_NO_THROW(word_grid = std::make_unique<WordGrid>(file_lines));
    ASSERT_EQ(word_grid->size(), WORD_GRID_ROWS);
    ASSERT_EQ(word_grid->getSearchWords().size(), WORDS_IN_PROVIDED_WORD_SEARCH);
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



TEST(WordGridTests, TestDirectionToPointOffset)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = std::make_unique<WordGrid>(file_lines);

    Direction dir = Direction::south;

    Point p(5, 5);
    ASSERT_EQ(grid->getPoint(p), 'Y');

    p += grid->directionToOffset(dir);
    EXPECT_EQ(p.getX(), 5);
    EXPECT_EQ(p.getY(), 6);
    ASSERT_EQ(grid->getPoint(p), 'N');
}

TEST(WordGridTests, GetSurroundingValuesByPoint)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    std::unique_ptr<WordGrid> grid = std::make_unique<WordGrid>(file_lines);

    Point p(5, 5);

    char known_nearby_values[] = {'C', 'I', 'K', 'E', 'N', 'L', 'T', 'G'};
    ASSERT_EQ(grid->getPoint(p), 'Y');
    std::vector<char> surrounding_values = grid->getNearby(p);
    ASSERT_EQ(surrounding_values.size(), 8);

    for(Direction d = Direction::north; d < Direction::direction_max; ++d)
    {
        ASSERT_EQ(known_nearby_values[static_cast<int>(d)], surrounding_values[static_cast<int>(d)]);
    }
}