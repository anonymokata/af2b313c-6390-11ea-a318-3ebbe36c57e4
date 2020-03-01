//
// Created by jordan on 2/29/20.
//
#include "gtest/gtest.h"
#include "Point.hpp"

/**
 * Test that the constructor has no errors, and sets X and Y appropriately.
 */
TEST(PointTests, TestPointConstructor)
{
    std::unique_ptr<Point> p = nullptr;
    ASSERT_NO_THROW(p = std::make_unique<Point>(12, 8));
    ASSERT_EQ(p->getX(), 12);
    ASSERT_EQ(p->getY(), 8);
}


/**
 * Test that getX and getY return sane values.
 *
 * This is effectively the sam as TestPointConstructor. They used to be different, but after
 * a refactor, the x and y properties became private, and getX and getY were used to get the values
 * of X and Y. This is kept for completeness and for historical rasons.
 */
TEST(PointTests, TestPointGetterXandY)
{
    std::unique_ptr<Point> p = std::make_unique<Point>(5, 2);

    ASSERT_EQ(p->getX(), 5);
    ASSERT_EQ(p->getY(), 2);
}

/**
 * Simple tests to ensure that calling that calling the individual setters
 * for each X and Y properly set those values and do not accidentally affect the
 * other.
 */
TEST(PointTests, TestPointSetterXandY)
{
    std::unique_ptr<Point> p = std::make_unique<Point>(5, 2);
    p->setX(12);
    ASSERT_EQ(p->getX(), 12);
    ASSERT_EQ(p->getY(), 2);

    p->setY(44);
    ASSERT_EQ(p->getX(), 12);
    ASSERT_EQ(p->getY(), 44);
}

/**
 * Test some simple addition of points using the overloaded operator.
 */
TEST(PointTests, TestPointAddition)
{
    Point a(1, 1);
    Point b(2, 2);
    Point z(0, 0);
    Point c = a + b;
    ASSERT_EQ(c.getX(), 3);
    ASSERT_EQ(c.getY(), 3);

    c = a + z;
    ASSERT_EQ(c.getX(), 1);
    ASSERT_EQ(c.getY(), 1);
}

TEST(PointTests, TestPointAdditionAndAssignment)
{
    Point a(1, 1);
    Point b(5, 5);

    a += b;
    ASSERT_EQ(a.getX(), 6);
    ASSERT_EQ(a.getY(), 6);
}

TEST(PointTests, TestPointEqualityOperatorOverride)
{
    Point a(1, 1);
    Point b(5, 5);
    Point c = a;
    Point d = b;
    // For some reason GTest really doesn't like to use 'a' and 'c' in an
    // ASSERT_EQ.
    ASSERT_TRUE(a == c);
    ASSERT_FALSE(a == d);


}