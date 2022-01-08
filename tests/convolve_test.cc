#include <gtest/gtest.h>

#include <numlib/convolve.hh>

namespace nb = numlib;

TEST(ConvolveTest, ConvolveFull) {
    auto a = nb::Vector(std::vector<float>{1, 2, 3});
    auto v = nb::Vector(std::vector<float>{0, 1, 0.5});

    EXPECT_EQ(nb::Convolve(a, v, nb::ConvolveMode::FULL), nb::Vector(std::vector<float>{0.0, 1, 2.5, 4.0, 1.5}));
}

TEST(ConvolveTest, ConvolveSame) {
    auto a = nb::Vector(std::vector<float>{1, 2, 3});
    auto v = nb::Vector(std::vector<float>{0, 1, 0.5});

    EXPECT_EQ(nb::Convolve(a, v, nb::ConvolveMode::SAME), nb::Vector(std::vector<float>{1, 2.5, 4.0}));
}

TEST(ConvolveTest, ConvolveValid) {
    auto a = nb::Vector(std::vector<float>{1, 2, 3});
    auto v = nb::Vector(std::vector<float>{0, 1, 0.5});

    EXPECT_EQ(nb::Convolve(a, v, nb::ConvolveMode::VALID), nb::Vector(std::vector<float>{2.5}));
}
