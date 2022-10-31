#include "../include/darknet.h"
#define NET_H 416
#define NET_W 416
#define NET_C 3
#define N_LAYERS 24
/*Layer 0-CONVOLUTIONAL*/
#define FOUTPUT_0 BASE+0
#define FSCALES_0 BASE+2768896
#define FR_MEAN_0 BASE+2768912
#define FR_VARIANCE_0 BASE+2768928
#define FWEIGHTS_0 BASE+2768944
#define FBIASES_0 BASE+2769376
/*Layer 1-MAXPOOL*/
#define FOUTPUT_1 BASE+2769392
/*Layer 2-CONVOLUTIONAL*/
#define FOUTPUT_2 BASE+3461616
#define FSCALES_2 BASE+4846064
#define FR_MEAN_2 BASE+4846096
#define FR_VARIANCE_2 BASE+4846128
#define FWEIGHTS_2 BASE+4846160
#define FBIASES_2 BASE+4850768
/*Layer 3-MAXPOOL*/
#define FOUTPUT_3 BASE+4850800
/*Layer 4-CONVOLUTIONAL*/
#define FOUTPUT_4 BASE+5196912
#define FSCALES_4 BASE+5889136
#define FR_MEAN_4 BASE+5889200
#define FR_VARIANCE_4 BASE+5889264
#define FWEIGHTS_4 BASE+5889328
#define FBIASES_4 BASE+5907760
/*Layer 5-MAXPOOL*/
#define FOUTPUT_5 BASE+5907824
/*Layer 6-CONVOLUTIONAL*/
#define FOUTPUT_6 BASE+6080880
#define FSCALES_6 BASE+6426992
#define FR_MEAN_6 BASE+6427120
#define FR_VARIANCE_6 BASE+6427248
#define FWEIGHTS_6 BASE+6427376
#define FBIASES_6 BASE+6501104
/*Layer 7-MAXPOOL*/
#define FOUTPUT_7 BASE+6501232
/*Layer 8-CONVOLUTIONAL*/
#define FOUTPUT_8 BASE+6587760
#define FSCALES_8 BASE+6760816
#define FR_MEAN_8 BASE+6761072
#define FR_VARIANCE_8 BASE+6761328
#define FWEIGHTS_8 BASE+6761584
#define FBIASES_8 BASE+7056496
/*Layer 9-MAXPOOL*/
#define FOUTPUT_9 BASE+7056752
/*Layer 10-CONVOLUTIONAL*/
#define FOUTPUT_10 BASE+7100016
#define FSCALES_10 BASE+7186544
#define FR_MEAN_10 BASE+7187056
#define FR_VARIANCE_10 BASE+7187568
#define FWEIGHTS_10 BASE+7188080
#define FBIASES_10 BASE+8367728
/*Layer 11-MAXPOOL*/
#define FOUTPUT_11 BASE+8368240
/*Layer 12-CONVOLUTIONAL*/
#define FOUTPUT_12 BASE+8454768
#define FSCALES_12 BASE+8627824
#define FR_MEAN_12 BASE+8628848
#define FR_VARIANCE_12 BASE+8629872
#define FWEIGHTS_12 BASE+8630896
#define FBIASES_12 BASE+13349488
/*Layer 13-CONVOLUTIONAL*/
#define FOUTPUT_13 BASE+13350512
#define FSCALES_13 BASE+13393776
#define FR_MEAN_13 BASE+13394032
#define FR_VARIANCE_13 BASE+13394288
#define FWEIGHTS_13 BASE+13394544
#define FBIASES_13 BASE+13656688
/*Layer 14-CONVOLUTIONAL*/
#define FOUTPUT_14 BASE+13656944
#define FSCALES_14 BASE+13743472
#define FR_MEAN_14 BASE+13743984
#define FR_VARIANCE_14 BASE+13744496
#define FWEIGHTS_14 BASE+13745008
#define FBIASES_14 BASE+14924656
/*Layer 15-CONVOLUTIONAL*/
#define FOUTPUT_15 BASE+14925168
#define FWEIGHTS_15 BASE+14968263
#define FBIASES_15 BASE+15098823
/*Layer 16-YOLO*/
#define FOUTPUT_16 BASE+15099078
fixed_t biases_16[12]={655360,917504,1507328,1769472,2424832,3801088,5308416,5373952,8847360,11075584,22544384,20905984};
int mask_16[3]={3,4,5};
/*Layer 17-ROUTE*/
int input_layers_17[1]={13},input_sizes_17[1]={43264};
#define FOUTPUT_17 BASE+15142173
/*Layer 18-CONVOLUTIONAL*/
#define FOUTPUT_18 BASE+15185437
#define FSCALES_18 BASE+15207069
#define FR_MEAN_18 BASE+15207197
#define FR_VARIANCE_18 BASE+15207325
#define FWEIGHTS_18 BASE+15207453
#define FBIASES_18 BASE+15240221
/*Layer 19-UPSAMPLE*/
#define FOUTPUT_19 BASE+15240349
/*Layer 20-ROUTE*/
int input_layers_20[2]={19,8},input_sizes_20[2]={86528,173056};
#define FOUTPUT_20 BASE+15326877
/*Layer 21-CONVOLUTIONAL*/
#define FOUTPUT_21 BASE+15586461
#define FSCALES_21 BASE+15759517
#define FR_MEAN_21 BASE+15759773
#define FR_VARIANCE_21 BASE+15760029
#define FWEIGHTS_21 BASE+15760285
#define FBIASES_21 BASE+16645021
/*Layer 22-CONVOLUTIONAL*/
#define FOUTPUT_22 BASE+16645277
#define FWEIGHTS_22 BASE+16817657
#define FBIASES_22 BASE+16882937
/*Layer 23-YOLO*/
#define FOUTPUT_23 BASE+16883192
fixed_t biases_23[12]={655360,917504,1507328,1769472,2424832,3801088,5308416,5373952,8847360,11075584,22544384,20905984};
int mask_23[3]={0,1,2};
layer g_layers[N_LAYERS]={/*GENERIC PARAMS-Layer 0*/
[0].type=0,		[0].activation=7,		[0].batch_normalize=1,		[0].batch=1,
[0].inputs=519168,		[0].outputs=2768896,		[0].n=16,
[0].h=416,		[0].w=416,		[0].c=3,
[0].out_h=416,		[0].out_w=416,		[0].out_c=16,
[0].size=3,		[0].stride=1,		[0].pad=1,
[0].index=0,		[0].classes=0,		[0].total=0,
/*GENERIC PARAMS-Layer 1*/
[1].type=3,		[1].activation=0,		[1].batch_normalize=0,		[1].batch=1,
[1].inputs=2768896,		[1].outputs=692224,		[1].n=0,
[1].h=416,		[1].w=416,		[1].c=16,
[1].out_h=208,		[1].out_w=208,		[1].out_c=16,
[1].size=2,		[1].stride=2,		[1].pad=1,
[1].index=0,		[1].classes=0,		[1].total=0,
/*GENERIC PARAMS-Layer 2*/
[2].type=0,		[2].activation=7,		[2].batch_normalize=1,		[2].batch=1,
[2].inputs=692224,		[2].outputs=1384448,		[2].n=32,
[2].h=208,		[2].w=208,		[2].c=16,
[2].out_h=208,		[2].out_w=208,		[2].out_c=32,
[2].size=3,		[2].stride=1,		[2].pad=1,
[2].index=0,		[2].classes=0,		[2].total=0,
/*GENERIC PARAMS-Layer 3*/
[3].type=3,		[3].activation=0,		[3].batch_normalize=0,		[3].batch=1,
[3].inputs=1384448,		[3].outputs=346112,		[3].n=0,
[3].h=208,		[3].w=208,		[3].c=32,
[3].out_h=104,		[3].out_w=104,		[3].out_c=32,
[3].size=2,		[3].stride=2,		[3].pad=1,
[3].index=0,		[3].classes=0,		[3].total=0,
/*GENERIC PARAMS-Layer 4*/
[4].type=0,		[4].activation=7,		[4].batch_normalize=1,		[4].batch=1,
[4].inputs=346112,		[4].outputs=692224,		[4].n=64,
[4].h=104,		[4].w=104,		[4].c=32,
[4].out_h=104,		[4].out_w=104,		[4].out_c=64,
[4].size=3,		[4].stride=1,		[4].pad=1,
[4].index=0,		[4].classes=0,		[4].total=0,
/*GENERIC PARAMS-Layer 5*/
[5].type=3,		[5].activation=0,		[5].batch_normalize=0,		[5].batch=1,
[5].inputs=692224,		[5].outputs=173056,		[5].n=0,
[5].h=104,		[5].w=104,		[5].c=64,
[5].out_h=52,		[5].out_w=52,		[5].out_c=64,
[5].size=2,		[5].stride=2,		[5].pad=1,
[5].index=0,		[5].classes=0,		[5].total=0,
/*GENERIC PARAMS-Layer 6*/
[6].type=0,		[6].activation=7,		[6].batch_normalize=1,		[6].batch=1,
[6].inputs=173056,		[6].outputs=346112,		[6].n=128,
[6].h=52,		[6].w=52,		[6].c=64,
[6].out_h=52,		[6].out_w=52,		[6].out_c=128,
[6].size=3,		[6].stride=1,		[6].pad=1,
[6].index=0,		[6].classes=0,		[6].total=0,
/*GENERIC PARAMS-Layer 7*/
[7].type=3,		[7].activation=0,		[7].batch_normalize=0,		[7].batch=1,
[7].inputs=346112,		[7].outputs=86528,		[7].n=0,
[7].h=52,		[7].w=52,		[7].c=128,
[7].out_h=26,		[7].out_w=26,		[7].out_c=128,
[7].size=2,		[7].stride=2,		[7].pad=1,
[7].index=0,		[7].classes=0,		[7].total=0,
/*GENERIC PARAMS-Layer 8*/
[8].type=0,		[8].activation=7,		[8].batch_normalize=1,		[8].batch=1,
[8].inputs=86528,		[8].outputs=173056,		[8].n=256,
[8].h=26,		[8].w=26,		[8].c=128,
[8].out_h=26,		[8].out_w=26,		[8].out_c=256,
[8].size=3,		[8].stride=1,		[8].pad=1,
[8].index=0,		[8].classes=0,		[8].total=0,
/*GENERIC PARAMS-Layer 9*/
[9].type=3,		[9].activation=0,		[9].batch_normalize=0,		[9].batch=1,
[9].inputs=173056,		[9].outputs=43264,		[9].n=0,
[9].h=26,		[9].w=26,		[9].c=256,
[9].out_h=13,		[9].out_w=13,		[9].out_c=256,
[9].size=2,		[9].stride=2,		[9].pad=1,
[9].index=0,		[9].classes=0,		[9].total=0,
/*GENERIC PARAMS-Layer 10*/
[10].type=0,		[10].activation=7,		[10].batch_normalize=1,		[10].batch=1,
[10].inputs=43264,		[10].outputs=86528,		[10].n=512,
[10].h=13,		[10].w=13,		[10].c=256,
[10].out_h=13,		[10].out_w=13,		[10].out_c=512,
[10].size=3,		[10].stride=1,		[10].pad=1,
[10].index=0,		[10].classes=0,		[10].total=0,
/*GENERIC PARAMS-Layer 11*/
[11].type=3,		[11].activation=0,		[11].batch_normalize=0,		[11].batch=1,
[11].inputs=86528,		[11].outputs=86528,		[11].n=0,
[11].h=13,		[11].w=13,		[11].c=512,
[11].out_h=13,		[11].out_w=13,		[11].out_c=512,
[11].size=2,		[11].stride=1,		[11].pad=1,
[11].index=0,		[11].classes=0,		[11].total=0,
/*GENERIC PARAMS-Layer 12*/
[12].type=0,		[12].activation=7,		[12].batch_normalize=1,		[12].batch=1,
[12].inputs=86528,		[12].outputs=173056,		[12].n=1024,
[12].h=13,		[12].w=13,		[12].c=512,
[12].out_h=13,		[12].out_w=13,		[12].out_c=1024,
[12].size=3,		[12].stride=1,		[12].pad=1,
[12].index=0,		[12].classes=0,		[12].total=0,
/*GENERIC PARAMS-Layer 13*/
[13].type=0,		[13].activation=7,		[13].batch_normalize=1,		[13].batch=1,
[13].inputs=173056,		[13].outputs=43264,		[13].n=256,
[13].h=13,		[13].w=13,		[13].c=1024,
[13].out_h=13,		[13].out_w=13,		[13].out_c=256,
[13].size=1,		[13].stride=1,		[13].pad=0,
[13].index=0,		[13].classes=0,		[13].total=0,
/*GENERIC PARAMS-Layer 14*/
[14].type=0,		[14].activation=7,		[14].batch_normalize=1,		[14].batch=1,
[14].inputs=43264,		[14].outputs=86528,		[14].n=512,
[14].h=13,		[14].w=13,		[14].c=256,
[14].out_h=13,		[14].out_w=13,		[14].out_c=512,
[14].size=3,		[14].stride=1,		[14].pad=1,
[14].index=0,		[14].classes=0,		[14].total=0,
/*GENERIC PARAMS-Layer 15*/
[15].type=0,		[15].activation=3,		[15].batch_normalize=0,		[15].batch=1,
[15].inputs=86528,		[15].outputs=43095,		[15].n=255,
[15].h=13,		[15].w=13,		[15].c=512,
[15].out_h=13,		[15].out_w=13,		[15].out_c=255,
[15].size=1,		[15].stride=1,		[15].pad=0,
[15].index=0,		[15].classes=0,		[15].total=0,
/*GENERIC PARAMS-Layer 16*/
[16].type=23,		[16].activation=0,		[16].batch_normalize=0,		[16].batch=1,
[16].inputs=43095,		[16].outputs=43095,		[16].n=3,
[16].h=13,		[16].w=13,		[16].c=255,
[16].out_h=13,		[16].out_w=13,		[16].out_c=255,
[16].size=0,		[16].stride=0,		[16].pad=0,
[16].index=0,		[16].classes=80,		[16].total=6,
/*GENERIC PARAMS-Layer 17*/
[17].type=8,		[17].activation=0,		[17].batch_normalize=0,		[17].batch=1,
[17].inputs=43264,		[17].outputs=43264,		[17].n=1,
[17].h=0,		[17].w=0,		[17].c=0,
[17].out_h=13,		[17].out_w=13,		[17].out_c=256,
[17].size=0,		[17].stride=0,		[17].pad=0,
[17].index=0,		[17].classes=0,		[17].total=0,
/*GENERIC PARAMS-Layer 18*/
[18].type=0,		[18].activation=7,		[18].batch_normalize=1,		[18].batch=1,
[18].inputs=43264,		[18].outputs=21632,		[18].n=128,
[18].h=13,		[18].w=13,		[18].c=256,
[18].out_h=13,		[18].out_w=13,		[18].out_c=128,
[18].size=1,		[18].stride=1,		[18].pad=0,
[18].index=0,		[18].classes=0,		[18].total=0,
/*GENERIC PARAMS-Layer 19*/
[19].type=26,		[19].activation=0,		[19].batch_normalize=0,		[19].batch=1,
[19].inputs=21632,		[19].outputs=86528,		[19].n=0,
[19].h=13,		[19].w=13,		[19].c=128,
[19].out_h=26,		[19].out_w=26,		[19].out_c=128,
[19].size=0,		[19].stride=2,		[19].pad=0,
[19].index=0,		[19].classes=0,		[19].total=0,
/*GENERIC PARAMS-Layer 20*/
[20].type=8,		[20].activation=0,		[20].batch_normalize=0,		[20].batch=1,
[20].inputs=259584,		[20].outputs=259584,		[20].n=2,
[20].h=0,		[20].w=0,		[20].c=0,
[20].out_h=26,		[20].out_w=26,		[20].out_c=384,
[20].size=0,		[20].stride=0,		[20].pad=0,
[20].index=0,		[20].classes=0,		[20].total=0,
/*GENERIC PARAMS-Layer 21*/
[21].type=0,		[21].activation=7,		[21].batch_normalize=1,		[21].batch=1,
[21].inputs=259584,		[21].outputs=173056,		[21].n=256,
[21].h=26,		[21].w=26,		[21].c=384,
[21].out_h=26,		[21].out_w=26,		[21].out_c=256,
[21].size=3,		[21].stride=1,		[21].pad=1,
[21].index=0,		[21].classes=0,		[21].total=0,
/*GENERIC PARAMS-Layer 22*/
[22].type=0,		[22].activation=3,		[22].batch_normalize=0,		[22].batch=1,
[22].inputs=173056,		[22].outputs=172380,		[22].n=255,
[22].h=26,		[22].w=26,		[22].c=256,
[22].out_h=26,		[22].out_w=26,		[22].out_c=255,
[22].size=1,		[22].stride=1,		[22].pad=0,
[22].index=0,		[22].classes=0,		[22].total=0,
/*GENERIC PARAMS-Layer 23*/
[23].type=23,		[23].activation=0,		[23].batch_normalize=0,		[23].batch=1,
[23].inputs=172380,		[23].outputs=172380,		[23].n=3,
[23].h=26,		[23].w=26,		[23].c=255,
[23].out_h=26,		[23].out_w=26,		[23].out_c=255,
[23].size=0,		[23].stride=0,		[23].pad=0,
[23].index=0,		[23].classes=80,		[23].total=6};
#define WORKSPACE_SIZE 24920064
#define BASE 0x0
fixed_t fpvector[17055572]={0};fixed_t g_workspace[WORKSPACE_SIZE]={0};
network g_network = {
.n=N_LAYERS,
    .w= NET_W,
    .h = NET_H,
   .c = NET_C,
    .workspace=g_workspace,
  .input = NULL,
    .output = NULL,
   .layers=NULL
};
void define_layer_mem()
{

g_layers[0].output=&fpvector[FOUTPUT_0];
/*Layer 0-CONVOLUTIONAL*/
g_layers[0].forward=forward_convolutional_layer;
g_layers[0].scales=&fpvector[FSCALES_0];
g_layers[0].rolling_mean=&fpvector[FR_MEAN_0];
g_layers[0].rolling_variance=&fpvector[FR_VARIANCE_0];
g_layers[0].weights=&fpvector[FWEIGHTS_0];
g_layers[0].biases=&fpvector[FBIASES_0];

g_layers[1].output=&fpvector[FOUTPUT_1];
/*Layer 1-MAXPOOL*/
g_layers[1].forward=forward_maxpool_layer;

g_layers[2].output=&fpvector[FOUTPUT_2];
/*Layer 2-CONVOLUTIONAL*/
g_layers[2].forward=forward_convolutional_layer;
g_layers[2].scales=&fpvector[FSCALES_2];
g_layers[2].rolling_mean=&fpvector[FR_MEAN_2];
g_layers[2].rolling_variance=&fpvector[FR_VARIANCE_2];
g_layers[2].weights=&fpvector[FWEIGHTS_2];
g_layers[2].biases=&fpvector[FBIASES_2];

g_layers[3].output=&fpvector[FOUTPUT_3];
/*Layer 3-MAXPOOL*/
g_layers[3].forward=forward_maxpool_layer;

g_layers[4].output=&fpvector[FOUTPUT_4];
/*Layer 4-CONVOLUTIONAL*/
g_layers[4].forward=forward_convolutional_layer;
g_layers[4].scales=&fpvector[FSCALES_4];
g_layers[4].rolling_mean=&fpvector[FR_MEAN_4];
g_layers[4].rolling_variance=&fpvector[FR_VARIANCE_4];
g_layers[4].weights=&fpvector[FWEIGHTS_4];
g_layers[4].biases=&fpvector[FBIASES_4];

g_layers[5].output=&fpvector[FOUTPUT_5];
/*Layer 5-MAXPOOL*/
g_layers[5].forward=forward_maxpool_layer;

g_layers[6].output=&fpvector[FOUTPUT_6];
/*Layer 6-CONVOLUTIONAL*/
g_layers[6].forward=forward_convolutional_layer;
g_layers[6].scales=&fpvector[FSCALES_6];
g_layers[6].rolling_mean=&fpvector[FR_MEAN_6];
g_layers[6].rolling_variance=&fpvector[FR_VARIANCE_6];
g_layers[6].weights=&fpvector[FWEIGHTS_6];
g_layers[6].biases=&fpvector[FBIASES_6];

g_layers[7].output=&fpvector[FOUTPUT_7];
/*Layer 7-MAXPOOL*/
g_layers[7].forward=forward_maxpool_layer;

g_layers[8].output=&fpvector[FOUTPUT_8];
/*Layer 8-CONVOLUTIONAL*/
g_layers[8].forward=forward_convolutional_layer;
g_layers[8].scales=&fpvector[FSCALES_8];
g_layers[8].rolling_mean=&fpvector[FR_MEAN_8];
g_layers[8].rolling_variance=&fpvector[FR_VARIANCE_8];
g_layers[8].weights=&fpvector[FWEIGHTS_8];
g_layers[8].biases=&fpvector[FBIASES_8];

g_layers[9].output=&fpvector[FOUTPUT_9];
/*Layer 9-MAXPOOL*/
g_layers[9].forward=forward_maxpool_layer;

g_layers[10].output=&fpvector[FOUTPUT_10];
/*Layer 10-CONVOLUTIONAL*/
g_layers[10].forward=forward_convolutional_layer;
g_layers[10].scales=&fpvector[FSCALES_10];
g_layers[10].rolling_mean=&fpvector[FR_MEAN_10];
g_layers[10].rolling_variance=&fpvector[FR_VARIANCE_10];
g_layers[10].weights=&fpvector[FWEIGHTS_10];
g_layers[10].biases=&fpvector[FBIASES_10];

g_layers[11].output=&fpvector[FOUTPUT_11];
/*Layer 11-MAXPOOL*/
g_layers[11].forward=forward_maxpool_layer;

g_layers[12].output=&fpvector[FOUTPUT_12];
/*Layer 12-CONVOLUTIONAL*/
g_layers[12].forward=forward_convolutional_layer;
g_layers[12].scales=&fpvector[FSCALES_12];
g_layers[12].rolling_mean=&fpvector[FR_MEAN_12];
g_layers[12].rolling_variance=&fpvector[FR_VARIANCE_12];
g_layers[12].weights=&fpvector[FWEIGHTS_12];
g_layers[12].biases=&fpvector[FBIASES_12];

g_layers[13].output=&fpvector[FOUTPUT_13];
/*Layer 13-CONVOLUTIONAL*/
g_layers[13].forward=forward_convolutional_layer;
g_layers[13].scales=&fpvector[FSCALES_13];
g_layers[13].rolling_mean=&fpvector[FR_MEAN_13];
g_layers[13].rolling_variance=&fpvector[FR_VARIANCE_13];
g_layers[13].weights=&fpvector[FWEIGHTS_13];
g_layers[13].biases=&fpvector[FBIASES_13];

g_layers[14].output=&fpvector[FOUTPUT_14];
/*Layer 14-CONVOLUTIONAL*/
g_layers[14].forward=forward_convolutional_layer;
g_layers[14].scales=&fpvector[FSCALES_14];
g_layers[14].rolling_mean=&fpvector[FR_MEAN_14];
g_layers[14].rolling_variance=&fpvector[FR_VARIANCE_14];
g_layers[14].weights=&fpvector[FWEIGHTS_14];
g_layers[14].biases=&fpvector[FBIASES_14];

g_layers[15].output=&fpvector[FOUTPUT_15];
/*Layer 15-CONVOLUTIONAL*/
g_layers[15].forward=forward_convolutional_layer;
g_layers[15].weights=&fpvector[FWEIGHTS_15];
g_layers[15].biases=&fpvector[FBIASES_15];

g_layers[16].output=&fpvector[FOUTPUT_16];
/*Layer 16-YOLO*/
g_layers[16].forward=forward_yolo_layer;
g_layers[16].mask=mask_16;
g_layers[16].biases=biases_16;

g_layers[17].output=&fpvector[FOUTPUT_17];
/*Layer 17-ROUTE*/
g_layers[17].forward=forward_route_layer;
g_layers[17].input_layers=input_layers_17;
g_layers[17].input_sizes=input_sizes_17;

g_layers[18].output=&fpvector[FOUTPUT_18];
/*Layer 18-CONVOLUTIONAL*/
g_layers[18].forward=forward_convolutional_layer;
g_layers[18].scales=&fpvector[FSCALES_18];
g_layers[18].rolling_mean=&fpvector[FR_MEAN_18];
g_layers[18].rolling_variance=&fpvector[FR_VARIANCE_18];
g_layers[18].weights=&fpvector[FWEIGHTS_18];
g_layers[18].biases=&fpvector[FBIASES_18];

g_layers[19].output=&fpvector[FOUTPUT_19];
/*Layer 19-UPSAMPLE*/
g_layers[19].forward=forward_upsample_layer;

g_layers[20].output=&fpvector[FOUTPUT_20];
/*Layer 20-ROUTE*/
g_layers[20].forward=forward_route_layer;
g_layers[20].input_layers=input_layers_20;
g_layers[20].input_sizes=input_sizes_20;

g_layers[21].output=&fpvector[FOUTPUT_21];
/*Layer 21-CONVOLUTIONAL*/
g_layers[21].forward=forward_convolutional_layer;
g_layers[21].scales=&fpvector[FSCALES_21];
g_layers[21].rolling_mean=&fpvector[FR_MEAN_21];
g_layers[21].rolling_variance=&fpvector[FR_VARIANCE_21];
g_layers[21].weights=&fpvector[FWEIGHTS_21];
g_layers[21].biases=&fpvector[FBIASES_21];

g_layers[22].output=&fpvector[FOUTPUT_22];
/*Layer 22-CONVOLUTIONAL*/
g_layers[22].forward=forward_convolutional_layer;
g_layers[22].weights=&fpvector[FWEIGHTS_22];
g_layers[22].biases=&fpvector[FBIASES_22];

g_layers[23].output=&fpvector[FOUTPUT_23];
/*Layer 23-YOLO*/
g_layers[23].forward=forward_yolo_layer;
g_layers[23].mask=mask_23;
g_layers[23].biases=biases_23;
g_network.layers=g_layers;

}