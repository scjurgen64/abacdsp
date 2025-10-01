#pragma once


namespace AbacDsp
{
inline void hadamardFeed(const unsigned order, const float* col, float* sum) noexcept
{
    switch (order)
    {
        default:
            sum[0] = col[0];
            break;
        case 2:
            sum[0] = col[0] + col[1];
            sum[1] = col[0] - col[1];
            break;
        case 4:
            sum[0] = col[0] + col[1] + col[2] + col[3];
            sum[1] = col[0] - col[1] + col[2] - col[3];
            sum[2] = col[0] + col[1] - col[2] - col[3];
            sum[3] = col[0] - col[1] - col[2] + col[3];
            break;
        case 8:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7];
            sum[1] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7];
            sum[2] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7];
            sum[3] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7];
            sum[4] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7];
            sum[5] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7];
            sum[6] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7];
            sum[7] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7];
            break;
        case 12:
            sum[0] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] - col[10] -
                     col[11];
            sum[1] = col[0] + col[1] + col[2] - col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] + col[10] -
                     col[11];
            sum[2] = col[0] - col[1] + col[2] + col[3] - col[4] + col[5] + col[6] + col[7] - col[8] - col[9] - col[10] +
                     col[11];
            sum[3] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] + col[7] + col[8] - col[9] - col[10] -
                     col[11];
            sum[4] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] + col[7] + col[8] + col[9] - col[10] -
                     col[11];
            sum[5] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] + col[9] + col[10] -
                     col[11];
            sum[6] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] + col[6] + col[7] - col[8] + col[9] + col[10] +
                     col[11];
            sum[7] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] +
                     col[11];
            sum[8] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] + col[9] - col[10] +
                     col[11];
            sum[9] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
                     col[11];
            sum[10] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] +
                      col[10] + col[11];
            sum[11] = col[0] + col[1] - col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11];
            break;
        case 16:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15];
            sum[1] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
                     col[11] + col[12] - col[13] + col[14] - col[15];
            sum[2] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
                     col[11] + col[12] + col[13] - col[14] - col[15];
            sum[3] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
                     col[11] + col[12] - col[13] - col[14] + col[15];
            sum[4] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] + col[10] +
                     col[11] - col[12] - col[13] - col[14] - col[15];
            sum[5] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] - col[14] + col[15];
            sum[6] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
                     col[11] - col[12] - col[13] + col[14] + col[15];
            sum[7] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] - col[12] + col[13] + col[14] - col[15];
            sum[8] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
                     col[11] - col[12] - col[13] - col[14] - col[15];
            sum[9] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] - col[14] + col[15];
            sum[10] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15];
            sum[11] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15];
            sum[12] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15];
            sum[13] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15];
            sum[14] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15];
            sum[15] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15];
            break;
        case 20:
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
            sum[10] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] - col[17] + col[18] + col[19];
            sum[11] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] - col[19];
            sum[12] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] - col[7] - col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] + col[15] + col[16] + col[17] + col[18] - col[19];
            sum[13] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] - col[18] - col[19];
            sum[14] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] + col[15] + col[16] + col[17] - col[18] + col[19];
            sum[15] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19];
            sum[16] = col[0] + col[1] + col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19];
            sum[17] = col[0] - col[1] - col[2] + col[3] - col[4] - col[5] - col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19];
            sum[18] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] - col[17] - col[18] + col[19];
            sum[19] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] - col[17] + col[18] + col[19];
            break;
        case 24:
            sum[0] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] - col[7] - col[8] - col[9] - col[10] -
                     col[11] + col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
                     col[21] - col[22] + col[23];
            sum[1] = col[0] - col[1] + col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
                     col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] + col[19] - col[20] -
                     col[21] + col[22] + col[23];
            sum[2] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
                     col[11] + col[12] - col[13] - col[14] + col[15] + col[16] + col[17] + col[18] - col[19] + col[20] +
                     col[21] - col[22] - col[23];
            sum[3] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] -
                     col[11] - col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] + col[19] + col[20] +
                     col[21] - col[22] - col[23];
            sum[4] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] + col[7] + col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] + col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23];
            sum[5] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] - col[6] - col[7] + col[8] + col[9] + col[10] -
                     col[11] + col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
                     col[21] - col[22] - col[23];
            sum[6] = col[0] + col[1] - col[2] + col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] + col[10] +
                     col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] + col[19] + col[20] -
                     col[21] - col[22] - col[23];
            sum[7] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] - col[7] - col[8] - col[9] - col[10] +
                     col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23];
            sum[8] = col[0] - col[1] - col[2] + col[3] + col[4] + col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] + col[12] + col[13] - col[14] + col[15] - col[16] - col[17] - col[18] - col[19] - col[20] +
                     col[21] + col[22] - col[23];
            sum[9] = col[0] + col[1] + col[2] - col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] + col[10] +
                     col[11] - col[12] + col[13] + col[14] + col[15] + col[16] - col[17] + col[18] - col[19] - col[20] -
                     col[21] - col[22] + col[23];
            sum[10] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] + col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23];
            sum[11] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23];
            sum[12] = col[0] - col[1] + col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23];
            sum[13] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23];
            sum[14] = col[0] - col[1] - col[2] + col[3] - col[4] - col[5] + col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] + col[13] + col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] + col[23];
            sum[15] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] + col[22] + col[23];
            sum[16] = col[0] + col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23];
            sum[17] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23];
            sum[18] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] + col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23];
            sum[19] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] - col[16] + col[17] + col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23];
            sum[20] = col[0] - col[1] - col[2] - col[3] - col[4] + col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] + col[23];
            sum[21] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23];
            sum[22] = col[0] + col[1] - col[2] + col[3] - col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23];
            sum[23] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] - col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23];
            break;
        case 28:
            sum[0] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] + col[10] -
                     col[11] + col[12] - col[13] - col[14] + col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
                     col[21] - col[22] + col[23] - col[24] - col[25] + col[26] - col[27];
            sum[1] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
                     col[11] + col[12] + col[13] - col[14] - col[15] + col[16] - col[17] + col[18] + col[19] - col[20] -
                     col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27];
            sum[2] = col[0] - col[1] - col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] + col[9] + col[10] +
                     col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
                     col[21] - col[22] + col[23] + col[24] + col[25] - col[26] - col[27];
            sum[3] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] - col[10] -
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] - col[17] - col[18] + col[19] - col[20] -
                     col[21] - col[22] - col[23] - col[24] - col[25] - col[26] + col[27];
            sum[4] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] - col[10] +
                     col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] + col[19] - col[20] -
                     col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27];
            sum[5] = col[0] - col[1] + col[2] + col[3] - col[4] + col[5] - col[6] - col[7] + col[8] - col[9] + col[10] -
                     col[11] - col[12] - col[13] + col[14] - col[15] + col[16] + col[17] + col[18] + col[19] + col[20] -
                     col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27];
            sum[6] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] - col[9] - col[10] -
                     col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] - col[19] + col[20] -
                     col[21] - col[22] + col[23] + col[24] + col[25] + col[26] - col[27];
            sum[7] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] -
                     col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] + col[20] +
                     col[21] - col[22] + col[23] + col[24] - col[25] - col[26] - col[27];
            sum[8] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] + col[9] + col[10] -
                     col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] + col[19] - col[20] +
                     col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27];
            sum[9] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] - col[6] - col[7] - col[8] - col[9] + col[10] -
                     col[11] + col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
                     col[21] + col[22] - col[23] + col[24] + col[25] - col[26] + col[27];
            sum[10] = col[0] + col[1] + col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] + col[25] - col[26] + col[27];
            sum[11] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] - col[12] + col[13] - col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] + col[24] - col[25] + col[26] + col[27];
            sum[12] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] + col[25] + col[26] + col[27];
            sum[13] = col[0] + col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] + col[25] + col[26] - col[27];
            sum[14] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27];
            sum[15] = col[0] - col[1] - col[2] + col[3] + col[4] + col[5] - col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] - col[27];
            sum[16] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] + col[27];
            sum[17] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] + col[27];
            sum[18] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] - col[22] - col[23] - col[24] + col[25] + col[26] + col[27];
            sum[19] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] + col[25] + col[26] - col[27];
            sum[20] = col[0] + col[1] + col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] + col[13] + col[14] + col[15] - col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] + col[27];
            sum[21] = col[0] + col[1] - col[2] + col[3] - col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] + col[25] + col[26] + col[27];
            sum[22] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] - col[25] - col[26] + col[27];
            sum[23] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] - col[25] + col[26] - col[27];
            sum[24] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] - col[27];
            sum[25] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] - col[25] - col[26] - col[27];
            sum[26] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] - col[25] - col[26] - col[27];
            sum[27] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] + col[9] -
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27];
            break;
        case 32:
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
            sum[10] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31];
            sum[11] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31];
            sum[12] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31];
            sum[13] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31];
            sum[14] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31];
            sum[15] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31];
            sum[16] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31];
            sum[17] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31];
            sum[18] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31];
            sum[19] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31];
            sum[20] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31];
            sum[21] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31];
            sum[22] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31];
            sum[23] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31];
            sum[24] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31];
            sum[25] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31];
            sum[26] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31];
            sum[27] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31];
            sum[28] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31];
            sum[29] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31];
            sum[30] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31];
            sum[31] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31];
            break;
        case 36:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35];
            sum[1] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
                     col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
                     col[31] - col[32] + col[33] - col[34] + col[35];
            sum[2] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
                     col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] + col[20] +
                     col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
                     col[31] + col[32] + col[33] + col[34] + col[35];
            sum[3] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] + col[20] -
                     col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
                     col[31] + col[32] - col[33] + col[34] - col[35];
            sum[4] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
                     col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
                     col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
                     col[31] - col[32] - col[33] + col[34] + col[35];
            sum[5] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
                     col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
                     col[31] - col[32] + col[33] + col[34] - col[35];
            sum[6] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] + col[10] +
                     col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] - col[20] -
                     col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] - col[30] -
                     col[31] + col[32] + col[33] - col[34] - col[35];
            sum[7] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
                     col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
                     col[31] + col[32] - col[33] - col[34] + col[35];
            sum[8] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] - col[9] + col[10] +
                     col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
                     col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
                     col[31] - col[32] - col[33] + col[34] + col[35];
            sum[9] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] - col[9] + col[10] -
                     col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
                     col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
                     col[31] - col[32] + col[33] + col[34] - col[35];
            sum[10] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35];
            sum[11] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35];
            sum[12] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35];
            sum[13] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35];
            sum[14] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35];
            sum[15] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35];
            sum[16] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35];
            sum[17] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35];
            sum[18] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35];
            sum[19] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35];
            sum[20] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35];
            sum[21] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35];
            sum[22] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] - col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35];
            sum[23] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35];
            sum[24] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35];
            sum[25] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35];
            sum[26] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] + col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35];
            sum[27] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35];
            sum[28] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35];
            sum[29] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35];
            sum[30] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] - col[31] + col[32] + col[33] + col[34] + col[35];
            sum[31] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] - col[31] + col[32] - col[33] + col[34] - col[35];
            sum[32] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] - col[33] + col[34] + col[35];
            sum[33] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] - col[33] + col[34] - col[35];
            sum[34] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] + col[34] - col[35];
            sum[35] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] - col[35];
            break;
        case 40:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39];
            sum[1] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
                     col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
                     col[31] - col[32] + col[33] - col[34] + col[35] - col[36] + col[37] - col[38] + col[39];
            sum[2] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
                     col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] + col[20] -
                     col[21] + col[22] - col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] + col[30] +
                     col[31] - col[32] - col[33] + col[34] + col[35] - col[36] - col[37] + col[38] + col[39];
            sum[3] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
                     col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] + col[20] +
                     col[21] - col[22] - col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] + col[30] -
                     col[31] - col[32] + col[33] + col[34] - col[35] - col[36] + col[37] + col[38] - col[39];
            sum[4] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] + col[20] -
                     col[21] - col[22] - col[23] + col[24] - col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] - col[32] - col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39];
            sum[5] = col[0] + col[1] - col[2] + col[3] - col[4] - col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] + col[20] +
                     col[21] - col[22] + col[23] - col[24] - col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
                     col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39];
            sum[6] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] - col[10] -
                     col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19] + col[20] -
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] - col[27] - col[28] - col[29] - col[30] -
                     col[31] - col[32] - col[33] + col[34] + col[35] + col[36] + col[37] - col[38] - col[39];
            sum[7] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] - col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] + col[20] +
                     col[21] + col[22] - col[23] + col[24] - col[25] - col[26] - col[27] - col[28] + col[29] - col[30] +
                     col[31] - col[32] + col[33] + col[34] - col[35] + col[36] - col[37] - col[38] + col[39];
            sum[8] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] - col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] + col[20] -
                     col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] + col[28] - col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35] - col[36] - col[37] - col[38] - col[39];
            sum[9] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] - col[9] + col[10] -
                     col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] + col[20] +
                     col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] - col[28] - col[29] + col[30] -
                     col[31] + col[32] - col[33] + col[34] - col[35] - col[36] + col[37] - col[38] + col[39];
            sum[10] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39];
            sum[11] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39];
            sum[12] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39];
            sum[13] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39];
            sum[14] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] + col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39];
            sum[15] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39];
            sum[16] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] - col[17] + col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] + col[36] -
                      col[37] + col[38] + col[39];
            sum[17] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] - col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] - col[39];
            sum[18] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39];
            sum[19] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] - col[39];
            sum[20] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39];
            sum[21] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39];
            sum[22] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39];
            sum[23] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39];
            sum[24] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] + col[21] + col[22] + col[23] - col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39];
            sum[25] = col[0] + col[1] - col[2] + col[3] - col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] - col[21] + col[22] - col[23] + col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39];
            sum[26] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39];
            sum[27] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39];
            sum[28] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] + col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39];
            sum[29] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39];
            sum[30] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39];
            sum[31] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39];
            sum[32] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39];
            sum[33] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39];
            sum[34] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39];
            sum[35] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39];
            sum[36] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] - col[17] + col[18] +
                      col[19] - col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] - col[36] +
                      col[37] - col[38] - col[39];
            sum[37] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] + col[36] +
                      col[37] - col[38] + col[39];
            sum[38] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] + col[39];
            sum[39] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] + col[39];
            break;

        case 44:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
                     col[41] + col[42] + col[43];
            sum[1] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] - col[9] + col[10] +
                     col[11] + col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] - col[19] - col[20] -
                     col[21] + col[22] - col[23] + col[24] + col[25] + col[26] - col[27] - col[28] - col[29] - col[30] -
                     col[31] + col[32] - col[33] - col[34] - col[35] + col[36] + col[37] - col[38] + col[39] - col[40] +
                     col[41] + col[42] - col[43];
            sum[2] = col[0] - col[1] - col[2] + col[3] - col[4] - col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] + col[12] + col[13] - col[14] + col[15] + col[16] + col[17] + col[18] + col[19] - col[20] -
                     col[21] - col[22] + col[23] - col[24] + col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
                     col[31] - col[32] + col[33] - col[34] - col[35] - col[36] + col[37] + col[38] - col[39] + col[40] -
                     col[41] + col[42] + col[43];
            sum[3] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] - col[10] -
                     col[11] + col[12] + col[13] + col[14] - col[15] + col[16] + col[17] + col[18] + col[19] + col[20] -
                     col[21] - col[22] - col[23] + col[24] - col[25] + col[26] + col[27] + col[28] - col[29] - col[30] -
                     col[31] - col[32] - col[33] + col[34] - col[35] - col[36] - col[37] + col[38] + col[39] - col[40] +
                     col[41] - col[42] + col[43];
            sum[4] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] - col[7] + col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] + col[14] + col[15] - col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] - col[22] - col[23] - col[24] + col[25] - col[26] + col[27] + col[28] + col[29] - col[30] -
                     col[31] - col[32] - col[33] - col[34] + col[35] - col[36] - col[37] - col[38] + col[39] + col[40] -
                     col[41] + col[42] - col[43];
            sum[5] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] + col[28] + col[29] + col[30] -
                     col[31] - col[32] - col[33] - col[34] - col[35] + col[36] - col[37] - col[38] - col[39] + col[40] +
                     col[41] - col[42] + col[43];
            sum[6] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] - col[9] + col[10] -
                     col[11] + col[12] - col[13] - col[14] + col[15] + col[16] + col[17] - col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] - col[24] - col[25] - col[26] + col[27] - col[28] + col[29] + col[30] +
                     col[31] - col[32] - col[33] - col[34] - col[35] - col[36] + col[37] - col[38] - col[39] - col[40] +
                     col[41] + col[42] - col[43];
            sum[7] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] - col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] - col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] - col[25] - col[26] - col[27] + col[28] - col[29] + col[30] +
                     col[31] + col[32] - col[33] - col[34] - col[35] - col[36] - col[37] + col[38] - col[39] - col[40] -
                     col[41] + col[42] + col[43];
            sum[8] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] - col[10] -
                     col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] + col[19] - col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] - col[28] + col[29] - col[30] +
                     col[31] + col[32] + col[33] - col[34] - col[35] - col[36] - col[37] - col[38] + col[39] - col[40] -
                     col[41] - col[42] + col[43];
            sum[9] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] - col[17] + col[18] + col[19] + col[20] -
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] - col[27] - col[28] - col[29] + col[30] -
                     col[31] + col[32] + col[33] + col[34] - col[35] - col[36] - col[37] - col[38] - col[39] + col[40] -
                     col[41] - col[42] - col[43];
            sum[10] = col[0] - col[1] + col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] + col[21] - col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] + col[41] - col[42] - col[43];
            sum[11] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] - col[29] - col[30] - col[31] + col[32] - col[33] + col[34] + col[35] + col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] - col[43];
            sum[12] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] + col[23] - col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] + col[43];
            sum[13] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] - col[31] - col[32] - col[33] + col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39] - col[40] - col[41] - col[42] - col[43];
            sum[14] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] + col[25] - col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43];
            sum[15] = col[0] - col[1] - col[2] + col[3] - col[4] - col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] - col[33] - col[34] - col[35] + col[36] -
                      col[37] + col[38] + col[39] + col[40] - col[41] - col[42] - col[43];
            sum[16] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] + col[27] -
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] + col[41] - col[42] - col[43];
            sum[17] = col[0] - col[1] - col[2] - col[3] - col[4] + col[5] - col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] + col[34] - col[35] - col[36] -
                      col[37] + col[38] - col[39] + col[40] + col[41] + col[42] - col[43];
            sum[18] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] - col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] + col[29] - col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] + col[43];
            sum[19] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] - col[6] + col[7] - col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] - col[31] + col[32] + col[33] + col[34] + col[35] + col[36] -
                      col[37] - col[38] - col[39] + col[40] - col[41] + col[42] + col[43];
            sum[20] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] + col[31] - col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] + col[41] - col[42] + col[43];
            sum[21] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] + col[9] -
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] - col[39] - col[40] - col[41] + col[42] - col[43];
            sum[22] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] + col[33] - col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] + col[43];
            sum[23] = col[0] + col[1] - col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] + col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] - col[41] - col[42] - col[43];
            sum[24] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] + col[35] - col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43];
            sum[25] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] - col[33] + col[34] + col[35] + col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] - col[43];
            sum[26] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] + col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] + col[36] +
                      col[37] - col[38] + col[39] + col[40] + col[41] + col[42] + col[43];
            sum[27] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] + col[15] - col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39] + col[40] + col[41] + col[42] + col[43];
            sum[28] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] + col[39] - col[40] + col[41] + col[42] + col[43];
            sum[29] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] + col[17] - col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] - col[41] + col[42] + col[43];
            sum[30] = col[0] + col[1] + col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] + col[41] - col[42] + col[43];
            sum[31] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] +
                      col[19] - col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] - col[43];
            sum[32] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] - col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] + col[43];
            sum[33] = col[0] + col[1] - col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] - col[41] + col[42] + col[43];
            sum[34] = col[0] + col[1] + col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43];
            sum[35] = col[0] + col[1] + col[2] + col[3] - col[4] + col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] + col[23] - col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] + col[33] - col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] - col[43];
            sum[36] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] - col[39] + col[40] - col[41] + col[42] - col[43];
            sum[37] = col[0] - col[1] - col[2] + col[3] + col[4] + col[5] - col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] + col[25] - col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43];
            sum[38] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] + col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] - col[41] + col[42] - col[43];
            sum[39] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] + col[6] + col[7] - col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] - col[41] - col[42] + col[43];
            sum[40] = col[0] + col[1] - col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] - col[43];
            sum[41] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] + col[9] -
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] - col[43];
            sum[42] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] + col[22] + col[23] + col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43];
            sum[43] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] + col[11] - col[12] + col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] + col[31] - col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] + col[41] - col[42] - col[43];
            break;
        case 48:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
                     col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47];
            sum[1] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
                     col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
                     col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
                     col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] - col[40] +
                     col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47];
            sum[2] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] + col[10] +
                     col[11] + col[12] - col[13] + col[14] - col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
                     col[21] + col[22] + col[23] + col[24] - col[25] + col[26] - col[27] + col[28] + col[29] - col[30] -
                     col[31] - col[32] - col[33] + col[34] + col[35] + col[36] - col[37] + col[38] - col[39] + col[40] +
                     col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47];
            sum[3] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] + col[10] -
                     col[11] + col[12] + col[13] - col[14] - col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
                     col[21] + col[22] - col[23] + col[24] + col[25] - col[26] - col[27] + col[28] - col[29] - col[30] +
                     col[31] - col[32] + col[33] + col[34] - col[35] + col[36] + col[37] - col[38] - col[39] + col[40] -
                     col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47];
            sum[4] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
                     col[11] + col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] + col[19] - col[20] -
                     col[21] - col[22] - col[23] + col[24] - col[25] + col[26] + col[27] + col[28] - col[29] + col[30] +
                     col[31] - col[32] - col[33] - col[34] - col[35] + col[36] - col[37] + col[38] + col[39] + col[40] -
                     col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47];
            sum[5] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
                     col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] - col[19] - col[20] +
                     col[21] - col[22] + col[23] + col[24] + col[25] + col[26] - col[27] - col[28] - col[29] + col[30] -
                     col[31] - col[32] + col[33] - col[34] + col[35] + col[36] + col[37] + col[38] - col[39] - col[40] -
                     col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47];
            sum[6] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] - col[10] -
                     col[11] + col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] - col[19] + col[20] +
                     col[21] - col[22] - col[23] + col[24] - col[25] - col[26] - col[27] + col[28] + col[29] + col[30] -
                     col[31] + col[32] + col[33] - col[34] - col[35] + col[36] - col[37] - col[38] - col[39] + col[40] +
                     col[41] + col[42] - col[43] + col[44] + col[45] - col[46] - col[47];
            sum[7] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] + col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] - col[19] + col[20] -
                     col[21] - col[22] + col[23] + col[24] + col[25] - col[26] + col[27] + col[28] - col[29] - col[30] -
                     col[31] + col[32] - col[33] - col[34] + col[35] + col[36] + col[37] - col[38] + col[39] + col[40] -
                     col[41] - col[42] - col[43] + col[44] - col[45] - col[46] + col[47];
            sum[8] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] + col[10] +
                     col[11] + col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] + col[20] -
                     col[21] + col[22] + col[23] + col[24] - col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
                     col[31] + col[32] - col[33] + col[34] + col[35] + col[36] - col[37] - col[38] - col[39] - col[40] -
                     col[41] + col[42] + col[43] + col[44] - col[45] + col[46] + col[47];
            sum[9] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] - col[9] + col[10] -
                     col[11] + col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] - col[20] -
                     col[21] + col[22] - col[23] + col[24] + col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
                     col[31] - col[32] - col[33] + col[34] - col[35] + col[36] + col[37] - col[38] + col[39] - col[40] +
                     col[41] + col[42] - col[43] - col[44] - col[45] + col[46] - col[47];
            sum[10] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] + col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] - col[47];
            sum[11] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] - col[47];
            sum[12] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47];
            sum[13] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47];
            sum[14] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47];
            sum[15] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47];
            sum[16] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] - col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27] +
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] - col[36] +
                      col[37] - col[38] - col[39] - col[40] + col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47];
            sum[17] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] - col[13] - col[14] + col[15] + col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] + col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] -
                      col[37] - col[38] + col[39] + col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47];
            sum[18] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47];
            sum[19] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47];
            sum[20] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] - col[12] + col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] + col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] - col[33] + col[34] + col[35] - col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] - col[44] + col[45] -
                      col[46] - col[47];
            sum[21] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] + col[21] - col[22] + col[23] + col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] - col[33] + col[34] - col[35] - col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] + col[45] -
                      col[46] + col[47];
            sum[22] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] + col[47];
            sum[23] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] + col[47];
            sum[24] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47];
            sum[25] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47];
            sum[26] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47];
            sum[27] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47];
            sum[28] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] + col[25] - col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] - col[36] +
                      col[37] - col[38] - col[39] - col[40] + col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47];
            sum[29] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] - col[25] - col[26] + col[27] +
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] - col[36] -
                      col[37] - col[38] + col[39] + col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47];
            sum[30] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] - col[32] - col[33] + col[34] + col[35] - col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47];
            sum[31] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47];
            sum[32] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] - col[21] + col[22] + col[23] - col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] + col[33] - col[34] - col[35] - col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] - col[44] + col[45] -
                      col[46] - col[47];
            sum[33] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] - col[11] + col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] + col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] + col[45] -
                      col[46] + col[47];
            sum[34] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] + col[47];
            sum[35] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] + col[47];
            sum[36] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47];
            sum[37] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] -
                      col[46] + col[47];
            sum[38] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47];
            sum[39] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47];
            sum[40] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] - col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] + col[25] - col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] + col[36] -
                      col[37] + col[38] + col[39] + col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47];
            sum[41] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] - col[13] - col[14] + col[15] + col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] - col[25] - col[26] + col[27] +
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39] - col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47];
            sum[42] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] - col[32] - col[33] + col[34] + col[35] + col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47];
            sum[43] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47];
            sum[44] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] - col[12] + col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] - col[23] - col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] + col[33] - col[34] - col[35] + col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] - col[45] +
                      col[46] + col[47];
            sum[45] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] + col[21] - col[22] + col[23] - col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] + col[33] - col[34] + col[35] + col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] - col[45] +
                      col[46] - col[47];
            sum[46] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] + col[23] - col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] - col[47];
            sum[47] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] - col[47];
            break;
        case 52:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
                     col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
                     col[51];
            sum[1] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
                     col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
                     col[31] - col[32] + col[33] - col[34] + col[35] - col[36] + col[37] - col[38] + col[39] - col[40] +
                     col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] - col[50] +
                     col[51];
            sum[2] = col[0] - col[1] + col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
                     col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
                     col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] - col[28] - col[29] + col[30] +
                     col[31] - col[32] - col[33] + col[34] + col[35] - col[36] - col[37] + col[38] + col[39] - col[40] -
                     col[41] + col[42] + col[43] - col[44] - col[45] + col[46] + col[47] - col[48] - col[49] + col[50] +
                     col[51];
            sum[3] = col[0] + col[1] - col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
                     col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
                     col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] - col[28] + col[29] + col[30] -
                     col[31] - col[32] + col[33] + col[34] - col[35] - col[36] + col[37] + col[38] - col[39] - col[40] +
                     col[41] + col[42] - col[43] - col[44] + col[45] + col[46] - col[47] - col[48] + col[49] + col[50] -
                     col[51];
            sum[4] = col[0] - col[1] - col[2] - col[3] + col[4] - col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
                     col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
                     col[31] + col[32] + col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] - col[40] -
                     col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47] + col[48] + col[49] - col[50] -
                     col[51];
            sum[5] = col[0] + col[1] - col[2] + col[3] - col[4] - col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] + col[20] -
                     col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
                     col[31] + col[32] - col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] - col[40] +
                     col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47] + col[48] - col[49] - col[50] +
                     col[51];
            sum[6] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] - col[7] - col[8] - col[9] - col[10] -
                     col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
                     col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
                     col[31] + col[32] + col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] + col[40] +
                     col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] - col[48] - col[49] - col[50] -
                     col[51];
            sum[7] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] - col[7] - col[8] + col[9] - col[10] +
                     col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
                     col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
                     col[31] + col[32] - col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] + col[40] -
                     col[41] + col[42] - col[43] + col[44] - col[45] + col[46] - col[47] - col[48] + col[49] - col[50] +
                     col[51];
            sum[8] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] - col[9] + col[10] +
                     col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] + col[19] - col[20] -
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] - col[32] - col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] + col[40] +
                     col[41] - col[42] - col[43] - col[44] - col[45] - col[46] - col[47] - col[48] - col[49] + col[50] +
                     col[51];
            sum[9] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] - col[9] + col[10] -
                     col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] - col[19] - col[20] +
                     col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
                     col[31] - col[32] + col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] + col[40] -
                     col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] + col[50] -
                     col[51];
            sum[10] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51];
            sum[11] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51];
            sum[12] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51];
            sum[13] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51];
            sum[14] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] + col[51];
            sum[15] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] + col[50] - col[51];
            sum[16] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51];
            sum[17] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51];
            sum[18] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51];
            sum[19] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51];
            sum[20] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51];
            sum[21] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] - col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51];
            sum[22] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51];
            sum[23] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51];
            sum[24] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51];
            sum[25] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51];
            sum[26] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51];
            sum[27] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51];
            sum[28] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51];
            sum[29] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51];
            sum[30] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51];
            sum[31] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51];
            sum[32] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51];
            sum[33] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51];
            sum[34] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51];
            sum[35] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51];
            sum[36] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] + col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51];
            sum[37] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51];
            sum[38] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51];
            sum[39] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51];
            sum[40] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51];
            sum[41] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] - col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51];
            sum[42] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] + col[51];
            sum[43] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] + col[50] - col[51];
            sum[44] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] + col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51];
            sum[45] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] - col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51];
            sum[46] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51];
            sum[47] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51];
            sum[48] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] - col[49] + col[50] + col[51];
            sum[49] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] - col[49] + col[50] - col[51];
            sum[50] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] - col[51];
            sum[51] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] - col[51];
            break;
        case 56:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
                     col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
                     col[51] + col[52] + col[53] + col[54] + col[55];
            sum[1] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
                     col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
                     col[31] - col[32] + col[33] - col[34] + col[35] - col[36] + col[37] - col[38] + col[39] - col[40] +
                     col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] - col[50] +
                     col[51] - col[52] + col[53] - col[54] + col[55];
            sum[2] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] + col[10] +
                     col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] - col[19] + col[20] +
                     col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] + col[28] - col[29] + col[30] -
                     col[31] + col[32] + col[33] - col[34] - col[35] + col[36] + col[37] + col[38] + col[39] - col[40] -
                     col[41] - col[42] - col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] + col[50] +
                     col[51] - col[52] - col[53] + col[54] + col[55];
            sum[3] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] + col[20] -
                     col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] + col[28] + col[29] - col[30] -
                     col[31] + col[32] - col[33] - col[34] + col[35] + col[36] - col[37] + col[38] - col[39] - col[40] +
                     col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] + col[50] -
                     col[51] - col[52] + col[53] + col[54] - col[55];
            sum[4] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] + col[10] +
                     col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] - col[19] - col[20] -
                     col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] + col[28] - col[29] + col[30] +
                     col[31] + col[32] - col[33] + col[34] + col[35] - col[36] - col[37] + col[38] + col[39] + col[40] +
                     col[41] - col[42] - col[43] - col[44] - col[45] - col[46] - col[47] - col[48] - col[49] + col[50] +
                     col[51] + col[52] + col[53] - col[54] - col[55];
            sum[5] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] + col[10] -
                     col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
                     col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] + col[28] + col[29] + col[30] -
                     col[31] - col[32] - col[33] + col[34] - col[35] - col[36] + col[37] + col[38] - col[39] + col[40] -
                     col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] + col[50] -
                     col[51] + col[52] - col[53] - col[54] + col[55];
            sum[6] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] - col[10] -
                     col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] - col[19] - col[20] -
                     col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] + col[28] - col[29] - col[30] -
                     col[31] + col[32] + col[33] + col[34] - col[35] + col[36] + col[37] - col[38] - col[39] + col[40] +
                     col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47] - col[48] - col[49] - col[50] -
                     col[51] + col[52] + col[53] + col[54] + col[55];
            sum[7] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] + col[19] - col[20] +
                     col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] + col[28] + col[29] - col[30] +
                     col[31] + col[32] - col[33] - col[34] - col[35] + col[36] - col[37] - col[38] + col[39] + col[40] -
                     col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47] - col[48] + col[49] - col[50] +
                     col[51] + col[52] - col[53] + col[54] - col[55];
            sum[8] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] + col[10] +
                     col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
                     col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] + col[28] - col[29] + col[30] +
                     col[31] - col[32] - col[33] + col[34] + col[35] + col[36] - col[37] + col[38] + col[39] - col[40] -
                     col[41] + col[42] + col[43] + col[44] + col[45] - col[46] - col[47] - col[48] - col[49] - col[50] -
                     col[51] - col[52] - col[53] + col[54] + col[55];
            sum[9] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
                     col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] + col[28] + col[29] + col[30] -
                     col[31] - col[32] + col[33] + col[34] - col[35] - col[36] - col[37] + col[38] - col[39] - col[40] +
                     col[41] + col[42] - col[43] + col[44] - col[45] - col[46] + col[47] - col[48] + col[49] - col[50] +
                     col[51] - col[52] + col[53] + col[54] - col[55];
            sum[10] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] - col[54] - col[55];
            sum[11] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] - col[52] + col[53] - col[54] + col[55];
            sum[12] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] - col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] - col[54] - col[55];
            sum[13] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] - col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] - col[54] + col[55];
            sum[14] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] + col[51] - col[52] - col[53] - col[54] - col[55];
            sum[15] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] + col[50] - col[51] - col[52] + col[53] - col[54] + col[55];
            sum[16] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] + col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] + col[52] + col[53] - col[54] - col[55];
            sum[17] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] - col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51] + col[52] - col[53] - col[54] + col[55];
            sum[18] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] + col[52] + col[53] + col[54] + col[55];
            sum[19] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] + col[52] - col[53] + col[54] - col[55];
            sum[20] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] - col[49] + col[50] + col[51] - col[52] - col[53] + col[54] + col[55];
            sum[21] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] - col[49] + col[50] - col[51] - col[52] + col[53] + col[54] - col[55];
            sum[22] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] - col[51] + col[52] + col[53] - col[54] - col[55];
            sum[23] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] - col[51] + col[52] - col[53] - col[54] + col[55];
            sum[24] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27] +
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] + col[52] - col[53] + col[54] + col[55];
            sum[25] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] +
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51] - col[52] - col[53] + col[54] - col[55];
            sum[26] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] + col[52] + col[53] + col[54] - col[55];
            sum[27] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] + col[52] - col[53] - col[54] - col[55];
            sum[28] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] - col[54] - col[55];
            sum[29] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] + col[52] - col[53] + col[54] - col[55];
            sum[30] = col[0] - col[1] + col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] - col[54] - col[55];
            sum[31] = col[0] + col[1] - col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] - col[54] + col[55];
            sum[32] = col[0] - col[1] + col[2] + col[3] + col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] - col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] + col[55];
            sum[33] = col[0] + col[1] + col[2] - col[3] - col[4] - col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] + col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] - col[55];
            sum[34] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] - col[52] - col[53] - col[54] - col[55];
            sum[35] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] - col[52] + col[53] - col[54] + col[55];
            sum[36] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] + col[52] + col[53] - col[54] - col[55];
            sum[37] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] + col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] + col[52] - col[53] - col[54] + col[55];
            sum[38] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] + col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] + col[51] + col[52] + col[53] + col[54] + col[55];
            sum[39] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] + col[50] - col[51] + col[52] - col[53] + col[54] - col[55];
            sum[40] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] + col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] + col[52] + col[53] + col[54] + col[55];
            sum[41] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] + col[52] - col[53] + col[54] - col[55];
            sum[42] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] + col[54] + col[55];
            sum[43] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] + col[54] - col[55];
            sum[44] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] + col[55];
            sum[45] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] + col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] - col[55];
            sum[46] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] - col[54] - col[55];
            sum[47] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] - col[54] + col[55];
            sum[48] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] + col[49] - col[50] - col[51] + col[52] + col[53] - col[54] - col[55];
            sum[49] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] + col[49] - col[50] + col[51] + col[52] - col[53] - col[54] + col[55];
            sum[50] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] + col[51] - col[52] - col[53] + col[54] + col[55];
            sum[51] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] + col[51] - col[52] + col[53] + col[54] - col[55];
            sum[52] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27] -
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] + col[53] - col[54] - col[55];
            sum[53] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] + col[52] + col[53] - col[54] + col[55];
            sum[54] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] - col[54] + col[55];
            sum[55] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] + col[54] + col[55];
            break;
        case 60:
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
            sum[10] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] + col[54] +
                      col[55] + col[56] + col[57] + col[58] + col[59];
            sum[11] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] + col[54] -
                      col[55] + col[56] - col[57] + col[58] - col[59];
            sum[12] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] + col[56] + col[57] + col[58] + col[59];
            sum[13] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] - col[54] +
                      col[55] + col[56] - col[57] + col[58] - col[59];
            sum[14] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] + col[58] + col[59];
            sum[15] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] + col[58] - col[59];
            sum[16] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59];
            sum[17] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] + col[59];
            sum[18] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59];
            sum[19] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59];
            sum[20] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] - col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] - col[58] - col[59];
            sum[21] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] - col[58] + col[59];
            sum[22] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] - col[58] - col[59];
            sum[23] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] - col[58] + col[59];
            sum[24] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59];
            sum[25] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] + col[59];
            sum[26] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59];
            sum[27] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59];
            sum[28] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] - col[58] - col[59];
            sum[29] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] - col[58] + col[59];
            sum[30] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59];
            sum[31] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] + col[59];
            sum[32] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59];
            sum[33] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59];
            sum[34] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] - col[58] - col[59];
            sum[35] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] - col[58] + col[59];
            sum[36] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] - col[58] - col[59];
            sum[37] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] - col[58] + col[59];
            sum[38] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] + col[52] + col[53] - col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59];
            sum[39] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] - col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] + col[52] - col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] + col[59];
            sum[40] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] - col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] + col[51] + col[52] + col[53] + col[54] +
                      col[55] - col[56] - col[57] + col[58] + col[59];
            sum[41] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] + col[50] - col[51] + col[52] - col[53] + col[54] -
                      col[55] - col[56] + col[57] + col[58] - col[59];
            sum[42] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] + col[52] + col[53] + col[54] +
                      col[55] + col[56] + col[57] - col[58] - col[59];
            sum[43] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] + col[52] - col[53] + col[54] -
                      col[55] + col[56] - col[57] - col[58] + col[59];
            sum[44] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] + col[54] +
                      col[55] + col[56] + col[57] + col[58] + col[59];
            sum[45] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] + col[54] -
                      col[55] + col[56] - col[57] + col[58] - col[59];
            sum[46] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] + col[56] + col[57] + col[58] + col[59];
            sum[47] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] + col[56] - col[57] + col[58] - col[59];
            sum[48] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] - col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] + col[58] + col[59];
            sum[49] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] - col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] + col[58] - col[59];
            sum[50] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59];
            sum[51] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] - col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59];
            sum[52] = col[0] - col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] + col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] - col[58] - col[59];
            sum[53] = col[0] + col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] - col[53] + col[54] -
                      col[55] - col[56] + col[57] - col[58] + col[59];
            sum[54] = col[0] - col[1] - col[2] - col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] + col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59];
            sum[55] = col[0] + col[1] - col[2] + col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] - col[54] -
                      col[55] + col[56] - col[57] - col[58] + col[59];
            sum[56] = col[0] - col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] + col[56] - col[57] + col[58] + col[59];
            sum[57] = col[0] + col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] - col[57] + col[58] - col[59];
            sum[58] = col[0] - col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] + col[58] - col[59];
            sum[59] = col[0] + col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] - col[59];
            break;
        case 64:
            sum[0] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] + col[10] +
                     col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] + col[28] + col[29] + col[30] +
                     col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] + col[40] +
                     col[41] + col[42] + col[43] + col[44] + col[45] + col[46] + col[47] + col[48] + col[49] + col[50] +
                     col[51] + col[52] + col[53] + col[54] + col[55] + col[56] + col[57] + col[58] + col[59] + col[60] +
                     col[61] + col[62] + col[63];
            sum[1] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] + col[10] -
                     col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
                     col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] + col[28] - col[29] + col[30] -
                     col[31] + col[32] - col[33] + col[34] - col[35] + col[36] - col[37] + col[38] - col[39] + col[40] -
                     col[41] + col[42] - col[43] + col[44] - col[45] + col[46] - col[47] + col[48] - col[49] + col[50] -
                     col[51] + col[52] - col[53] + col[54] - col[55] + col[56] - col[57] + col[58] - col[59] + col[60] -
                     col[61] + col[62] - col[63];
            sum[2] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] - col[10] -
                     col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] - col[19] + col[20] +
                     col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] + col[28] + col[29] - col[30] -
                     col[31] + col[32] + col[33] - col[34] - col[35] + col[36] + col[37] - col[38] - col[39] + col[40] +
                     col[41] - col[42] - col[43] + col[44] + col[45] - col[46] - col[47] + col[48] + col[49] - col[50] -
                     col[51] + col[52] + col[53] - col[54] - col[55] + col[56] + col[57] - col[58] - col[59] + col[60] +
                     col[61] - col[62] - col[63];
            sum[3] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] - col[10] +
                     col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] + col[19] + col[20] -
                     col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] + col[28] - col[29] - col[30] +
                     col[31] + col[32] - col[33] - col[34] + col[35] + col[36] - col[37] - col[38] + col[39] + col[40] -
                     col[41] - col[42] + col[43] + col[44] - col[45] - col[46] + col[47] + col[48] - col[49] - col[50] +
                     col[51] + col[52] - col[53] - col[54] + col[55] + col[56] - col[57] - col[58] + col[59] + col[60] -
                     col[61] - col[62] + col[63];
            sum[4] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] + col[10] +
                     col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] + col[19] - col[20] -
                     col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] - col[28] - col[29] - col[30] -
                     col[31] + col[32] + col[33] + col[34] + col[35] - col[36] - col[37] - col[38] - col[39] + col[40] +
                     col[41] + col[42] + col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] + col[50] +
                     col[51] - col[52] - col[53] - col[54] - col[55] + col[56] + col[57] + col[58] + col[59] - col[60] -
                     col[61] - col[62] - col[63];
            sum[5] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] + col[10] -
                     col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] - col[19] - col[20] +
                     col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] - col[28] + col[29] - col[30] +
                     col[31] + col[32] - col[33] + col[34] - col[35] - col[36] + col[37] - col[38] + col[39] + col[40] -
                     col[41] + col[42] - col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] + col[50] -
                     col[51] - col[52] + col[53] - col[54] + col[55] + col[56] - col[57] + col[58] - col[59] - col[60] +
                     col[61] - col[62] + col[63];
            sum[6] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] - col[10] -
                     col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] - col[19] - col[20] -
                     col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] - col[28] - col[29] + col[30] +
                     col[31] + col[32] + col[33] - col[34] - col[35] - col[36] - col[37] + col[38] + col[39] + col[40] +
                     col[41] - col[42] - col[43] - col[44] - col[45] + col[46] + col[47] + col[48] + col[49] - col[50] -
                     col[51] - col[52] - col[53] + col[54] + col[55] + col[56] + col[57] - col[58] - col[59] - col[60] -
                     col[61] + col[62] + col[63];
            sum[7] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] - col[10] +
                     col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] + col[19] - col[20] +
                     col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] - col[28] + col[29] + col[30] -
                     col[31] + col[32] - col[33] - col[34] + col[35] - col[36] + col[37] + col[38] - col[39] + col[40] -
                     col[41] - col[42] + col[43] - col[44] + col[45] + col[46] - col[47] + col[48] - col[49] - col[50] +
                     col[51] - col[52] + col[53] + col[54] - col[55] + col[56] - col[57] - col[58] + col[59] - col[60] +
                     col[61] + col[62] - col[63];
            sum[8] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] - col[10] -
                     col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] + col[19] + col[20] +
                     col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] - col[28] - col[29] - col[30] -
                     col[31] + col[32] + col[33] + col[34] + col[35] + col[36] + col[37] + col[38] + col[39] - col[40] -
                     col[41] - col[42] - col[43] - col[44] - col[45] - col[46] - col[47] + col[48] + col[49] + col[50] +
                     col[51] + col[52] + col[53] + col[54] + col[55] - col[56] - col[57] - col[58] - col[59] - col[60] -
                     col[61] - col[62] - col[63];
            sum[9] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] - col[10] +
                     col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] - col[19] + col[20] -
                     col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] - col[28] + col[29] - col[30] +
                     col[31] + col[32] - col[33] + col[34] - col[35] + col[36] - col[37] + col[38] - col[39] - col[40] +
                     col[41] - col[42] + col[43] - col[44] + col[45] - col[46] + col[47] + col[48] - col[49] + col[50] -
                     col[51] + col[52] - col[53] + col[54] - col[55] - col[56] + col[57] - col[58] + col[59] - col[60] +
                     col[61] - col[62] + col[63];
            sum[10] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59] - col[60] - col[61] + col[62] + col[63];
            sum[11] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59] - col[60] + col[61] + col[62] - col[63];
            sum[12] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] - col[56] - col[57] - col[58] - col[59] + col[60] + col[61] + col[62] + col[63];
            sum[13] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] - col[56] + col[57] - col[58] + col[59] + col[60] - col[61] + col[62] - col[63];
            sum[14] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] + col[58] + col[59] + col[60] + col[61] - col[62] - col[63];
            sum[15] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] + col[58] - col[59] + col[60] - col[61] - col[62] + col[63];
            sum[16] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] - col[54] -
                      col[55] - col[56] - col[57] - col[58] - col[59] - col[60] - col[61] - col[62] - col[63];
            sum[17] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] - col[52] + col[53] - col[54] +
                      col[55] - col[56] + col[57] - col[58] + col[59] - col[60] + col[61] - col[62] + col[63];
            sum[18] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] + col[58] + col[59] - col[60] - col[61] + col[62] + col[63];
            sum[19] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] + col[58] - col[59] - col[60] + col[61] + col[62] - col[63];
            sum[20] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] + col[54] +
                      col[55] - col[56] - col[57] - col[58] - col[59] + col[60] + col[61] + col[62] + col[63];
            sum[21] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] + col[54] -
                      col[55] - col[56] + col[57] - col[58] + col[59] + col[60] - col[61] + col[62] - col[63];
            sum[22] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59] + col[60] + col[61] - col[62] - col[63];
            sum[23] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59] + col[60] - col[61] - col[62] + col[63];
            sum[24] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] + col[32] + col[33] + col[34] + col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] + col[58] + col[59] + col[60] + col[61] + col[62] + col[63];
            sum[25] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] + col[32] - col[33] + col[34] - col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] + col[58] - col[59] + col[60] - col[61] + col[62] - col[63];
            sum[26] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] + col[32] + col[33] - col[34] - col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] + col[54] +
                      col[55] + col[56] + col[57] - col[58] - col[59] + col[60] + col[61] - col[62] - col[63];
            sum[27] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] + col[32] - col[33] - col[34] + col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] + col[54] -
                      col[55] + col[56] - col[57] - col[58] + col[59] + col[60] - col[61] - col[62] + col[63];
            sum[28] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] + col[32] + col[33] + col[34] + col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] + col[54] +
                      col[55] + col[56] + col[57] + col[58] + col[59] - col[60] - col[61] - col[62] - col[63];
            sum[29] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] + col[32] - col[33] + col[34] - col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] + col[54] -
                      col[55] + col[56] - col[57] + col[58] - col[59] - col[60] + col[61] - col[62] + col[63];
            sum[30] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] + col[32] + col[33] - col[34] - col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] + col[52] + col[53] - col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59] - col[60] - col[61] + col[62] + col[63];
            sum[31] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] + col[32] - col[33] - col[34] + col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] + col[52] - col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] + col[59] - col[60] + col[61] + col[62] - col[63];
            sum[32] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] - col[54] -
                      col[55] - col[56] - col[57] - col[58] - col[59] - col[60] - col[61] - col[62] - col[63];
            sum[33] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51] - col[52] + col[53] - col[54] +
                      col[55] - col[56] + col[57] - col[58] + col[59] - col[60] + col[61] - col[62] + col[63];
            sum[34] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] + col[58] + col[59] - col[60] - col[61] + col[62] + col[63];
            sum[35] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] + col[58] - col[59] - col[60] + col[61] + col[62] - col[63];
            sum[36] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] + col[54] +
                      col[55] - col[56] - col[57] - col[58] - col[59] + col[60] + col[61] + col[62] + col[63];
            sum[37] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] + col[54] -
                      col[55] - col[56] + col[57] - col[58] + col[59] + col[60] - col[61] + col[62] - col[63];
            sum[38] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59] + col[60] + col[61] - col[62] - col[63];
            sum[39] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59] + col[60] - col[61] - col[62] + col[63];
            sum[40] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] + col[16] + col[17] + col[18] +
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] - col[48] - col[49] - col[50] - col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] + col[58] + col[59] + col[60] + col[61] + col[62] + col[63];
            sum[41] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] + col[16] - col[17] + col[18] -
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] - col[48] + col[49] - col[50] + col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] + col[58] - col[59] + col[60] - col[61] + col[62] - col[63];
            sum[42] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] + col[16] + col[17] - col[18] -
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] - col[48] - col[49] + col[50] + col[51] - col[52] - col[53] + col[54] +
                      col[55] + col[56] + col[57] - col[58] - col[59] + col[60] + col[61] - col[62] - col[63];
            sum[43] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] + col[16] - col[17] - col[18] +
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] - col[48] + col[49] + col[50] - col[51] - col[52] + col[53] + col[54] -
                      col[55] + col[56] - col[57] - col[58] + col[59] + col[60] - col[61] - col[62] + col[63];
            sum[44] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] + col[16] + col[17] + col[18] +
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] - col[48] - col[49] - col[50] - col[51] + col[52] + col[53] + col[54] +
                      col[55] + col[56] + col[57] + col[58] + col[59] - col[60] - col[61] - col[62] - col[63];
            sum[45] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] + col[16] - col[17] + col[18] -
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] - col[48] + col[49] - col[50] + col[51] + col[52] - col[53] + col[54] -
                      col[55] + col[56] - col[57] + col[58] - col[59] - col[60] + col[61] - col[62] + col[63];
            sum[46] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] + col[16] + col[17] - col[18] -
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] - col[48] - col[49] + col[50] + col[51] + col[52] + col[53] - col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59] - col[60] - col[61] + col[62] + col[63];
            sum[47] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] + col[16] - col[17] - col[18] +
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] - col[48] + col[49] + col[50] - col[51] + col[52] - col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] + col[59] - col[60] + col[61] + col[62] - col[63];
            sum[48] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] + col[8] + col[9] +
                      col[10] + col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] - col[24] - col[25] - col[26] - col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] - col[40] - col[41] - col[42] - col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] + col[51] + col[52] + col[53] + col[54] +
                      col[55] + col[56] + col[57] + col[58] + col[59] + col[60] + col[61] + col[62] + col[63];
            sum[49] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] + col[8] - col[9] +
                      col[10] - col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] - col[24] + col[25] - col[26] + col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] - col[40] + col[41] - col[42] + col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] + col[50] - col[51] + col[52] - col[53] + col[54] -
                      col[55] + col[56] - col[57] + col[58] - col[59] + col[60] - col[61] + col[62] - col[63];
            sum[50] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] + col[8] + col[9] -
                      col[10] - col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] - col[24] - col[25] + col[26] + col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] - col[40] - col[41] + col[42] + col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] + col[56] + col[57] - col[58] - col[59] + col[60] + col[61] - col[62] - col[63];
            sum[51] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] + col[8] - col[9] -
                      col[10] + col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] - col[24] + col[25] + col[26] - col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] - col[40] + col[41] + col[42] - col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] + col[52] - col[53] - col[54] +
                      col[55] + col[56] - col[57] - col[58] + col[59] + col[60] - col[61] - col[62] + col[63];
            sum[52] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] + col[8] + col[9] +
                      col[10] + col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] - col[24] - col[25] - col[26] - col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] - col[40] - col[41] - col[42] - col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] + col[56] + col[57] + col[58] + col[59] - col[60] - col[61] - col[62] - col[63];
            sum[53] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] + col[8] - col[9] +
                      col[10] - col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] - col[24] + col[25] - col[26] + col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] - col[40] + col[41] - col[42] + col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] + col[56] - col[57] + col[58] - col[59] - col[60] + col[61] - col[62] + col[63];
            sum[54] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] + col[8] + col[9] -
                      col[10] - col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] - col[24] - col[25] + col[26] + col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] - col[40] - col[41] + col[42] + col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] + col[56] + col[57] - col[58] - col[59] - col[60] - col[61] + col[62] + col[63];
            sum[55] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] + col[8] - col[9] -
                      col[10] + col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] - col[24] + col[25] + col[26] - col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] - col[40] + col[41] + col[42] - col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] + col[56] - col[57] - col[58] + col[59] - col[60] + col[61] + col[62] - col[63];
            sum[56] = col[0] + col[1] + col[2] + col[3] + col[4] + col[5] + col[6] + col[7] - col[8] - col[9] -
                      col[10] - col[11] - col[12] - col[13] - col[14] - col[15] - col[16] - col[17] - col[18] -
                      col[19] - col[20] - col[21] - col[22] - col[23] + col[24] + col[25] + col[26] + col[27] +
                      col[28] + col[29] + col[30] + col[31] - col[32] - col[33] - col[34] - col[35] - col[36] -
                      col[37] - col[38] - col[39] + col[40] + col[41] + col[42] + col[43] + col[44] + col[45] +
                      col[46] + col[47] + col[48] + col[49] + col[50] + col[51] + col[52] + col[53] + col[54] +
                      col[55] - col[56] - col[57] - col[58] - col[59] - col[60] - col[61] - col[62] - col[63];
            sum[57] = col[0] - col[1] + col[2] - col[3] + col[4] - col[5] + col[6] - col[7] - col[8] + col[9] -
                      col[10] + col[11] - col[12] + col[13] - col[14] + col[15] - col[16] + col[17] - col[18] +
                      col[19] - col[20] + col[21] - col[22] + col[23] + col[24] - col[25] + col[26] - col[27] +
                      col[28] - col[29] + col[30] - col[31] - col[32] + col[33] - col[34] + col[35] - col[36] +
                      col[37] - col[38] + col[39] + col[40] - col[41] + col[42] - col[43] + col[44] - col[45] +
                      col[46] - col[47] + col[48] - col[49] + col[50] - col[51] + col[52] - col[53] + col[54] -
                      col[55] - col[56] + col[57] - col[58] + col[59] - col[60] + col[61] - col[62] + col[63];
            sum[58] = col[0] + col[1] - col[2] - col[3] + col[4] + col[5] - col[6] - col[7] - col[8] - col[9] +
                      col[10] + col[11] - col[12] - col[13] + col[14] + col[15] - col[16] - col[17] + col[18] +
                      col[19] - col[20] - col[21] + col[22] + col[23] + col[24] + col[25] - col[26] - col[27] +
                      col[28] + col[29] - col[30] - col[31] - col[32] - col[33] + col[34] + col[35] - col[36] -
                      col[37] + col[38] + col[39] + col[40] + col[41] - col[42] - col[43] + col[44] + col[45] -
                      col[46] - col[47] + col[48] + col[49] - col[50] - col[51] + col[52] + col[53] - col[54] -
                      col[55] - col[56] - col[57] + col[58] + col[59] - col[60] - col[61] + col[62] + col[63];
            sum[59] = col[0] - col[1] - col[2] + col[3] + col[4] - col[5] - col[6] + col[7] - col[8] + col[9] +
                      col[10] - col[11] - col[12] + col[13] + col[14] - col[15] - col[16] + col[17] + col[18] -
                      col[19] - col[20] + col[21] + col[22] - col[23] + col[24] - col[25] - col[26] + col[27] +
                      col[28] - col[29] - col[30] + col[31] - col[32] + col[33] + col[34] - col[35] - col[36] +
                      col[37] + col[38] - col[39] + col[40] - col[41] - col[42] + col[43] + col[44] - col[45] -
                      col[46] + col[47] + col[48] - col[49] - col[50] + col[51] + col[52] - col[53] - col[54] +
                      col[55] - col[56] + col[57] + col[58] - col[59] - col[60] + col[61] + col[62] - col[63];
            sum[60] = col[0] + col[1] + col[2] + col[3] - col[4] - col[5] - col[6] - col[7] - col[8] - col[9] -
                      col[10] - col[11] + col[12] + col[13] + col[14] + col[15] - col[16] - col[17] - col[18] -
                      col[19] + col[20] + col[21] + col[22] + col[23] + col[24] + col[25] + col[26] + col[27] -
                      col[28] - col[29] - col[30] - col[31] - col[32] - col[33] - col[34] - col[35] + col[36] +
                      col[37] + col[38] + col[39] + col[40] + col[41] + col[42] + col[43] - col[44] - col[45] -
                      col[46] - col[47] + col[48] + col[49] + col[50] + col[51] - col[52] - col[53] - col[54] -
                      col[55] - col[56] - col[57] - col[58] - col[59] + col[60] + col[61] + col[62] + col[63];
            sum[61] = col[0] - col[1] + col[2] - col[3] - col[4] + col[5] - col[6] + col[7] - col[8] + col[9] -
                      col[10] + col[11] + col[12] - col[13] + col[14] - col[15] - col[16] + col[17] - col[18] +
                      col[19] + col[20] - col[21] + col[22] - col[23] + col[24] - col[25] + col[26] - col[27] -
                      col[28] + col[29] - col[30] + col[31] - col[32] + col[33] - col[34] + col[35] + col[36] -
                      col[37] + col[38] - col[39] + col[40] - col[41] + col[42] - col[43] - col[44] + col[45] -
                      col[46] + col[47] + col[48] - col[49] + col[50] - col[51] - col[52] + col[53] - col[54] +
                      col[55] - col[56] + col[57] - col[58] + col[59] + col[60] - col[61] + col[62] - col[63];
            sum[62] = col[0] + col[1] - col[2] - col[3] - col[4] - col[5] + col[6] + col[7] - col[8] - col[9] +
                      col[10] + col[11] + col[12] + col[13] - col[14] - col[15] - col[16] - col[17] + col[18] +
                      col[19] + col[20] + col[21] - col[22] - col[23] + col[24] + col[25] - col[26] - col[27] -
                      col[28] - col[29] + col[30] + col[31] - col[32] - col[33] + col[34] + col[35] + col[36] +
                      col[37] - col[38] - col[39] + col[40] + col[41] - col[42] - col[43] - col[44] - col[45] +
                      col[46] + col[47] + col[48] + col[49] - col[50] - col[51] - col[52] - col[53] + col[54] +
                      col[55] - col[56] - col[57] + col[58] + col[59] + col[60] + col[61] - col[62] - col[63];
            sum[63] = col[0] - col[1] - col[2] + col[3] - col[4] + col[5] + col[6] - col[7] - col[8] + col[9] +
                      col[10] - col[11] + col[12] - col[13] - col[14] + col[15] - col[16] + col[17] + col[18] -
                      col[19] + col[20] - col[21] - col[22] + col[23] + col[24] - col[25] - col[26] + col[27] -
                      col[28] + col[29] + col[30] - col[31] - col[32] + col[33] + col[34] - col[35] + col[36] -
                      col[37] - col[38] + col[39] + col[40] - col[41] - col[42] + col[43] - col[44] + col[45] +
                      col[46] - col[47] + col[48] - col[49] - col[50] + col[51] - col[52] + col[53] + col[54] -
                      col[55] - col[56] + col[57] + col[58] - col[59] + col[60] - col[61] - col[62] + col[63];
            break;
    }
}
}
