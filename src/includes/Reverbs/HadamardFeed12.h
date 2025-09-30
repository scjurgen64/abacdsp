#pragma once

namespace AbacadDsp
{
void hadamardFeed12(const float* col, float* sum) noexcept
{
    sum[0] =
        col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] - col[10] - col[11];
    sum[1] =
        col[0] + col[1] + col[2] - col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] + col[10] - col[11];
    sum[2] =
        col[0] - col[1] + col[2] + col[3] - col[4] + col[5] + col[6] + col[7] - col[8] - col[9] - col[10] + col[11];
    sum[3] =
        col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] + col[7] + col[8] - col[9] - col[10] - col[11];
    sum[4] =
        col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] + col[7] + col[8] + col[9] - col[10] - col[11];
    sum[5] =
        col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] + col[9] + col[10] - col[11];
    sum[6] =
        col[0] - col[1] - col[2] - col[3] + col[4] - col[5] + col[6] + col[7] - col[8] + col[9] + col[10] + col[11];
    sum[7] =
        col[0] + col[1] - col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] + col[11];
    sum[8] =
        col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] + col[9] - col[10] + col[11];
    sum[9] =
        col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] - col[11];
    sum[10] =
        col[0] - col[1] + col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] + col[10] + col[11];
    sum[11] =
        col[0] + col[1] - col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] + col[9] - col[10] + col[11];
}
}
