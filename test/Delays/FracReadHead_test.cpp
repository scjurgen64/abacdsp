
#include "Delays/FracReadHead.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace AbacDsp::Test
{

TEST(FracReadHeadTest, advancesLinear)
{
    constexpr size_t BufferSize{20};
    FracReadHead<BufferSize> sut(48000.f);
    size_t hd{0};
    for (size_t i = 0; i < 1024; ++i)
    {
        const auto s1 = sut.step(static_cast<float>(hd));
        hd = (hd + 1) % BufferSize;
        const auto s2 = sut.step(static_cast<float>(hd));
        hd = (hd + 1) % BufferSize;
        const auto delta = (static_cast<int>(s1) + 1 - static_cast<int>(s2)) % BufferSize;
        EXPECT_NEAR(delta, 0.f, 1E-6f) << "failed at step " << i << " with hd=" << hd;
    }
}

}