/**
 * This file tests main functionality.
 *
 * @note In some tests, the main program will output data. This kinda makes the test output look bad, and
 * could break a test output parser. To that end I am setting the failbit on cout any time we expect output
 * through that stream. Afterwards, I set the goodbit in order to revert this.
 */
#include "gtest/gtest.h"
#include "src/main.hpp"

/**
 * Test that the argument parsing is correct.
 */
TEST(TestAltMain, TestAltMainParameters)
{
    std::cout.setstate(std::ios_base::failbit);

    // Adding two char*'s here is a hack.
    char* args[] = {(char*)"WordSearchKata", (char*)"./data/ProvidedWordSearch.txt"};
    ASSERT_EQ(ALT_MAIN(2, args), SUCCESS);
    char* args2[] = {(char*)"WordSearchKata", (char*)"./data/doesntexist.txt"};
    ASSERT_EQ(ALT_MAIN(2, args2), INVALID_PARAMETERS);
    std::cout.setstate(std::ios_base::goodbit);
}

/**
 * Ensure that we can consume and properly process a word search not given to us, but
 * generated on our own.
 */
TEST(TestAlTMain, TestNonProvided)
{
    std::cout.setstate(std::ios_base::failbit);
    char* args[] = {(char*)"WordSearchKata", (char*)"./data/NextGen.txt"};
    ASSERT_EQ(ALT_MAIN(2, args), SUCCESS);
    std::cout.setstate(std::ios_base::goodbit);
}