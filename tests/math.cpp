/* 
 * (c) Ryozuki See LICENSE.txt in the root of the distribution for more information.
 * If you are missing that file, acquire a complete release at https://github.com/Ryozuki/GForce
 */

#include <GForce/Math.hpp>
#include <gtest/gtest.h>
#include <cmath>

TEST(Maths, ToDegrees)
{
    EXPECT_DOUBLE_EQ(gf::Math::toDegrees(0), 0);
    EXPECT_DOUBLE_EQ(gf::Math::toDegrees(M_PI), 180);
    EXPECT_DOUBLE_EQ(gf::Math::toDegrees(2 * M_PI), 360);
    EXPECT_DOUBLE_EQ(gf::Math::toDegrees(M_PI / 2.0), 90);
    EXPECT_DOUBLE_EQ(gf::Math::toDegrees((2.0 / 3.0) * M_PI), 120);
    EXPECT_DOUBLE_EQ(gf::Math::toDegrees((4.0 / 9.0) * M_PI), 80);
}

TEST(Maths, ToRadians)
{
    EXPECT_DOUBLE_EQ(gf::Math::toRadians(0), 0);
    EXPECT_DOUBLE_EQ(gf::Math::toRadians(180), M_PI);
    EXPECT_DOUBLE_EQ(gf::Math::toRadians(360), 2 * M_PI);
    EXPECT_DOUBLE_EQ(gf::Math::toRadians(90), M_PI / 2.0);
    EXPECT_DOUBLE_EQ(gf::Math::toRadians(120), (2.0 / 3.0) * M_PI);
    EXPECT_DOUBLE_EQ(gf::Math::toRadians(80), (4.0 / 9.0) * M_PI);
}
