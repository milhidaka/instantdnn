
#include <stdlib.h>
#include <math.h>

float static_buffer[9739889];
float* dynamic_buffer = nullptr;

int meta_buf_0[] = {6249787,6404374,51529,3,3,51529};
int meta_buf_1[] = {6404374,3245696,1,3,227,227,113,113,3,3,1,1,2,2,0,0};
int meta_buf_2[] = {3245696,0,722496,12769,64,27};
int meta_buf_3[] = {1728,722496,722496,64,64,64,12769};
int meta_buf_4[] = {722496,4644155,1,113,113,64,56,56,3,3,2,2,0,0};
int meta_buf_5[] = {4644155,1792,8459377,3136,16,64};
int meta_buf_6[] = {2816,8459377,8509553,16,3136,16,3136};
int meta_buf_7[] = {8509553,8559729,3136,16,16,3136};
int meta_buf_8[] = {8559729,1539712,1,16,56,56,56,56,3,3,1,1,1,1,1,1};
int meta_buf_9[] = {1539712,2832,4844859,3136,64,144};
int meta_buf_10[] = {12048,4844859,5045563,64,3136,64,3136};
int meta_buf_11[] = {8509553,8710257,3136,16,16,3136};
int meta_buf_12[] = {8710257,12112,5246267,3136,64,16};
int meta_buf_13[] = {13136,5246267,5446971,64,3136,64,3136};
int meta_buf_14[] = {2844288,4,2,5446971,5045563,1,1,401408,1,7168,128,401408,1,7168,128,1,64,56,56,1,64,56,56,0,64};
int meta_buf_15[] = {2844288,13200,8860785,3136,16,128};
int meta_buf_16[] = {15248,8860785,8910961,16,3136,16,3136};
int meta_buf_17[] = {8910961,8961137,3136,16,16,3136};
int meta_buf_18[] = {8961137,1991296,1,16,56,56,56,56,3,3,1,1,1,1,1,1};
int meta_buf_19[] = {1991296,15264,5647675,3136,64,144};
int meta_buf_20[] = {24480,5647675,5848379,64,3136,64,3136};
int meta_buf_21[] = {8910961,9011313,3136,16,16,3136};
int meta_buf_22[] = {9011313,24544,6049083,3136,64,16};
int meta_buf_23[] = {25568,6049083,4042043,64,3136,64,3136};
int meta_buf_24[] = {2442880,4,2,4042043,5848379,1,1,401408,1,7168,128,401408,1,7168,128,1,64,56,56,1,64,56,56,0,64};
int meta_buf_25[] = {2442880,6784753,1,56,56,128,28,28,3,3,2,2,0,0};
int meta_buf_26[] = {6784753,25632,9362545,784,32,128};
int meta_buf_27[] = {29728,9362545,9387633,32,784,32,784};
int meta_buf_28[] = {9387633,9412721,784,32,32,784};
int meta_buf_29[] = {9412721,3590459,1,32,28,28,28,28,3,3,1,1,1,1,1,1};
int meta_buf_30[] = {3590459,29760,6885105,784,128,288};
int meta_buf_31[] = {66624,6885105,6985457,128,784,128,784};
int meta_buf_32[] = {9387633,9437809,784,32,32,784};
int meta_buf_33[] = {9437809,66752,7085809,784,128,32};
int meta_buf_34[] = {70848,7085809,7186161,128,784,128,784};
int meta_buf_35[] = {4242747,4,2,7186161,6985457,1,1,200704,1,7168,256,200704,1,7168,256,1,128,28,28,1,128,28,28,0,128};
int meta_buf_36[] = {4242747,70976,9462897,784,32,256};
int meta_buf_37[] = {79168,9462897,9487985,32,784,32,784};
int meta_buf_38[] = {9487985,9513073,784,32,32,784};
int meta_buf_39[] = {9513073,3816251,1,32,28,28,28,28,3,3,1,1,1,1,1,1};
int meta_buf_40[] = {3816251,79200,7286513,784,128,288};
int meta_buf_41[] = {116064,7286513,7386865,128,784,128,784};
int meta_buf_42[] = {9487985,9538161,784,32,32,784};
int meta_buf_43[] = {9538161,116192,7487217,784,128,32};
int meta_buf_44[] = {120288,7487217,7587569,128,784,128,784};
int meta_buf_45[] = {4443451,4,2,7587569,7386865,1,1,200704,1,7168,256,200704,1,7168,256,1,128,28,28,1,128,28,28,0,128};
int meta_buf_46[] = {4443451,8208497,1,28,28,256,14,14,3,3,2,2,0,0};
int meta_buf_47[] = {8208497,120416,9663601,196,48,256};
int meta_buf_48[] = {132704,9663601,9673009,48,196,48,196};
int meta_buf_49[] = {9673009,9682417,196,48,48,196};
int meta_buf_50[] = {9682417,7888625,1,48,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_51[] = {7888625,132752,9061489,196,192,432};
int meta_buf_52[] = {215696,9061489,9099121,192,196,192,196};
int meta_buf_53[] = {9673009,9691825,196,48,48,196};
int meta_buf_54[] = {9691825,215888,9136753,196,192,48};
int meta_buf_55[] = {225104,9136753,9174385,192,196,192,196};
int meta_buf_56[] = {8057969,4,2,9174385,9099121,1,1,75264,1,5376,384,75264,1,5376,384,1,192,14,14,1,192,14,14,0,192};
int meta_buf_57[] = {8057969,225296,9701233,196,48,384};
int meta_buf_58[] = {243728,9701233,9710641,48,196,48,196};
int meta_buf_59[] = {9710641,9720049,196,48,48,196};
int meta_buf_60[] = {9720049,7973297,1,48,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_61[] = {7973297,243776,9212017,196,192,432};
int meta_buf_62[] = {326720,9212017,9249649,192,196,192,196};
int meta_buf_63[] = {9710641,9729457,196,48,48,196};
int meta_buf_64[] = {9729457,326912,9287281,196,192,48};
int meta_buf_65[] = {336128,9287281,9324913,192,196,192,196};
int meta_buf_66[] = {8133233,4,2,9324913,9249649,1,1,75264,1,5376,384,75264,1,5376,384,1,192,14,14,1,192,14,14,0,192};
int meta_buf_67[] = {8133233,336320,9563249,196,64,384};
int meta_buf_68[] = {360896,9563249,9575793,64,196,64,196};
int meta_buf_69[] = {9575793,9588337,196,64,64,196};
int meta_buf_70[] = {9588337,6558961,1,64,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_71[] = {6558961,360960,8258673,196,256,576};
int meta_buf_72[] = {508416,8258673,8308849,256,196,256,196};
int meta_buf_73[] = {9575793,9600881,196,64,64,196};
int meta_buf_74[] = {9600881,508672,8359025,196,256,64};
int meta_buf_75[] = {525056,8359025,8409201,256,196,256,196};
int meta_buf_76[] = {7687921,4,2,8409201,8308849,1,1,100352,1,7168,512,100352,1,7168,512,1,256,14,14,1,256,14,14,0,256};
int meta_buf_77[] = {7687921,525312,9613425,196,64,512};
int meta_buf_78[] = {558080,9613425,9625969,64,196,64,196};
int meta_buf_79[] = {9625969,9638513,196,64,64,196};
int meta_buf_80[] = {9638513,6671857,1,64,14,14,14,14,3,3,1,1,1,1,1,1};
int meta_buf_81[] = {6671857,558144,8609905,196,256,576};
int meta_buf_82[] = {705600,8609905,8660081,256,196,256,196};
int meta_buf_83[] = {9625969,9651057,196,64,64,196};
int meta_buf_84[] = {9651057,705856,8760433,196,256,64};
int meta_buf_85[] = {722240,8760433,8810609,256,196,256,196};
int meta_buf_86[] = {7788273,4,2,8810609,8660081,1,1,100352,1,7168,512,100352,1,7168,512,1,256,14,14,1,256,14,14,0,256};
int meta_buf_87[] = {7788273,9739377,1,14,14,512,1,1,13,13,13,13,0,0};
int meta_buf_88[] = {9739377,9738865,512};
int* meta_buffers[] = {meta_buf_0,meta_buf_1,meta_buf_2,meta_buf_3,meta_buf_4,meta_buf_5,meta_buf_6,meta_buf_7,meta_buf_8,meta_buf_9,meta_buf_10,meta_buf_11,meta_buf_12,meta_buf_13,meta_buf_14,meta_buf_15,meta_buf_16,meta_buf_17,meta_buf_18,meta_buf_19,meta_buf_20,meta_buf_21,meta_buf_22,meta_buf_23,meta_buf_24,meta_buf_25,meta_buf_26,meta_buf_27,meta_buf_28,meta_buf_29,meta_buf_30,meta_buf_31,meta_buf_32,meta_buf_33,meta_buf_34,meta_buf_35,meta_buf_36,meta_buf_37,meta_buf_38,meta_buf_39,meta_buf_40,meta_buf_41,meta_buf_42,meta_buf_43,meta_buf_44,meta_buf_45,meta_buf_46,meta_buf_47,meta_buf_48,meta_buf_49,meta_buf_50,meta_buf_51,meta_buf_52,meta_buf_53,meta_buf_54,meta_buf_55,meta_buf_56,meta_buf_57,meta_buf_58,meta_buf_59,meta_buf_60,meta_buf_61,meta_buf_62,meta_buf_63,meta_buf_64,meta_buf_65,meta_buf_66,meta_buf_67,meta_buf_68,meta_buf_69,meta_buf_70,meta_buf_71,meta_buf_72,meta_buf_73,meta_buf_74,meta_buf_75,meta_buf_76,meta_buf_77,meta_buf_78,meta_buf_79,meta_buf_80,meta_buf_81,meta_buf_82,meta_buf_83,meta_buf_84,meta_buf_85,meta_buf_86,meta_buf_87,meta_buf_88};

extern "C" void init() {
    //static_buffer = (float*)malloc(9739889 * sizeof(float));
}

extern "C" float* get_static_buffer(void) {
    return static_buffer;
}

extern "C" float* allocate_dynamic_buffer(int count) {
    if (dynamic_buffer) {
        free(dynamic_buffer);
        dynamic_buffer = nullptr;
    }
    dynamic_buffer = (float*)malloc(count * sizeof(float));
    return dynamic_buffer;
}

extern "C" float* get_dynamic_buffer(void) {
    return dynamic_buffer;
}
extern "C" void set_placeholder_value(int kernel_order, int offset, int value) {
    meta_buffers[kernel_order][offset] = value;
}

void transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    float * v2 = (static_buffer + meta_buffer[1]);
    const int v3 = meta_buffer[2];
    const int v4 = meta_buffer[3];
    const int D0 = meta_buffer[4];
    const int D1 = meta_buffer[5];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v5 = v1[d0*v3 + d1];
            float v6;
            {
                v6 = v5;
            }
            v2[d0 + d1*v4] = v6;
        }
    }
}


