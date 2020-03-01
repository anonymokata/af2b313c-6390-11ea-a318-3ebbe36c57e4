#include "gtest/gtest.h"
#include "WordSearchSolver.hpp"
#include "WordGrid.hpp"
#include "FileReader.hpp"
#include <vector>
#include <string>
#include <map>
TEST(TestWordSearchSolver, TestWordSearchConstructor)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    ASSERT_NO_THROW(WordSearchSolver solver(grid));
}

TEST(TestWordSearchSolver, TestWordSearchNaiveSearch)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    WordSearchSolver solver(grid);

    std::vector<std::tuple<std::string, std::vector<Point>>> word_points = solver.naiveSearch();
    ASSERT_EQ(word_points.size(), 8);
}