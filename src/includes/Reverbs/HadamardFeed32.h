#pragma once

namespace AbacDsp
{
inline void hadamardFeed32(const float* col, float* sum) noexcept
{
    sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
             col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
             col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
             col[31];
    sum[1] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
             col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
             col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
             col[31];
    sum[2] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
             col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] + col[20] +
             col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
             col[31];
    sum[3] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
             col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] + col[20] -
             col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
             col[31];
    sum[4] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] + col[10] +
             col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] + col[19] - col[20] -
             col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
             col[31];
    sum[5] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] -
             col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] - col[19] - col[20] +
             col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
             col[31];
    sum[6] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
             col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
             col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
             col[31];
    sum[7] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
             col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
             col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
             col[31];
    sum[8] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
             col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
             col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] - col[28] - col[29] - col[30] -
             col[31];
    sum[9] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
             col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
             col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
             col[31];
    sum[10] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
              col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19] + col[20] +
              col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] + col[30] +
              col[31];
    sum[11] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] + col[20] -
              col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] + col[30] -
              col[31];
    sum[12] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] - col[20] -
              col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] + col[30] +
              col[31];
    sum[13] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
              col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19] - col[20] +
              col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] + col[30] -
              col[31];
    sum[14] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
              col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
              col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] + col[28] + col[29] - col[30] -
              col[31];
    sum[15] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
              col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
              col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] + col[28] - col[29] - col[30] +
              col[31];
    sum[16] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
              col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] - col[20] -
              col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] - col[28] - col[29] - col[30] -
              col[31];
    sum[17] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
              col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
              col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
              col[31];
    sum[18] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
              col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
              col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] + col[30] +
              col[31];
    sum[19] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
              col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
              col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] + col[30] -
              col[31];
    sum[20] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] + col[10] +
              col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
              col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] + col[30] +
              col[31];
    sum[21] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] -
              col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
              col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] + col[30] -
              col[31];
    sum[22] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
              col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] + col[20] +
              col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] + col[28] + col[29] - col[30] -
              col[31];
    sum[23] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
              col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] + col[20] -
              col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] + col[28] - col[29] - col[30] +
              col[31];
    sum[24] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
              col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] - col[19] - col[20] -
              col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
              col[31];
    sum[25] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
              col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
              col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
              col[31];
    sum[26] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
              col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
              col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
              col[31];
    sum[27] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
              col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
              col[31];
    sum[28] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
              col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
              col[31];
    sum[29] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
              col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
              col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
              col[31];
    sum[30] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
              col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] + col[20] +
              col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
              col[31];
    sum[31] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
              col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] + col[20] -
              col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
              col[31];
}
}