void im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(const int * meta_buffer)
{
    const float *im = (static_buffer + meta_buffer[0]);
    float *col = (static_buffer + meta_buffer[1]);

    const int N = meta_buffer[2];
    const int C1 = meta_buffer[3];
    const int H1 = meta_buffer[4];
    const int W1 = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];
    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
    const int DH = meta_buffer[10];
    const int DW = meta_buffer[11];
    const int SH = meta_buffer[12];
    const int SW = meta_buffer[13];
    const int PH = meta_buffer[14];
    const int PW = meta_buffer[15];

    for (int gid = 0; gid < N*H2*W2*KH*KW*C1; gid += 1) {
        const int c1 = gid % C1;
        const int kw = gid / C1 % KW;
        const int kh = gid / C1 / KW % KH;
        const int w2 = gid / C1 / KW / KH % W2;
        const int h2 = gid / C1 / KW / KH / W2 % H2;
        const int  n = gid / C1 / KW / KH / W2 / H2;

        const int h1 = h2 * SH - PH + kh * DH;
        const int w1 = w2 * SW - PW + kw * DW;

        col[gid] = (h1 < 0 || h1 >= H1 || w1 < 0 || w1 >= W1) ? 0 : im[((n*H1+h1)*W1+w1)*C1+c1];
    }
}


