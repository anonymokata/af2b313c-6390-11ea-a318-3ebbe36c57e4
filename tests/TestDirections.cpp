#include "src/Direction.hpp"
#include "gtest/gtest.h"

TEST(DirectionTest, TestDirectionsIncrement)
{
    Direction dir = Direction::north;
    for (int i = 0; i < 9; i++)
    {
        switch(i)
        {
            case 0:
                ASSERT_EQ(dir, Direction::north);
                break;
            case 1:
                ASSERT_EQ(dir, Direction::north_east);
                break;
            case 2:
                ASSERT_EQ(dir, Direction::east);
                break;
            case 3:
                ASSERT_EQ(dir, Direction::south_east);
                break;
            case 4:
                ASSERT_EQ(dir, Direction::south);
                break;
            case 5:
                ASSERT_EQ(dir, Direction::south_west);
                break;
            case 6:
                ASSERT_EQ(dir, Direction::west);
                break;
            case 7:
                ASSERT_EQ(dir, Direction::north_west);
                break;
            case 8:
                ASSERT_EQ(dir, Direction::direction_max);
                break;
        }
        ++dir;
    }
    // Ensure that if we go past direction_max we get back to north.
    ASSERT_EQ(dir, Direction::north);

}