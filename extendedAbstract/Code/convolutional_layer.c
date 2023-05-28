#include "convolutional_layer.h"
#include "utils.h"
#include "batchnorm_layer.h"
#include "im2col.h"
#include "blas.h"
#include "gemm.h"

#include <stdio.h>
#include <time.h>

fixed_t max=0;
fixed_t min=0;

int convolutional_out_height(layer l) {
    return (l.h + 2*l.pad - l.size) / l.stride + 1;
}

int convolutional_out_width(layer l) {
    return (l.w + 2*l.pad - l.size) / l.stride + 1;
}

void add_bias(fixed_t *output, fixed_t *biases, int batch, int n, int size) {
    int i,j,b;
    for(b = 0; b < batch; ++b){
        for(i = 0; i < n; ++i){
            for(j = 0; j < size; ++j){
                output[(b*n + i)*size + j] += biases[i];
                if(output[(b*n + i)*size + j]>max)
                max=output[(b*n + i)*size + j];
                if(output[(b*n + i)*size + j]<min)
                min=output[(b*n + i)*size + j];
            }
        }
    }
}

void scale_bias(fixed_t *output, fixed_t *scales, int batch, int n, int size) {
    int i,j,b;
    for(b = 0; b < batch; ++b){
        for(i = 0; i < n; ++i){
            for(j = 0; j < size; ++j){
                //output[(b*n + i)*size + j] *= scales[i];
               output[(b*n + i)*size + j]=fixed_mul(output[(b*n + i)*size + j],scales[i]);
               if(output[(b*n + i)*size + j]>max){
                max=output[(b*n + i)*size + j];
               }
                if(output[(b*n + i)*size + j]<min)
                min=output[(b*n + i)*size + j];
            }
        }
    }
}

void forward_convolutional_layer(layer l, network net) {
    
    int m = l.n; //number of filters
    int k = l.size*l.size*l.c; //filter dimensions * number of colours
    int n = l.out_w*l.out_h; //output dimension
	      
	fixed_t *a = l.weights; //weight base address
	fixed_t *b = net.workspace; //max network's layer size
	fixed_t *c = l.output; //layer output
	fixed_t *im =  net.input; //layer input


	//Unroll image
	if (l.size == 1) b = im;
	else im2col_cpu(im, l.c, l.h, l.w, l.size, l.stride, l.pad, b);
	//Perform convolution
	gemm(0, 0, m, n, k, POINT, a, k, b, n, POINT, c, n);

    

	//Normalize, scale and add bias
    if(l.batch_normalize) forward_batchnorm_layer(l, net);
    else add_bias(l.output, l.biases, l.batch, l.n, l.out_h*l.out_w);


	//Apply activation method
    activate_array(l.output, l.outputs*l.batch, l.activation);
    //printf("max=%f,min=%f\n",fixed_to_float(max),fixed_to_float(min));



}