#ifndef INCLUDE_EIGEN
#define INCLUDE_EIGEN
#include <Eigen/Dense>
#endif

void tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(const int * meta_buffer)
{
    float *A = (static_buffer + meta_buffer[0]);
    float *B = (static_buffer + meta_buffer[1]);
    float *C = (static_buffer + meta_buffer[2]);

    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > a_mat(A, meta_buffer[3], meta_buffer[5]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::ColMajor> > b_mat(B, meta_buffer[5], meta_buffer[4]);
    Eigen::Map<Eigen::Matrix<float, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> > c_mat(C, meta_buffer[3], meta_buffer[4]);

    c_mat.noalias() = a_mat * b_mat;
}


void fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0 + d1*v5] = v9;
        }
    }
}


void maxpooling2d_386ebef75ea973afd833e12e5ea8f6c97456944cd3812afb94b9bb4e(const int * meta_buffer)
{
    const float *X = (static_buffer + meta_buffer[0]);
    float *Y = (static_buffer + meta_buffer[1]);
    const int N = meta_buffer[2];
    const int H1 = meta_buffer[3];
    const int W1 = meta_buffer[4];
    const int C = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];
    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
    const int SH = meta_buffer[10];
    const int SW = meta_buffer[11];
    const int PH = meta_buffer[12];
    const int PW = meta_buffer[13];

    for (int gid = 0; gid < N * H2 * W2 * C; gid += 1) {
        const int c = gid % C;
        const int w2 = gid / C % W2;
        const int h2 = gid / C / W2 % H2;
        const int n = gid / C / W2 / H2;

        float v = -1e7;
        for (int kh = 0; kh < KH; kh++) {
            const int h1 = h2 * SH - PH + kh;
            if (h1 < 0 || h1 >= H1) continue;

            for (int kw = 0; kw < KW; kw++) {
                const int w1 = w2 * SW - PW + kw;
                if (w1 < 0 || w1 >= W1) continue;

                v = v > X[((n * H1 + h1) * W1 + w1) * C + c] ? v : X[((n * H1 + h1) * W1 + w1) * C + c];
            }
        }

        Y[gid] = v;
    }
}


void fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    const float * v2 = (static_buffer + meta_buffer[1]);
    float * v3 = (static_buffer + meta_buffer[2]);
    const int v4 = meta_buffer[3];
    const int v5 = meta_buffer[4];
    const int D0 = meta_buffer[5];
    const int D1 = meta_buffer[6];
    int d0;
    for (d0 = ((1 > 8) ? (0 % (1 / 8)) : 0); d0 < D0; d0 += ((1 > 8) ? (1 / 8) : 1)) {
        const float v6 = v1[d0];
        int d1;
        for (d1 = ((1 > 8) ? (0 / (1 / 8)) : 0); d1 < D1; d1 += ((1 > 8) ? 8 : 1)) {
            const float v7 = v2[d0 + d1*v4];
            float v8;
            {
                v8 = v7 + v6;
            }
            float v9;
            {
                v9 = v8 > 0 ? v8 : 0;
            }
            v3[d0*v5 + d1] = v9;
        }
    }
}


void concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(const int * meta_buffer)
{
    float *y = (static_buffer + meta_buffer[0]);
    const int N = meta_buffer[2];
    const int D = meta_buffer[1];
    const int *y_offsets = (&(meta_buffer[23]));
    const int *x_shapes = (&(meta_buffer[15]));
    const int *x_strides_in_y = (&(meta_buffer[7]));

    int x_index = 0;

    for (int n = 0; n < N; n++) {
        const float *x = (meta_buffer[3+2+(n)]?static_buffer:dynamic_buffer) + meta_buffer[3 + (n)];
        const int y_offset = y_offsets[n];
        const int *x_shape = x_shapes + n * D;
        const int *x_stride_in_y = x_strides_in_y + n * D;

        int x_size = 1;
        for (int d = 0; d < D; d++) {
            x_size *= x_shape[d];
        }

        while (x_index < x_size) {
            int y_index = y_offset;
            int s = x_index;
            for (int d = D-1; d >= 0; d--) {
                y_index += x_stride_in_y[d] * (s % x_shape[d]);
                s /= x_shape[d];
            }

            y[y_index] = x[x_index];

            x_index++;
        }

        x_index -= x_size;
    }
}


