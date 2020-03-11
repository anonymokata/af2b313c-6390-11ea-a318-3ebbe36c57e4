/**
 * @file TestSinglePassSolver.cpp
 *
 * Test the SinglePassSolver solution.
 *
 * @author Jordan Sebastian
 */
#include "gtest/gtest.h"
#include "src/SinglePassSolver.hpp"
#include <algorithm>
#include <memory>
#include <vector>
#include <string>
#include "src/FileReader.hpp"
#include "src/WordGrid.hpp"
#include "TestConstants.hpp"
#include "src/Direction.hpp"

/**
 * Test that we can build the constructor without an exception.
 */
TEST(TestSinglePass, TestBuildConstructor)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    // Create our solver, with our word grid.
    std::unique_ptr<SinglePassSolver> solver = nullptr;
    ASSERT_NO_THROW(solver = std::make_unique<SinglePassSolver>(word_grid));

}

/**
 * Test that we can find a word,given a direction and a starting spot.
 */
TEST(TestSinglePass, TestFindWordInDirection)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::string word = "SPOCK";
    std::vector<Point> results;
    solver.searchAtPointAndDir(word.begin(), word.end(), Point(2, 1),
                                                            Direction::south_east, results);
    ASSERT_EQ(results.size(), 5);
    ASSERT_TRUE(std::equal(results.begin(), results.end(), spock_solution.begin()));
}

/**
 * Test that we can find a word given a range of directions.
 */
TEST(TestSinglePass, TestFindWordInDirectionRange)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::string word = "SPOCK";
    std::vector<Point> results;
    solver.searchAtPointAndDirRange(word.begin(), word.end(), Point(2, 1), Direction::east,
                                                                 Direction::direction_max, results);
    ASSERT_EQ(results.size(), 5);
    results.clear();

    solver.searchAtPointAndDirRange(word.begin(), word.end(), Point(2, 1), Direction::south,
                                              Direction::direction_max, results);
    ASSERT_EQ(results.size(), 0);

}

/**
 * Test that we can find words in the grid, given only a starting spot.
 */
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

    // Spot check some of the words.
    std::vector<WordSolution> solution;
    solver.searchWordsInGridAtPoint(words, Point(1, 7), solution);
    ASSERT_EQ(solution.size(), 1);
    ASSERT_STREQ(solution[0].word.c_str(), "KIRK");
    solution.clear();
    solver.searchWordsInGridAtPoint(words, Point(0, 0), solution);
    ASSERT_EQ(solution.size(), 1);
    ASSERT_STREQ(solution[0].word.c_str(), "SULU");

}

/**
 * Test that we can solve the provided word search correctly.
 */
TEST(TestSinglePass, TestSolvePuzzle)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::list<std::string> words {
            std::string("BONES"),
            std::string("KHAN"),
            std::string("KIRK"),
            std::string("SCOTTY"),
            std::string("SPOCK"),
            std::string("SULU"),
            std::string("UHURA"),
    };

    std::vector<WordSolution> all_solutions = solver.solve();
    ASSERT_EQ(all_solutions.size(), words.size());

    auto it = std::find_if(all_solutions.begin(), all_solutions.end(), [](const WordSolution& solution) {return solution.word == "BONES";});
    ASSERT_FALSE(it == all_solutions.end());
    it = std::find_if(all_solutions.begin(), all_solutions.end(), [](const WordSolution& solution) {return solution.word == "KHAN";});
    ASSERT_FALSE(it == all_solutions.end());
    it = std::find_if(all_solutions.begin(), all_solutions.end(), [](const WordSolution& solution) {return solution.word == "KIRK";});
    ASSERT_FALSE(it == all_solutions.end());
    it = std::find_if(all_solutions.begin(), all_solutions.end(), [](const WordSolution& solution) {return solution.word == "SPOCK";});
    ASSERT_FALSE(it == all_solutions.end());
    it = std::find_if(all_solutions.begin(), all_solutions.end(), [](const WordSolution& solution) {return solution.word == "SULU";});
    ASSERT_FALSE(it == all_solutions.end());
    it = std::find_if(all_solutions.begin(), all_solutions.end(), [](const WordSolution& solution) {return solution.word == "UHURA";});
    ASSERT_FALSE(it == all_solutions.end());
    it = std::find_if(all_solutions.begin(), all_solutions.end(), [](const WordSolution& solution) {return solution.word == "SCOTTY";});
    ASSERT_FALSE(it == all_solutions.end());
}