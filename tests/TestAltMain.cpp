/**
 *
 */
#include "gtest/gtest.h"
#include "main.hpp"

TEST(TestAltMain, TestAltMainParameters)
{
    // Adding two char*'s here is a hack.
    char* args[] = {(char*)"WordSearchKata", (char*)"./data/ProvidedWordSearch.txt"};
    ASSERT_EQ(ALT_MAIN(2, args), SUCCESS);


}