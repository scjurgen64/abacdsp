#pragma once

namespace AbacDsp
{
inline void hadamardFeed20(const float* col, float* sum) noexcept
{
    sum[0] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] - col[10] -
             col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19];
    sum[1] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] + col[7] + col[8] + col[9] - col[10] +
             col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] - col[18] - col[19];
    sum[2] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] + col[9] + col[10] -
             col[11] + col[12] - col[13] - col[14] - col[15] - col[16] + col[17] + col[18] + col[19];
    sum[3] = col[0] - col[1] + col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] + col[9] - col[10] -
             col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19];
    sum[4] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] - col[9] - col[10] +
             col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] + col[19];
    sum[5] = col[0] + col[1] - col[2] + col[3] + col[4] + col[5] - col[6] + col[7] + col[8] + col[9] + col[10] -
             col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19];
    sum[6] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] + col[9] + col[10] +
             col[11] - col[12] + col[13] + col[14] - col[15] + col[16] + col[17] - col[18] + col[19];
    sum[7] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] - col[7] - col[8] + col[9] - col[10] +
             col[11] + col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] + col[19];
    sum[8] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] - col[6] - col[7] + col[8] - col[9] + col[10] -
             col[11] + col[12] + col[13] - col[14] + col[15] - col[16] - col[17] - col[18] + col[19];
    sum[9] = col[0] + col[1] - col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] + col[10] +
             col[11] + col[12] - col[13] + col[14] + col[15] - col[16] + col[17] + col[18] - col[19];
    sum[10] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] + col[7] + col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] + col[14] + col[15] + col[16] - col[17] + col[18] + col[19];
    sum[11] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] - col[10] +
              col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] - col[19];
    sum[12] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] - col[7] - col[8] + col[9] + col[10] +
              col[11] + col[12] + col[13] - col[14] + col[15] + col[16] + col[17] + col[18] - col[19];
    sum[13] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] + col[10] +
              col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] - col[18] - col[19];
    sum[14] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] +
              col[11] - col[12] - col[13] - col[14] + col[15] + col[16] + col[17] - col[18] + col[19];
    sum[15] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19];
    sum[16] = col[0] + col[1] + col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
              col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19];
    sum[17] = col[0] - col[1] - col[2] + col[3] - col[4] - col[5] - col[6] + col[7] - col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19];
    sum[18] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] + col[9] - col[10] +
              col[11] - col[12] + col[13] - col[14] + col[15] - col[16] - col[17] - col[18] + col[19];
    sum[19] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] + col[6] - col[7] - col[8] - col[9] + col[10] -
              col[11] - col[12] - col[13] - col[14] - col[15] + col[16] - col[17] + col[18] + col[19];
}
}
