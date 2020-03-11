/**
 * @file TestWordSolution.cpp
 *
 * Test the small logic that the WordSolution struct has associated with it.
 *
 * @author Jordan Sebastian
 */
#include "gtest/gtest.h"
#include "src/WordSolution.hpp"
#include <sstream>
#include <string>

/**
 * Test that the operator overloading of the stream operator (<<), will print to the given stream
 * the expected solution.
 */
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

    std::string not_found("DOESNTEXIST: Not Found");
    ss.str("");
    solution = {
            .word = "DOESNTEXIST",
            .points = std::vector<Point>(),
    };

    ss << solution;
    ASSERT_STREQ(ss.str().c_str(), not_found.c_str());
}