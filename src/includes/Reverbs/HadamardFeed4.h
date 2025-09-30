#pragma once

namespace AbacadDsp
{
void hadamardFeed4(const float* col, float* sum) noexcept
{
    sum[0] = col[0] + col[1] + col[2] + col[3];
    sum[1] = col[0] - col[1] + col[2] - col[3];
    sum[2] = col[0] + col[1] - col[2] - col[3];
    sum[3] = col[0] - col[1] - col[2] + col[3];
}
}
