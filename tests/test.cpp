//
// Created by Edgar on 04/09/2018.
//

#include <gtest/gtest.h>
#include <GForce/library.h>

TEST(TestCase, TestName)
{
    EXPECT_EQ(test(), 5);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
