#include "gtest/gtest.h"
#include "src/NaiveSolver.hpp"
#include "src/WordGrid.hpp"
#include "src/FileReader.hpp"
#include <vector>
#include <string>
#include <map>
#include "TestConstants.hpp"
#include "src/WordSolution.hpp"
#include <array>

TEST(TestNaiveSolver, TestWordSearchConstructor)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    ASSERT_NO_THROW(NaiveSolver solver(grid));
}

TEST(TestNaiveSolver, TestWordSarchNaieveFindForwardInDirectionGivenStart)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    NaiveSolver solver(grid);

    std::vector<Point> bones_points = solver.searchAtPointAndDir("BONES", Point(0, 6), Direction::south);
    ASSERT_NE(bones_points.size(), 0);
    ASSERT_EQ(bones_points.size(), 5);
    ASSERT_TRUE(bones_points[0] == Point(0, 6));
    ASSERT_TRUE(bones_points[1] == Point(0, 7));
    ASSERT_TRUE(bones_points[2] == Point(0, 8));
    ASSERT_TRUE(bones_points[3] == Point(0, 9));
    ASSERT_TRUE(bones_points[4] == Point(0, 10));

    std::vector<Point> kahn_points = solver.searchAtPointAndDir("KHAN", Point(5, 9), Direction::north);
    ASSERT_EQ(kahn_points.size(), sizeof("KHAN") - 1);

    ASSERT_TRUE(kahn_points[0] == Point(5,9));
    ASSERT_TRUE(kahn_points[1] == Point(5,8));
    ASSERT_TRUE(kahn_points[2] == Point(5,7));
    ASSERT_TRUE(kahn_points[3] == Point(5,6));

}

TEST(TestNaiveSolver, FindWordInAnyDirectionGivenStartingPoint)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    NaiveSolver solver(grid);
    Direction dir_found = Direction::direction_max;
    std::vector<Point> bones_points = solver.searchAtPoint("BONES", Point(0, 6), dir_found);
    ASSERT_EQ(bones_points.size(), 5);
    ASSERT_TRUE(bones_points[0] == Point(0, 6));
    ASSERT_TRUE(bones_points[1] == Point(0, 7));
    ASSERT_TRUE(bones_points[2] == Point(0, 8));
    ASSERT_TRUE(bones_points[3] == Point(0, 9));
    ASSERT_TRUE(bones_points[4] == Point(0, 10));
    ASSERT_NE(dir_found, Direction::direction_max);
    ASSERT_EQ(dir_found, Direction::south);

    dir_found = Direction::direction_max;
    std::vector<Point> sulu_points = solver.searchAtPoint("SULU", Point(3, 3), dir_found);
    ASSERT_EQ(sulu_points.size(), 4);
    ASSERT_EQ(dir_found, Direction::north_west);
    ASSERT_TRUE(sulu_points[0] == Point(3, 3));
    ASSERT_TRUE(sulu_points[1] == Point(2, 2));
    ASSERT_TRUE(sulu_points[2] == Point(1, 1));
    ASSERT_TRUE(sulu_points[3] == Point(0, 0));

    dir_found = Direction::direction_max;
    std::vector<Point> not_found_points = solver.searchAtPoint("DOESNOTEXIST", Point(20, 50), dir_found);

    ASSERT_TRUE(not_found_points.empty());
    ASSERT_EQ(dir_found, Direction::direction_max);

}

TEST(TestNaiveSolver, TestWordSearchNieveFindWrongStart)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    NaiveSolver solver(grid);

    std::vector<Point> bones_points = solver.searchAtPointAndDir("BONES", Point(0, 0), Direction::south);
    ASSERT_EQ(bones_points.size(), 0);
}

TEST(TestNaiveSolver, TestWordSearchGoodStartWrongDirectionOutOfRange)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    NaiveSolver solver(grid);

    std::vector<Point> bones_points = solver.searchAtPointAndDir("BONES", Point(0, 5), Direction::west);
    ASSERT_EQ(bones_points.size(), 0);
}

TEST(TestNaiveSolver, TestWordSearchFindSingleWord)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    NaiveSolver solver(grid);

    std::vector<Point> bones_points;
    ASSERT_NO_THROW(bones_points = solver.searchForWord("BONES"));
    ASSERT_EQ(bones_points.size(), 5);

    ASSERT_TRUE(bones_points[0] == Point(0, 6));
    ASSERT_TRUE(bones_points[1] == Point(0, 7));
    ASSERT_TRUE(bones_points[2] == Point(0, 8));
    ASSERT_TRUE(bones_points[3] == Point(0, 9));
    ASSERT_TRUE(bones_points[4] == Point(0, 10));

    ASSERT_NO_THROW(bones_points = solver.searchForWord("DOESNTEXIST"));
    ASSERT_TRUE(bones_points.empty());

}

TEST(TestnaiveSolver, TestNaiveSolverFindWordEmptyString)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    NaiveSolver solver(grid);
    std::vector<Point> pts;

    ASSERT_THROW(pts = solver.searchForWord(""), std::logic_error);
    ASSERT_EQ(pts.size(), 0);
}


TEST(TestNaiveSolver, TestWordSearchSolvePuzzle)
{
    FileReader fileReader("./data/ProvidedWordSearch.txt");
    std::vector<std::string> lines = fileReader.readFileLines();
    WordGrid grid(lines);
    NaiveSolver solver(grid);

    std::vector<WordSolution> solutions = solver.solve();
    ASSERT_EQ(solutions.size(), WORDS_IN_PROVIDED_WORD_SEARCH);



    for (const auto& solution : solutions)
    {
        std::vector<Point>* current_word = nullptr;
        if (solution.word == "BONES")
        {
            current_word = &bones_solution;
        }
        else if (solution.word == "SULU")
        {
            current_word = &sulu_solution;
        }
        else if (solution.word == "KHAN")
        {
            current_word = &khan_solution;
        }
        else if (solution.word == "KIRK")
        {
            current_word = &kirk_solution;
        }
        else if (solution.word == "SCOTTY")
        {
            current_word = &scotty_solution;
        }
        else if (solution.word == "SPOCK")
        {
            current_word = &spock_solution;
        }
        else if (solution.word == "UHURA")
        {
            current_word = &uhura_solution;
        }

        // Ensure we didn't get another word we weren't expecting.
        ASSERT_NE(current_word, nullptr);
        ASSERT_TRUE(std::equal(current_word->begin(), current_word->end(), solution.points.begin()));

    }

}