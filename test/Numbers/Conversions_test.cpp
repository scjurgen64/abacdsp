
#include "gtest/gtest.h"

#include "Numbers/Convert.h"


TEST(DspAudioAlgorithmsTests, getPanFactorNormalized)
{
    constexpr float epsilon = 1.0E-6f;
    float left, right;
    for (int i = -10; i <= 10; ++i)
    {
        auto f = static_cast<float>(i) / 10.f;
        Convert::getPanFactorNormalized(f, left, right);
        EXPECT_NEAR(left, std::cos((f + 1) / 2 * 3.1415926535 / 2.f), epsilon);
        EXPECT_NEAR(right, std::sin((f + 1) / 2 * 3.1415926535 / 2.f), epsilon);
    }
}
