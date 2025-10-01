#pragma once

namespace AbacDsp
{
inline void hadamardFeed60(const float* col, float* sum) noexcept
{
    sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
             col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
             col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
             col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
             col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
             col[51] + col[52] + col[53] + col[54] + col[55] + col[56] + col[57] + col[58] + col[59];
    sum[1] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
             col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
             col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
             col[31] - col[32] + col[33] - col[34] + col[35] - col[36] + col[37] - col[38] + col[39] - col[40] +
             col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] - col[50] +
             col[51] - col[52] + col[53] - col[54] + col[55] - col[56] + col[57] - col[58] + col[59];
    sum[2] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
             col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19] + col[20] +
             col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
             col[31] - col[32] - col[33] + col[34] + col[35] - col[36] - col[37] - col[38] - col[39] - col[40] -
             col[41] + col[42] + col[43] - col[44] - col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
             col[51] + col[52] + col[53] - col[54] - col[55] - col[56] - col[57] + col[58] + col[59];
    sum[3] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
             col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] + col[20] -
             col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
             col[31] - col[32] + col[33] + col[34] - col[35] - col[36] + col[37] - col[38] + col[39] - col[40] +
             col[41] + col[42] - col[43] - col[44] + col[45] + col[46] - col[47] + col[48] - col[49] + col[50] -
             col[51] + col[52] - col[53] - col[54] + col[55] - col[56] + col[57] + col[58] - col[59];
    sum[4] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
             col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] - col[20] -
             col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
             col[31] - col[32] - col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] - col[40] -
             col[41] - col[42] - col[43] + col[44] + col[45] - col[46] - col[47] + col[48] + col[49] + col[50] +
             col[51] + col[52] + col[53] + col[54] + col[55] - col[56] - col[57] - col[58] - col[59];
    sum[5] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
             col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19] - col[20] +
             col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
             col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] - col[40] +
             col[41] - col[42] + col[43] + col[44] - col[45] - col[46] + col[47] + col[48] - col[49] + col[50] -
             col[51] + col[52] - col[53] + col[54] - col[55] - col[56] + col[57] - col[58] + col[59];
    sum[6] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] - col[10] -
             col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
             col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] - col[30] -
             col[31] + col[32] + col[33] - col[34] - col[35] - col[36] - col[37] + col[38] + col[39] - col[40] -
             col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47] - col[48] - col[49] + col[50] +
             col[51] + col[52] + col[53] + col[54] + col[55] + col[56] + col[57] - col[58] - col[59];
    sum[7] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] - col[10] +
             col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
             col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
             col[31] + col[32] - col[33] - col[34] + col[35] - col[36] + col[37] + col[38] - col[39] - col[40] +
             col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47] - col[48] + col[49] + col[50] -
             col[51] + col[52] - col[53] + col[54] - col[55] + col[56] - col[57] - col[58] + col[59];
    sum[8] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] + col[10] +
             col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
             col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
             col[31] - col[32] - col[33] + col[34] + col[35] - col[36] - col[37] - col[38] - col[39] + col[40] +
             col[41] - col[42] - col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] - col[50] -
             col[51] + col[52] + col[53] + col[54] + col[55] + col[56] + col[57] + col[58] + col[59];
    sum[9] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] - col[9] + col[10] -
             col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
             col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
             col[31] - col[32] + col[33] + col[34] - col[35] - col[36] + col[37] - col[38] + col[39] + col[40] -
             col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] - col[50] +
             col[51] + col[52] - col[53] + col[54] - col[55] + col[56] - col[57] + col[58] - col[59];
    sum[10] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] + col[10] -
              col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] + col[20] +
              col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
              col[31] - col[32] - col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] - col[40] -
              col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47] - col[48] - col[49] + col[50] +
              col[51] - col[52] - col[53] + col[54] + col[55] + col[56] + col[57] + col[58] + col[59];
    sum[11] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] - col[10] -
              col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] + col[20] -
              col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
              col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] - col[40] +
              col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] + col[50] -
              col[51] - col[52] + col[53] + col[54] - col[55] + col[56] - col[57] + col[58] - col[59];
    sum[12] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
              col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
              col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] - col[28] - col[29] + col[30] +
              col[31] - col[32] - col[33] - col[34] - col[35] - col[36] - col[37] + col[38] + col[39] - col[40] -
              col[41] - col[42] - col[43] + col[44] + col[45] - col[46] - col[47] - col[48] - col[49] - col[50] -
              col[51] + col[52] + col[53] - col[54] - col[55] + col[56] + col[57] + col[58] + col[59];
    sum[13] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
              col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] - col[28] + col[29] + col[30] -
              col[31] - col[32] + col[33] - col[34] + col[35] - col[36] + col[37] + col[38] - col[39] - col[40] +
              col[41] - col[42] + col[43] + col[44] - col[45] - col[46] + col[47] - col[48] + col[49] - col[50] +
              col[51] + col[52] - col[53] - col[54] + col[55] + col[56] - col[57] + col[58] - col[59];
    sum[14] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] + col[14] - col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
              col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] - col[30] -
              col[31] + col[32] + col[33] - col[34] - col[35] - col[36] - col[37] - col[38] - col[39] + col[40] +
              col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47] - col[48] - col[49] - col[50] -
              col[51] - col[52] - col[53] + col[54] + col[55] - col[56] - col[57] + col[58] + col[59];
    sum[15] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
              col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
              col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] - col[30] +
              col[31] + col[32] - col[33] - col[34] + col[35] - col[36] + col[37] - col[38] + col[39] + col[40] -
              col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47] - col[48] + col[49] - col[50] +
              col[51] - col[52] + col[53] + col[54] - col[55] - col[56] + col[57] + col[58] - col[59];
    sum[16] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
              col[11] - col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] + col[19] - col[20] -
              col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
              col[31] - col[32] - col[33] + col[34] + col[35] - col[36] - col[37] - col[38] - col[39] - col[40] -
              col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] - col[50] -
              col[51] - col[52] - col[53] - col[54] - col[55] + col[56] + col[57] - col[58] - col[59];
    sum[17] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
              col[11] - col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] - col[19] - col[20] +
              col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
              col[31] - col[32] + col[33] + col[34] - col[35] - col[36] + col[37] - col[38] + col[39] - col[40] +
              col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] - col[50] +
              col[51] - col[52] + col[53] - col[54] + col[55] + col[56] - col[57] - col[58] + col[59];
    sum[18] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
              col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] - col[19] + col[20] +
              col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
              col[31] + col[32] + col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] - col[40] -
              col[41] - col[42] - col[43] + col[44] + col[45] - col[46] - col[47] - col[48] - col[49] + col[50] +
              col[51] - col[52] - col[53] - col[54] - col[55] - col[56] - col[57] + col[58] + col[59];
    sum[19] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
              col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] - col[19] + col[20] -
              col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
              col[31] + col[32] - col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] - col[40] +
              col[41] - col[42] + col[43] + col[44] - col[45] - col[46] + col[47] - col[48] + col[49] + col[50] -
              col[51] - col[52] + col[53] - col[54] + col[55] - col[56] + col[57] + col[58] - col[59];
    sum[20] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
              col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] + col[20] -
              col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] + col[30] +
              col[31] + col[32] + col[33] + col[34] + col[35] - col[36] - col[37] + col[38] + col[39] - col[40] -
              col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47] - col[48] - col[49] - col[50] -
              col[51] + col[52] + col[53] - col[54] - col[55] - col[56] - col[57] - col[58] - col[59];
    sum[21] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
              col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] - col[20] -
              col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] + col[30] -
              col[31] + col[32] - col[33] + col[34] - col[35] - col[36] + col[37] + col[38] - col[39] - col[40] +
              col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47] - col[48] + col[49] - col[50] +
              col[51] + col[52] - col[53] - col[54] + col[55] - col[56] + col[57] - col[58] + col[59];
    sum[22] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] + col[10] +
              col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
              col[21] + col[22] - col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
              col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] - col[38] - col[39] + col[40] +
              col[41] - col[42] - col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] - col[50] -
              col[51] - col[52] - col[53] + col[54] + col[55] - col[56] - col[57] - col[58] - col[59];
    sum[23] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] + col[10] -
              col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
              col[21] - col[22] - col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
              col[31] + col[32] - col[33] + col[34] - col[35] + col[36] - col[37] - col[38] + col[39] + col[40] -
              col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] - col[50] +
              col[51] - col[52] + col[53] + col[54] - col[55] - col[56] + col[57] - col[58] + col[59];
    sum[24] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
              col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
              col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
              col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] - col[40] -
              col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47] - col[48] - col[49] + col[50] +
              col[51] - col[52] - col[53] - col[54] - col[55] + col[56] + col[57] - col[58] - col[59];
    sum[25] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
              col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
              col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
              col[31] + col[32] - col[33] + col[34] - col[35] + col[36] - col[37] + col[38] - col[39] - col[40] +
              col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] + col[50] -
              col[51] - col[52] + col[53] - col[54] + col[55] + col[56] - col[57] - col[58] + col[59];
    sum[26] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
              col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] - col[20] -
              col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27] + col[28] + col[29] - col[30] -
              col[31] - col[32] - col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
              col[41] - col[42] - col[43] + col[44] + col[45] - col[46] - col[47] - col[48] - col[49] - col[50] -
              col[51] + col[52] + col[53] - col[54] - col[55] - col[56] - col[57] + col[58] + col[59];
    sum[27] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
              col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19] - col[20] +
              col[21] - col[22] + col[23] + col[24] - col[25] - col[26] - col[27] + col[28] - col[29] - col[30] +
              col[31] - col[32] + col[33] + col[34] - col[35] + col[36] - col[37] + col[38] - col[39] + col[40] -
              col[41] - col[42] + col[43] + col[44] - col[45] - col[46] + col[47] - col[48] + col[49] - col[50] +
              col[51] + col[52] - col[53] - col[54] + col[55] - col[56] + col[57] + col[58] - col[59];
    sum[28] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
              col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
              col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] + col[28] - col[29] + col[30] +
              col[31] - col[32] - col[33] - col[34] - col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
              col[41] + col[42] + col[43] - col[44] - col[45] + col[46] + col[47] - col[48] - col[49] - col[50] -
              col[51] - col[52] - col[53] + col[54] + col[55] - col[56] - col[57] - col[58] - col[59];
    sum[29] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
              col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] - col[28] - col[29] + col[30] -
              col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] + col[38] - col[39] + col[40] -
              col[41] + col[42] - col[43] - col[44] + col[45] + col[46] - col[47] - col[48] + col[49] - col[50] +
              col[51] - col[52] + col[53] + col[54] - col[55] - col[56] + col[57] - col[58] + col[59];
    sum[30] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
              col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] + col[30] -
              col[31] + col[32] + col[33] - col[34] - col[35] - col[36] - col[37] + col[38] + col[39] + col[40] +
              col[41] + col[42] + col[43] + col[44] + col[45] - col[46] - col[47] + col[48] + col[49] - col[50] -
              col[51] - col[52] - col[53] - col[54] - col[55] + col[56] + col[57] - col[58] - col[59];
    sum[31] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
              col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
              col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] - col[30] -
              col[31] + col[32] - col[33] - col[34] + col[35] - col[36] + col[37] + col[38] - col[39] + col[40] -
              col[41] + col[42] - col[43] + col[44] - col[45] - col[46] + col[47] + col[48] - col[49] - col[50] +
              col[51] - col[52] + col[53] - col[54] + col[55] + col[56] - col[57] - col[58] + col[59];
    sum[32] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
              col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] + col[20] +
              col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
              col[31] + col[32] - col[33] + col[34] + col[35] - col[36] - col[37] - col[38] - col[39] + col[40] +
              col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] - col[48] - col[49] + col[50] +
              col[51] - col[52] - col[53] - col[54] - col[55] - col[56] - col[57] + col[58] + col[59];
    sum[33] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
              col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] + col[20] -
              col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
              col[31] - col[32] - col[33] + col[34] - col[35] - col[36] + col[37] - col[38] + col[39] + col[40] -
              col[41] + col[42] - col[43] + col[44] - col[45] + col[46] - col[47] - col[48] + col[49] + col[50] -
              col[51] - col[52] + col[53] - col[54] + col[55] - col[56] + col[57] + col[58] - col[59];
    sum[34] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
              col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] + col[20] +
              col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
              col[31] + col[32] + col[33] + col[34] - col[35] + col[36] + col[37] - col[38] - col[39] - col[40] -
              col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] - col[50] -
              col[51] + col[52] + col[53] - col[54] - col[55] - col[56] - col[57] - col[58] - col[59];
    sum[35] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
              col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] + col[20] -
              col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
              col[31] + col[32] - col[33] - col[34] - col[35] + col[36] - col[37] - col[38] + col[39] - col[40] +
              col[41] + col[42] - col[43] + col[44] - col[45] + col[46] - col[47] + col[48] - col[49] - col[50] +
              col[51] + col[52] - col[53] - col[54] + col[55] - col[56] + col[57] - col[58] + col[59];
    sum[36] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
              col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
              col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] - col[30] -
              col[31] - col[32] - col[33] + col[34] + col[35] + col[36] - col[37] + col[38] + col[39] - col[40] -
              col[41] - col[42] - col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
              col[51] - col[52] - col[53] + col[54] + col[55] - col[56] - col[57] - col[58] - col[59];
    sum[37] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
              col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] - col[30] +
              col[31] - col[32] + col[33] + col[34] - col[35] - col[36] - col[37] + col[38] - col[39] - col[40] +
              col[41] - col[42] + col[43] + col[44] - col[45] + col[46] - col[47] + col[48] - col[49] + col[50] -
              col[51] - col[52] + col[53] + col[54] - col[55] - col[56] + col[57] - col[58] + col[59];
    sum[38] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
              col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
              col[31] - col[32] - col[33] - col[34] - col[35] + col[36] + col[37] + col[38] - col[39] + col[40] +
              col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
              col[51] + col[52] + col[53] - col[54] - col[55] + col[56] + col[57] - col[58] - col[59];
    sum[39] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
              col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
              col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
              col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] - col[38] - col[39] + col[40] -
              col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47] + col[48] - col[49] + col[50] -
              col[51] + col[52] - col[53] - col[54] + col[55] + col[56] - col[57] - col[58] + col[59];
    sum[40] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
              col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] - col[20] -
              col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
              col[31] + col[32] + col[33] - col[34] - col[35] - col[36] - col[37] + col[38] + col[39] + col[40] -
              col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] + col[50] +
              col[51] + col[52] + col[53] + col[54] + col[55] - col[56] - col[57] + col[58] + col[59];
    sum[41] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
              col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
              col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
              col[31] + col[32] - col[33] - col[34] + col[35] - col[36] + col[37] + col[38] - col[39] - col[40] -
              col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] + col[50] -
              col[51] + col[52] - col[53] + col[54] - col[55] - col[56] + col[57] + col[58] - col[59];
    sum[42] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
              col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
              col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] + col[28] + col[29] + col[30] +
              col[31] + col[32] + col[33] + col[34] + col[35] - col[36] - col[37] - col[38] - col[39] + col[40] +
              col[41] + col[42] - col[43] + col[44] + col[45] - col[46] - col[47] - col[48] - col[49] + col[50] +
              col[51] + col[52] + col[53] + col[54] + col[55] + col[56] + col[57] - col[58] - col[59];
    sum[43] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
              col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] + col[28] - col[29] + col[30] -
              col[31] + col[32] - col[33] + col[34] - col[35] - col[36] + col[37] - col[38] + col[39] + col[40] -
              col[41] - col[42] - col[43] + col[44] - col[45] - col[46] + col[47] - col[48] + col[49] + col[50] -
              col[51] + col[52] - col[53] + col[54] - col[55] + col[56] - col[57] - col[58] + col[59];
    sum[44] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] - col[10] -
              col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
              col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] + col[30] +
              col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] - col[38] - col[39] - col[40] -
              col[41] + col[42] + col[43] + col[44] - col[45] + col[46] + col[47] - col[48] - col[49] - col[50] -
              col[51] + col[52] + col[53] + col[54] + col[55] + col[56] + col[57] + col[58] + col[59];
    sum[45] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
              col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
              col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] + col[30] -
              col[31] + col[32] - col[33] + col[34] - col[35] + col[36] - col[37] - col[38] + col[39] - col[40] +
              col[41] + col[42] - col[43] - col[44] - col[45] + col[46] - col[47] - col[48] + col[49] - col[50] +
              col[51] + col[52] - col[53] + col[54] - col[55] + col[56] - col[57] + col[58] - col[59];
    sum[46] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
              col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
              col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
              col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] - col[40] -
              col[41] - col[42] - col[43] + col[44] + col[45] + col[46] - col[47] + col[48] + col[49] - col[50] -
              col[51] - col[52] - col[53] + col[54] + col[55] + col[56] + col[57] + col[58] + col[59];
    sum[47] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
              col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
              col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
              col[31] + col[32] - col[33] + col[34] - col[35] + col[36] - col[37] + col[38] - col[39] - col[40] +
              col[41] - col[42] + col[43] + col[44] - col[45] - col[46] - col[47] + col[48] - col[49] - col[50] +
              col[51] - col[52] + col[53] + col[54] - col[55] + col[56] - col[57] + col[58] - col[59];
    sum[48] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
              col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
              col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
              col[31] - col[32] - col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
              col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47] + col[48] - col[49] + col[50] +
              col[51] - col[52] - col[53] - col[54] - col[55] + col[56] + col[57] + col[58] + col[59];
    sum[49] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
              col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
              col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
              col[31] - col[32] + col[33] + col[34] - col[35] + col[36] - col[37] + col[38] - col[39] + col[40] -
              col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47] - col[48] - col[49] + col[50] -
              col[51] - col[52] + col[53] - col[54] + col[55] + col[56] - col[57] + col[58] - col[59];
    sum[50] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
              col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
              col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] - col[30] -
              col[31] + col[32] + col[33] - col[34] - col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
              col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] + col[50] -
              col[51] + col[52] + col[53] - col[54] - col[55] - col[56] - col[57] + col[58] + col[59];
    sum[51] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
              col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
              col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
              col[31] + col[32] - col[33] - col[34] + col[35] + col[36] - col[37] + col[38] - col[39] + col[40] -
              col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] - col[50] -
              col[51] + col[52] - col[53] - col[54] + col[55] - col[56] + col[57] + col[58] - col[59];
    sum[52] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
              col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
              col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
              col[31] - col[32] - col[33] + col[34] + col[35] - col[36] - col[37] + col[38] + col[39] + col[40] +
              col[41] + col[42] + col[43] + col[44] + col[45] - col[46] - col[47] - col[48] - col[49] + col[50] +
              col[51] + col[52] - col[53] + col[54] + col[55] - col[56] - col[57] - col[58] - col[59];
    sum[53] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
              col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
              col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
              col[31] - col[32] + col[33] + col[34] - col[35] - col[36] + col[37] + col[38] - col[39] + col[40] -
              col[41] + col[42] - col[43] + col[44] - col[45] - col[46] + col[47] - col[48] + col[49] + col[50] -
              col[51] - col[52] - col[53] + col[54] - col[55] - col[56] + col[57] - col[58] + col[59];
    sum[54] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
              col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] - col[20] -
              col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
              col[31] - col[32] - col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] + col[40] +
              col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] - col[48] - col[49] - col[50] -
              col[51] + col[52] + col[53] + col[54] - col[55] + col[56] + col[57] - col[58] - col[59];
    sum[55] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
              col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
              col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
              col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] + col[40] -
              col[41] + col[42] - col[43] + col[44] - col[45] + col[46] - col[47] - col[48] + col[49] - col[50] +
              col[51] + col[52] - col[53] - col[54] - col[55] + col[56] - col[57] - col[58] + col[59];
    sum[56] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
              col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
              col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
              col[31] - col[32] - col[33] - col[34] - col[35] - col[36] - col[37] + col[38] + col[39] - col[40] -
              col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] - col[50] -
              col[51] - col[52] - col[53] + col[54] + col[55] + col[56] - col[57] + col[58] + col[59];
    sum[57] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
              col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
              col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
              col[31] - col[32] + col[33] - col[34] + col[35] - col[36] + col[37] + col[38] - col[39] - col[40] +
              col[41] + col[42] - col[43] + col[44] - col[45] + col[46] - col[47] + col[48] - col[49] - col[50] +
              col[51] - col[52] + col[53] + col[54] - col[55] - col[56] - col[57] + col[58] - col[59];
    sum[58] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] + col[10] +
              col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
              col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
              col[31] + col[32] + col[33] - col[34] - col[35] - col[36] - col[37] - col[38] - col[39] + col[40] +
              col[41] - col[42] - col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
              col[51] - col[52] - col[53] - col[54] - col[55] + col[56] + col[57] + col[58] - col[59];
    sum[59] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] -
              col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
              col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
              col[31] + col[32] - col[33] - col[34] + col[35] - col[36] + col[37] - col[38] + col[39] + col[40] -
              col[41] - col[42] + col[43] + col[44] - col[45] + col[46] - col[47] + col[48] - col[49] + col[50] -
              col[51] - col[52] + col[53] - col[54] + col[55] + col[56] - col[57] - col[58] - col[59];
}
}
