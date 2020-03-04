/**
 * This file tests main functionality.
 */
#include "gtest/gtest.h"
#include "main.hpp"

/**
 * Test that the argument parisng is correct.
 */
TEST(TestAltMain, TestAltMainParameters)
{
    // Adding two char*'s here is a hack.
    char* args[] = {(char*)"WordSearchKata", (char*)"./data/ProvidedWordSearch.txt"};
    ASSERT_EQ(ALT_MAIN(2, args), SUCCESS);
    char* args2[] = {(char*)"WordSearchKata", (char*)"./data/doesntexist.txt"};
    ASSERT_EQ(ALT_MAIN(2, args2), INVALID_PARAMETERS);
}

/**
 * Ensure that we can consume and properly process a word search not given to us, but
 * generated on our own.
 */
TEST(TestAlTMain, TestNonProvided)
{
    char* args[] = {(char*)"WordSearchKata", (char*)"./data/NextGen.txt"};
    ASSERT_EQ(ALT_MAIN(2, args), SUCCESS);
}