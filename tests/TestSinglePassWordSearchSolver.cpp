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

TEST(TestSinglePass, TestBuildFindWordInDirection)
{
    FileReader reader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> file_lines = reader.readFileLines();
    WordGrid word_grid(file_lines);

    SinglePassSolver solver(word_grid);
    std::string word = "SPOCK";
    std::vector<Point> results = solver.searchAtPointAndDir(word.begin(), word.end(), Point(2,1), Direction::south_east);
    ASSERT_EQ(results.size(), 5);

}