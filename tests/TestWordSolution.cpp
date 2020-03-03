#include "gtest/gtest.h"
#include "WordSolution.hpp"
#include <sstream>
#include <string>

TEST(TestWordSoluton, TestOuputOperator)
{
    std::string expected("SPOCK: (2,1),(3,2),(4,3),(5,4),(6,5)");
    std::vector<Point> spock_solution = {
            Point(2, 1),
            Point(3, 2),
            Point(4, 3),
            Point(5, 4),
            Point(6, 5),
    };

    WordSolution solution {
        .word = "SPOCK",
        .points = spock_solution,
    };

    std::stringstream ss;

    ss << solution;

    ASSERT_STREQ(ss.str().c_str(), expected.c_str());

}