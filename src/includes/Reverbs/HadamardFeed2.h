#pragma once

namespace AbacDsp
{
inline void hadamardFeed2(const float* col, float* sum) noexcept
{
    sum[0] = col[0] + col[1];
    sum[1] = col[0] - col[1];
}
}
