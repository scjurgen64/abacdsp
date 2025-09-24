
#include "Delays/NaiveDelay.h"

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace AbacDsp::Test
{
TEST(NaiveDelayTest, simpleFeedAndEat)
{
    NaiveDelay<1000> sut(48000.f);
    sut.setSize(100);
    sut.step(1);
    for (size_t i = 0; i < 100; ++i)
    {
        EXPECT_EQ(sut.step(0), 0.f) << "failed at " << i;
    }
    EXPECT_GT(sut.step(0), 0.99f);
}
}