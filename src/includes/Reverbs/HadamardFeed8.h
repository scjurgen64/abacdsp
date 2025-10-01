#pragma once

namespace AbacDsp
{
inline void hadamardFeed8(const float* col, float* sum) noexcept
{
    sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7];
    sum[1] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7];
    sum[2] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7];
    sum[3] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7];
    sum[4] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7];
    sum[5] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7];
    sum[6] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7];
    sum[7] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7];
}
}
