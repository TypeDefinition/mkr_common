#include <gtest/gtest.h>
#include "common/type_id.h"

using namespace mkr;

TEST(type_id, category) {
    struct category_a {};
    struct category_b {};

    struct foo {};
    struct bar {};
    struct baz {};

    auto id_1 = type_id<category_a>::value<foo>();
    auto id_2 = type_id<category_a>::value<foo>();
    auto id_3 = type_id<category_a>::value<baz>();

    EXPECT_TRUE(id_1 == id_2);
    EXPECT_FALSE(id_1 == id_3);

    auto id_4 = type_id<category_b>::value<foo>();
    auto id_5 = type_id<category_b>::value<bar>();
    auto id_6 = type_id<category_b>::value<baz>();

    EXPECT_FALSE(id_4 == id_5);
    EXPECT_FALSE(id_5 == id_6);
    EXPECT_FALSE(id_4 == id_6);
    EXPECT_TRUE(id_1 == id_4);
    EXPECT_FALSE(id_3 == id_6);
}