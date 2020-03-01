#include "gtest/gtest.h"
#include "WordSearchSolver.hpp"
#include "WordGrid.hpp"
#include "FileReader.hpp"
#include <vector>
#include <string>

TEST(TestWordSearchSolver, TestWordSearchConstructor)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    ASSERT_NO_THROW(WordSearchSolver solver(grid));
}