#include <gtest/gtest.h>
#include "common/type_id.h"

using namespace mkr;

TEST(type_id, base_derived) {
    struct base {};
    struct derived_a : public base {};
    struct derived_b : public base {};
    struct foo {};

    auto id_1 = type_id<base>::value<derived_a>();
    auto id_2 = type_id<base>::value<derived_a>();
    auto id_3 = type_id<base>::value<derived_b>();

    EXPECT_TRUE(id_1 == id_2);
    EXPECT_TRUE(id_1 != id_3);
}