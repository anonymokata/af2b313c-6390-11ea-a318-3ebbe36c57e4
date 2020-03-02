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

TEST(TestWordSearchSolver, FindWordInAnyDirectionGivenStartingPoint)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    WordSearchSolver solver(grid);
    Direction dir_found = Direction::direction_max;
    std::vector<Point> bones_points = solver.findWordInAnyDirection("BONES", Point(0, 6), dir_found);
    ASSERT_EQ(bones_points.size(), 5);
    ASSERT_TRUE(bones_points[0] == Point(0, 6));
    ASSERT_TRUE(bones_points[1] == Point(0, 7));
    ASSERT_TRUE(bones_points[2] == Point(0, 8));
    ASSERT_TRUE(bones_points[3] == Point(0, 9));
    ASSERT_TRUE(bones_points[4] == Point(0, 10));
    ASSERT_NE(dir_found, Direction::direction_max);
    ASSERT_EQ(dir_found, Direction::south);

    dir_found = Direction::direction_max;
    std::vector<Point> sulu_points = solver.findWordInAnyDirection("SULU", Point(3, 3), dir_found);
    ASSERT_EQ(sulu_points.size(), 4);
    ASSERT_EQ(dir_found, Direction::north_west);
    ASSERT_TRUE(sulu_points[0] == Point(3, 3));
    ASSERT_TRUE(sulu_points[1] == Point(2, 2));
    ASSERT_TRUE(sulu_points[2] == Point(1, 1));
    ASSERT_TRUE(sulu_points[3] == Point(0, 0));

    dir_found = Direction::direction_max;
    std::vector<Point> not_found_points = solver.findWordInAnyDirection("DOESNOTEXIST", Point(20, 50), dir_found);

    ASSERT_TRUE(not_found_points.empty());
    ASSERT_EQ(dir_found, Direction::direction_max);

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

TEST(TestWordSaerchSolver, TestWordSearchFindSingleWord)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    WordSearchSolver solver(grid);

    std::vector<Point> bones_points;
    ASSERT_NO_THROW(bones_points = solver.findWord("BONES"));
    ASSERT_EQ(bones_points.size(), 5);

}