#include "Directions.hpp"
#include "gtest/gtest.h"

TEST(DirectionTest, TestDirectionsIncrement)
{
    Directions dir = Directions::north;
    for (int i = 0; i < 9; i++)
    {
        switch(i)
        {
            case 0:
                ASSERT_EQ(dir, Directions::north);
                break;
            case 1:
                ASSERT_EQ(dir, Directions::north_east);
                break;
            case 2:
                ASSERT_EQ(dir, Directions::east);
                break;
            case 3:
                ASSERT_EQ(dir, Directions::south_east);
                break;
            case 4:
                ASSERT_EQ(dir, Directions::south);
                break;
            case 5:
                ASSERT_EQ(dir, Directions::south_west);
                break;
            case 6:
                ASSERT_EQ(dir, Directions::west);
                break;
            case 7:
                ASSERT_EQ(dir, Directions::north_west);
                break;
            case 8:
                ASSERT_EQ(dir, Directions::direction_max);
                break;
        }
        ++dir;
    }
    // Ensure that if we go past direction_max we get back to north.
    ASSERT_EQ(dir, Directions::north);

}