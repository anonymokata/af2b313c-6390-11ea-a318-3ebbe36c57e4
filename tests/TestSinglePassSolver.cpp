#include "gtest/gtest.h"
#include "SinglePassSolver.hpp"
#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include "FileReader.hpp"
#include "WordGrid.hpp"
#include "TestConstants.hpp"
#include "Direction.hpp"

TEST(TestSinglePass, TestBuildConstructor)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    // Create our solver, with our word grid.
    std::unique_ptr<SinglePassSolver> solver = nullptr;
    ASSERT_NO_THROW(solver = std::make_unique<SinglePassSolver>(word_grid));

}

TEST(TestSinglePass, TestFindWordInDirection)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::string word = "SPOCK";
    std::vector<Point> results = solver.searchAtPointAndDir(word.begin(), word.end(), Point(2,1), Direction::south_east);
    ASSERT_EQ(results.size(), 5);
    ASSERT_TRUE(std::equal(results.begin(), results.end(), spock_solution.begin()));
}

TEST(TestSinglePass, TestFindWordInDirectionRange)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::string word = "SPOCK";
    std::vector<Point> results = solver.searchAtPointAndDirRange(word.begin(), word.end(), Point(2, 1), Direction::east, Direction::direction_max);
    ASSERT_EQ(results.size(), 5);
    results.clear();
    results = solver.searchAtPointAndDirRange(word.begin(), word.end(), Point(2, 1), Direction::south, Direction::direction_max);
    ASSERT_EQ(results.size(), 0);

}

TEST(TestSinglePass, TestFindWordsInGridAtPoint)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::list<std::string> words {
        std::string("BONES"),
        std::string("KHAN"),
        std::string("KIRK"),
        std::string("SPOCK"),
        std::string("SULU"),
        std::string("UHURA"),
    };


    std::vector<WordSolution> solution = solver.searchWordsInGridAtPoint(words, Point(1, 7));
    ASSERT_EQ(solution.size(), 1);
    ASSERT_STREQ(solution[0].word.c_str(), "KIRK");

    solution = solver.searchWordsInGridAtPoint(words, Point(0, 0));
    ASSERT_EQ(solution.size(), 1);
    ASSERT_STREQ(solution[0].word.c_str(), "SULU");

}

TEST(TestSinglePass, TestFindWordsInGrid)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::list<std::string> words {
            std::string("BONES"),
            std::string("KHAN"),
            std::string("KIRK"),
            std::string("SPOCK"),
            std::string("SULU"),
            std::string("UHURA"),
    };

    std::vector<WordSolution> all_solutions = solver.solve();
    ASSERT_EQ(all_solutions.size(), words.size());
}