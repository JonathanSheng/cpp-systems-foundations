#include <gtest/gtest.h>
#include "vector.hpp"

TEST (VectorTest, TypeAgnostic){
    Vector<int> v {1, 2, 3};
    Vector<char> c {'a', 'b', 'c'};
    Vector<float> f {1.0, 2.0, 3.0};
    EXPECT_EQ(v[0], 1);
    EXPECT_EQ(c[0], 'a');
    EXPECT_EQ(f[0], 1.0);
}
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

TEST (VectorTest, Size){
    Vector<int> v {1, 2, 3};
    EXPECT_EQ(v.size(), 3);
}

TEST (VectorTest, Empty){
    Vector<int> v {1, 2, 3};
    EXPECT_EQ(v.empty(), false);
    Vector<int> a (0);
    EXPECT_EQ(a.empty(), true);
}

TEST(VectorTest, PushBack){
    Vector<int> v {1, 2,3 };
    EXPECT_EQ(v.back(), 3);
    v.push_back(4);
    EXPECT_EQ(v.back(), 4);
    EXPECT_EQ(v.size(), 4);
    EXPECT_EQ(v[3], 4);
}

TEST(VectorTest, PopBack){
    Vector<int> v {1, 2,3 };
    EXPECT_EQ(v.back(), 3);
    v.pop_back();
    EXPECT_EQ(v.back(), 2);
    EXPECT_EQ(v.size(), 2);
}

TEST(VectorTest, Insert){
    Vector<int> v {1, 2,3 };
    EXPECT_EQ(v[1], 2);
    v.insert(1, 5);
    EXPECT_EQ(v[1], 5);
    EXPECT_EQ(v.size(), 4);
}

TEST(VectorTest, Erase){
    Vector<int> v {1, 2,3 };
    v.erase(0);
    EXPECT_EQ(v[0], 2);
    EXPECT_EQ(v.size(), 2);
}

TEST(VectorTest, Clear){
    Vector<int> v {1, 2,3 };
    EXPECT_EQ(v.size(), 3);
    v.clear();
    EXPECT_EQ(v.size(), 0);
}

TEST (VectorTest, MemoryLimit){
    Vector<int> v {1, 2, 3};
    v.reserve(4);
    v.push_back(4);
    EXPECT_EQ(v.capacity(), 4);
    v.push_back(5);
    EXPECT_EQ(v.capacity(), 8);
    EXPECT_EQ(v.size(), 5);
}