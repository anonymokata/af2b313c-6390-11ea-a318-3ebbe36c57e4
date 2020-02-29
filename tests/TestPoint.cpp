//
// Created by jordan on 2/29/20.
//
#include "gtest/gtest.h"
#include "Point.hpp"

TEST(PointTests, TestPointConstructor)
{
    ASSERT_NO_THROW(Point p(5, 2));
}