void averagepooling2d_315133a9f01ff68a853da10590f9591258950d2d5ab8b7bac49ab0ea(const int * meta_buffer)
{
    const float *X = (static_buffer + meta_buffer[0]);
    float *Y = (static_buffer + meta_buffer[1]);
    const int N = meta_buffer[2];
    const int H1 = meta_buffer[3];
    const int W1 = meta_buffer[4];
    const int C = meta_buffer[5];
    const int H2 = meta_buffer[6];
    const int W2 = meta_buffer[7];

    const int KH = meta_buffer[8];
    const int KW = meta_buffer[9];
    const int SH = meta_buffer[10];
    const int SW = meta_buffer[11];
    const int PH = meta_buffer[12];
    const int PW = meta_buffer[13];

    for (int gid = 0; gid < N * H2 * W2 * C; gid += 1) {
        const int c = gid % C;
        const int w2 = gid / C % W2;
        const int h2 = gid / C / W2 % H2;
        const int n = gid / C / W2 / H2;

        float v = 0;
        
        for (int kh = 0; kh < KH; kh++) {
            const int h1 = h2 * SH - PH + kh;
            if (h1 < 0 || h1 >= H1) continue;

            for (int kw = 0; kw < KW; kw++) {
                const int w1 = w2 * SW - PW + kw;
                if (w1 < 0 || w1 >= W1) continue;

                v += X[((n * H1 + h1) * W1 + w1) * C + c];
                
            }
        }
        v /= KH * KW;

        Y[gid] = v;
    }
}


void transpose_6c1a5765207ae813be68b295e01081389ed8f452899e3a431cad37f6(const int * meta_buffer)
{
    const float * v1 = (static_buffer + meta_buffer[0]);
    float * v2 = (static_buffer + meta_buffer[1]);
    const int D0 = meta_buffer[2];
    int d0;
    for (d0 = 0; d0 < D0; d0 += 1) {
        const float v3 = v1[d0];
        float v4;
        {
            v4 = v3;
        }
        v2[d0] = v4;
    }
}

extern "C" void run() {
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_0);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_1);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_2);
fusedelementwise_39f491a753592bd6d9a83c6f76917012b5eb3c0ac597e095aa174319(meta_buf_3);
maxpooling2d_386ebef75ea973afd833e12e5ea8f6c97456944cd3812afb94b9bb4e(meta_buf_4);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_5);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_6);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_7);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_8);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_9);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_10);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_11);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_12);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_13);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_14);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_15);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_16);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_17);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_18);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_19);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_20);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_21);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_22);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_23);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_24);
maxpooling2d_386ebef75ea973afd833e12e5ea8f6c97456944cd3812afb94b9bb4e(meta_buf_25);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_26);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_27);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_28);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_29);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_30);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_31);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_32);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_33);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_34);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_35);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_36);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_37);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_38);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_39);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_40);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_41);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_42);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_43);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_44);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_45);
maxpooling2d_386ebef75ea973afd833e12e5ea8f6c97456944cd3812afb94b9bb4e(meta_buf_46);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_47);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_48);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_49);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_50);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_51);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_52);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_53);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_54);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_55);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_56);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_57);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_58);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_59);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_60);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_61);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_62);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_63);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_64);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_65);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_66);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_67);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_68);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_69);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_70);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_71);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_72);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_73);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_74);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_75);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_76);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_77);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_78);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_79);
im2col_54f86552263d1a348fd988a8122143d1a6ec1c1aa7867ba5833442fb(meta_buf_80);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_81);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_82);
transpose_3ede431373fd6b14a21ca5a7f2fab289eb4c42220e346f22acc816e8(meta_buf_83);
tensordot_b0c87b9ad9c24d5c638538a68fd9e1ad2b472c70c0e98883fad5c6af(meta_buf_84);
fusedelementwise_98dfb71cb3aa5495493f1ed73dda277b60580ec81e0a2a17444e0ee4(meta_buf_85);
concat_9dc48661f18df861021d8647f2b13b42a014c55639541640b11390e0(meta_buf_86);
averagepooling2d_315133a9f01ff68a853da10590f9591258950d2d5ab8b7bac49ab0ea(meta_buf_87);
transpose_6c1a5765207ae813be68b295e01081389ed8f452899e3a431cad37f6(meta_buf_88);

}

