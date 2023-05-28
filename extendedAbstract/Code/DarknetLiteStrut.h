struct layer{
					//Generic
						LAYER_TYPE type; //identifies layer's type
						ACTIVATION activation; //identifies layer's activation function
						void (*forward)   (struct layer, struct network); //associated with forward method of each type of layer
						int groups;
					// Convolutional
						int batch_normalize; //indicates layer output must be normalized before applying activation function
						int batch; //always 1
						int inputs; //size of layer input
						int outputs; //size of layer output
						int h,w,c; //input dimensions
						int out_h, out_w, out_c; //output dimensions
						int n; //number of filters
						int size; //size of filter
						int stride; //indicates how many positions kernel moves
						int pad; //indicates size of padding sorrounding image
					
					//Shortcut
						int index; //used in shortcut layer
						
						int classes; //used in yolo layer
						int *mask; //used in yolo layer
						int total; //used in yolo layer
						int   * input_layers; //used in route layer
						int   * input_sizes; //used in route layer
						fixed_t * biases; //used for convolutional and yolo layers
						fixed_t * scales; //used for convolutional layers with batch_normalize
						fixed_t * weights; //convolutional layer weights
						fixed_t * output; //layer output /result
						fixed_t * rolling_mean; //used for normalize_cpu
						fixed_t * rolling_variance; //used for normalize_cpu
						size_t workspace_size; //indicates max output size among all layers
					
					
						//Generic Var
						fixed_t f1; // float->fixed 32 bit
					};