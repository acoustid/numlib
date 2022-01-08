#include <gtest/gtest.h>

#include <numlib/base.hh>

namespace nb = numlib;

TEST(BaseTest, StdVector) {
    EXPECT_EQ(nb::Size(std::vector<float>{}), 0u);
    EXPECT_EQ(nb::Size(std::vector<float>{1, 2, 3}), 3u);

    auto v = nb::Vector(std::vector<float>{1, 2, 3});
    EXPECT_EQ(nb::Size(v), 3u);
    EXPECT_EQ(v[0], 1.0f);
    EXPECT_EQ(v[1], 2.0f);
    EXPECT_EQ(v[2], 3.0f);

    nb::Resize(v, 4);
    EXPECT_EQ(nb::Size(v), 4u);
}

TEST(BaseTest, StdArray) {
    EXPECT_EQ(nb::Size(std::array<float, 0>{}), 0u);
    EXPECT_EQ(nb::Size(std::array<float, 3>{1, 2, 3}), 3u);

    auto v = nb::Vector(std::array<float, 3>{1, 2, 3});
    EXPECT_EQ(nb::Size(v), 3u);
    EXPECT_EQ(v[0], 1.0f);
    EXPECT_EQ(v[1], 2.0f);
    EXPECT_EQ(v[2], 3.0f);
}

TEST(BaseTest, StdPair) {
    EXPECT_EQ(nb::Size(std::make_pair(1, 2)), 2u);
}

TEST(BaseTest, StdTuple) {
    EXPECT_EQ(nb::Size(std::make_tuple(0.0, 1.1)), 2u);
}

TEST(BaseTest, ArrayPtr) {
    std::vector<float> vd{1, 2, 3};

    auto v = nb::Vector(vd.data(), vd.size());
    EXPECT_EQ(nb::Size(v), 3u);
    EXPECT_EQ(v[0], 1.0f);
    EXPECT_EQ(v[1], 2.0f);
    EXPECT_EQ(v[2], 3.0f);
}

TEST(BaseTest, OwnedArrayPtr) {
    float *data = (float *) malloc(sizeof(float) * 3);
    data[0] = 1.0f;
    data[1] = 2.0f;
    data[2] = 3.0f;

    bool free_called = false;

    {
        auto v = nb::Vector(data, 3, [&](auto ptr){ free_called = true; free(ptr); });
        EXPECT_EQ(nb::Size(v), 3u);
        EXPECT_EQ(v[0], 1.0f);
        EXPECT_EQ(v[1], 2.0f);
        EXPECT_EQ(v[2], 3.0f);
    }

    EXPECT_TRUE(free_called);
}
