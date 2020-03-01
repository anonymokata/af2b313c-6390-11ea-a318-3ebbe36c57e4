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

TEST(TestWordSearchSolver, TestWordSarchNaieveFindForwardInDirectionGivenStart)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    WordSearchSolver solver(grid);

    std::vector<Point> bones_points = solver.findWordInDirection("BONES", Point(0, 6), Direction::south);
    ASSERT_NE(bones_points.size(), 0);
    ASSERT_EQ(bones_points.size(), 5);
    ASSERT_TRUE(bones_points[0] == Point(0, 6));
    ASSERT_TRUE(bones_points[1] == Point(0, 7));
    ASSERT_TRUE(bones_points[2] == Point(0, 8));
    ASSERT_TRUE(bones_points[3] == Point(0, 9));
    ASSERT_TRUE(bones_points[4] == Point(0, 10));

    std::vector<Point> kahn_points = solver.findWordInDirection("KHAN", Point(5,9), Direction::north);
    ASSERT_EQ(kahn_points.size(), sizeof("KHAN") - 1);

    ASSERT_TRUE(kahn_points[0] == Point(5,9));
    ASSERT_TRUE(kahn_points[1] == Point(5,8));
    ASSERT_TRUE(kahn_points[2] == Point(5,7));
    ASSERT_TRUE(kahn_points[3] == Point(5,6));

}

TEST(TestWordSeachSolver, TestWordSearchNieveFindWrongStart)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    WordSearchSolver solver(grid);

    std::vector<Point> bones_points = solver.findWordInDirection("BONES", Point(0, 0), Direction::south);
    ASSERT_EQ(bones_points.size(), 0);
}

TEST(TestWordSearchSolver, TestWordSearchGoodStartWrongDirectionOutOfRange)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    WordSearchSolver solver(grid);

    std::vector<Point> bones_points = solver.findWordInDirection("BONES", Point(0, 5), Direction::west);
    ASSERT_EQ(bones_points.size(), 0);
}