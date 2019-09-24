#include <gtest/gtest.h>
#include "Empty.h"

// Empty test to make sure build systems are working

TEST(TestTests, empty) {
    Empty e(8);
    e.nothing();
}
