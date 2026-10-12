#include <gtest/gtest.h>
#include "vector.hpp"

TEST(VectorTest, IndexReturnsStoredElement) {
    Vector<int> v{1, 2, 3};
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(v[1], 2);
    EXPECT_EQ(v[2], 3);
}

TEST (VectorTest, MoveConstructor){
    Vector<int> v {1, 2, 3};
    Vector<int> a = v;
    EXPECT_EQ(a[0], 1);
    EXPECT_EQ(a[1], 2);
    EXPECT_EQ(a[2], 3);
}

TEST (VectorTest, VectorSize){
    Vector<int> v {1, 2, 3};
    EXPECT_EQ(v.size(), 3);
}

TEST (VectorTest, VectorEmpty){
    Vector<int> v {1, 2, 3};
    EXPECT_EQ(v.empty(), false);
    Vector<int> a (0);
    EXPECT_EQ(a.empty(), true);
}