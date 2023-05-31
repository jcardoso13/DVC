#include "../include/darknet.h"
#define NET_H 256
#define NET_W 256
#define NET_C 3
#define N_LAYERS 16
/*Layer 0-CONVOLUTIONAL*/
#define FOUTPUT_0 BASE+0
#define FSCALES_0 BASE+1048576
#define FR_MEAN_0 BASE+1048592
#define FR_VARIANCE_0 BASE+1048608
#define FWEIGHTS_0 BASE+1048624
#define FBIASES_0 BASE+1049056
/*Layer 1-MAXPOOL*/
#define FOUTPUT_1 BASE+1049072
/*Layer 2-CONVOLUTIONAL*/
#define FOUTPUT_2 BASE+1311216
#define FSCALES_2 BASE+1835504
#define FR_MEAN_2 BASE+1835536
#define FR_VARIANCE_2 BASE+1835568
#define FWEIGHTS_2 BASE+1835600
#define FBIASES_2 BASE+1840208
/*Layer 3-MAXPOOL*/
#define FOUTPUT_3 BASE+1840240
/*Layer 4-CONVOLUTIONAL*/
#define FOUTPUT_4 BASE+1971312
#define FSCALES_4 BASE+2233456
#define FR_MEAN_4 BASE+2233520
#define FR_VARIANCE_4 BASE+2233584
#define FWEIGHTS_4 BASE+2233648
#define FBIASES_4 BASE+2252080
/*Layer 5-MAXPOOL*/
#define FOUTPUT_5 BASE+2252144
/*Layer 6-CONVOLUTIONAL*/
#define FOUTPUT_6 BASE+2317680
#define FSCALES_6 BASE+2448752
#define FR_MEAN_6 BASE+2448880
#define FR_VARIANCE_6 BASE+2449008
#define FWEIGHTS_6 BASE+2449136
#define FBIASES_6 BASE+2522864
/*Layer 7-MAXPOOL*/
#define FOUTPUT_7 BASE+2522992
/*Layer 8-CONVOLUTIONAL*/
#define FOUTPUT_8 BASE+2555760
#define FSCALES_8 BASE+2621296
#define FR_MEAN_8 BASE+2621552
#define FR_VARIANCE_8 BASE+2621808
#define FWEIGHTS_8 BASE+2622064
#define FBIASES_8 BASE+2916976
/*Layer 9-MAXPOOL*/
#define FOUTPUT_9 BASE+2917232
/*Layer 10-CONVOLUTIONAL*/
#define FOUTPUT_10 BASE+2933616
#define FSCALES_10 BASE+2966384
#define FR_MEAN_10 BASE+2966896
#define FR_VARIANCE_10 BASE+2967408
#define FWEIGHTS_10 BASE+2967920
#define FBIASES_10 BASE+4147568
/*Layer 11-MAXPOOL*/
#define FOUTPUT_11 BASE+4148080
/*Layer 12-CONVOLUTIONAL*/
#define FOUTPUT_12 BASE+4156272
#define FSCALES_12 BASE+4172656
#define FR_MEAN_12 BASE+4173680
#define FR_VARIANCE_12 BASE+4174704
#define FWEIGHTS_12 BASE+4175728
#define FBIASES_12 BASE+8894320
/*-AVGPOOL*/
/*Layer 14-CONVOLUTIONAL*/
#define FOUTPUT_14 BASE+8895344
#define FWEIGHTS_14 BASE+8896344
#define FBIASES_14 BASE+9920344
/*Layer 15-SOFTMAX*/
#define FOUTPUT_15 BASE+9921344
layer g_layers[N_LAYERS]={/*GENERIC PARAMS-Layer 0*/
[0].type=0,		[0].activation=7,		[0].batch_normalize=1,		[0].batch=1,
[0].inputs=196608,		[0].outputs=1048576,		[0].n=16,
[0].h=256,		[0].w=256,		[0].c=3,
[0].out_h=256,		[0].out_w=256,		[0].out_c=16,
[0].size=3,		[0].stride=1,		[0].pad=1,
[0].index=0,		[0].classes=0,		[0].total=0,
/*GENERIC PARAMS-Layer 1*/
[1].type=3,		[1].activation=0,		[1].batch_normalize=0,		[1].batch=1,
[1].inputs=1048576,		[1].outputs=262144,		[1].n=0,
[1].h=256,		[1].w=256,		[1].c=16,
[1].out_h=128,		[1].out_w=128,		[1].out_c=16,
[1].size=2,		[1].stride=2,		[1].pad=1,
[1].index=0,		[1].classes=0,		[1].total=0,
/*GENERIC PARAMS-Layer 2*/
[2].type=0,		[2].activation=7,		[2].batch_normalize=1,		[2].batch=1,
[2].inputs=262144,		[2].outputs=524288,		[2].n=32,
[2].h=128,		[2].w=128,		[2].c=16,
[2].out_h=128,		[2].out_w=128,		[2].out_c=32,
[2].size=3,		[2].stride=1,		[2].pad=1,
[2].index=0,		[2].classes=0,		[2].total=0,
/*GENERIC PARAMS-Layer 3*/
[3].type=3,		[3].activation=0,		[3].batch_normalize=0,		[3].batch=1,
[3].inputs=524288,		[3].outputs=131072,		[3].n=0,
[3].h=128,		[3].w=128,		[3].c=32,
[3].out_h=64,		[3].out_w=64,		[3].out_c=32,
[3].size=2,		[3].stride=2,		[3].pad=1,
[3].index=0,		[3].classes=0,		[3].total=0,
/*GENERIC PARAMS-Layer 4*/
[4].type=0,		[4].activation=7,		[4].batch_normalize=1,		[4].batch=1,
[4].inputs=131072,		[4].outputs=262144,		[4].n=64,
[4].h=64,		[4].w=64,		[4].c=32,
[4].out_h=64,		[4].out_w=64,		[4].out_c=64,
[4].size=3,		[4].stride=1,		[4].pad=1,
[4].index=0,		[4].classes=0,		[4].total=0,
/*GENERIC PARAMS-Layer 5*/
[5].type=3,		[5].activation=0,		[5].batch_normalize=0,		[5].batch=1,
[5].inputs=262144,		[5].outputs=65536,		[5].n=0,
[5].h=64,		[5].w=64,		[5].c=64,
[5].out_h=32,		[5].out_w=32,		[5].out_c=64,
[5].size=2,		[5].stride=2,		[5].pad=1,
[5].index=0,		[5].classes=0,		[5].total=0,
/*GENERIC PARAMS-Layer 6*/
[6].type=0,		[6].activation=7,		[6].batch_normalize=1,		[6].batch=1,
[6].inputs=65536,		[6].outputs=131072,		[6].n=128,
[6].h=32,		[6].w=32,		[6].c=64,
[6].out_h=32,		[6].out_w=32,		[6].out_c=128,
[6].size=3,		[6].stride=1,		[6].pad=1,
[6].index=0,		[6].classes=0,		[6].total=0,
/*GENERIC PARAMS-Layer 7*/
[7].type=3,		[7].activation=0,		[7].batch_normalize=0,		[7].batch=1,
[7].inputs=131072,		[7].outputs=32768,		[7].n=0,
[7].h=32,		[7].w=32,		[7].c=128,
[7].out_h=16,		[7].out_w=16,		[7].out_c=128,
[7].size=2,		[7].stride=2,		[7].pad=1,
[7].index=0,		[7].classes=0,		[7].total=0,
/*GENERIC PARAMS-Layer 8*/
[8].type=0,		[8].activation=7,		[8].batch_normalize=1,		[8].batch=1,
[8].inputs=32768,		[8].outputs=65536,		[8].n=256,
[8].h=16,		[8].w=16,		[8].c=128,
[8].out_h=16,		[8].out_w=16,		[8].out_c=256,
[8].size=3,		[8].stride=1,		[8].pad=1,
[8].index=0,		[8].classes=0,		[8].total=0,
/*GENERIC PARAMS-Layer 9*/
[9].type=3,		[9].activation=0,		[9].batch_normalize=0,		[9].batch=1,
[9].inputs=65536,		[9].outputs=16384,		[9].n=0,
[9].h=16,		[9].w=16,		[9].c=256,
[9].out_h=8,		[9].out_w=8,		[9].out_c=256,
[9].size=2,		[9].stride=2,		[9].pad=1,
[9].index=0,		[9].classes=0,		[9].total=0,
/*GENERIC PARAMS-Layer 10*/
[10].type=0,		[10].activation=7,		[10].batch_normalize=1,		[10].batch=1,
[10].inputs=16384,		[10].outputs=32768,		[10].n=512,
[10].h=8,		[10].w=8,		[10].c=256,
[10].out_h=8,		[10].out_w=8,		[10].out_c=512,
[10].size=3,		[10].stride=1,		[10].pad=1,
[10].index=0,		[10].classes=0,		[10].total=0,
/*GENERIC PARAMS-Layer 11*/
[11].type=3,		[11].activation=0,		[11].batch_normalize=0,		[11].batch=1,
[11].inputs=32768,		[11].outputs=8192,		[11].n=0,
[11].h=8,		[11].w=8,		[11].c=512,
[11].out_h=4,		[11].out_w=4,		[11].out_c=512,
[11].size=2,		[11].stride=2,		[11].pad=1,
[11].index=0,		[11].classes=0,		[11].total=0,
/*GENERIC PARAMS-Layer 12*/
[12].type=0,		[12].activation=7,		[12].batch_normalize=1,		[12].batch=1,
[12].inputs=8192,		[12].outputs=16384,		[12].n=1024,
[12].h=4,		[12].w=4,		[12].c=512,
[12].out_h=4,		[12].out_w=4,		[12].out_c=1024,
[12].size=3,		[12].stride=1,		[12].pad=1,
[12].index=0,		[12].classes=0,		[12].total=0,
/*GENERIC PARAMS-Layer 13*/
[13].type=11,		[13].activation=0,		[13].batch_normalize=0,		[13].batch=1,
[13].inputs=16384,		[13].outputs=1024,		[13].n=0,
[13].h=4,		[13].w=4,		[13].c=1024,
[13].out_h=1,		[13].out_w=1,		[13].out_c=1024,
[13].size=0,		[13].stride=0,		[13].pad=0,
[13].index=0,		[13].classes=0,		[13].total=0,
/*GENERIC PARAMS-Layer 14*/
[14].type=0,		[14].activation=3,		[14].batch_normalize=0,		[14].batch=1,
[14].inputs=1024,		[14].outputs=1000,		[14].n=1000,
[14].h=1,		[14].w=1,		[14].c=1024,
[14].out_h=1,		[14].out_w=1,		[14].out_c=1000,
[14].size=1,		[14].stride=1,		[14].pad=0,
[14].index=0,		[14].classes=0,		[14].total=0,
/*GENERIC PARAMS-Layer 15*/
[15].type=4,		[15].activation=0,		[15].batch_normalize=0,		[15].batch=1,
[15].inputs=1000,		[15].outputs=1000,		[15].n=0,
[15].h=1,		[15].w=1,		[15].c=1000,
[15].out_h=0,		[15].out_w=0,		[15].out_c=0,
[15].size=0,		[15].stride=0,		[15].pad=0,
[15].index=0,		[15].classes=0,		[15].total=0};
#define WORKSPACE_SIZE 9437184
#define BASE 0x0
fixed_t fpvector[9921344]={0};fixed_t g_workspace[WORKSPACE_SIZE]={0};
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


/*-AVGPOOL*/
g_layers[13].forward=forward_maxpool_layer;

g_layers[14].output=&fpvector[FOUTPUT_14];
/*Layer 14-CONVOLUTIONAL*/
g_layers[14].forward=forward_convolutional_layer;
g_layers[14].weights=&fpvector[FWEIGHTS_14];
g_layers[14].biases=&fpvector[FBIASES_14];

g_layers[15].output=&fpvector[FOUTPUT_15];
/*Layer 15-SOFTMAX*/
g_layers[15].forward=forward_softmax_layer;
g_network.layers=g_layers;

}