#include <string>
#include "gtest/gtest.h"

// Empty test to make sure build systems are working

TEST(TestTests, empty) {
    SUCCEED();
    std::string s = "steve";
    EXPECT_EQ(s, "steve");
}
