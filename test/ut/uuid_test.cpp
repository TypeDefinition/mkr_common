#include <gtest/gtest.h>
#include "common/uuid.h"

using namespace mkr;

TEST(uuid, randomness) {
    uuid a, b, c;
    EXPECT_TRUE(a != b);
    EXPECT_TRUE(b != c);
    EXPECT_TRUE(c != a);
    EXPECT_TRUE(a == a);
    EXPECT_TRUE(b == b);
    EXPECT_TRUE(c == c);
}