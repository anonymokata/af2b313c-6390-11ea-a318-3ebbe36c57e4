//
// Created by jordan on 2/29/20.
//
#include "gtest/gtest.h"
#include "Point.hpp"

TEST(PointTests, TestPointConstructor)
{
    std::unique_ptr<Point> p = nullptr;
    ASSERT_NO_THROW(p = std::make_unique<Point>(5, 2));
    ASSERT_EQ(p->x, 5);
    ASSERT_EQ(p->y, 2);
}