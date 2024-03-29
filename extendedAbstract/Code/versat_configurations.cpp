#include "Versat.hpp"
//The point of this file is to store configurations

/*
simd_mult(versat_t* vector_a, int width,versat_t* vector_b)
{

}

simd_add(versat_t* vector_a,int width,versat_t* vector_b)
{
	
}
*/
int alu_operation(CStage* obj,int op_a,int op_b,int index, int alu_index,int operation) // alu_index 0 for ALU, 1 for ALU_LITE
{
	if (alu_index == 0)
	{
		obj->alu[index].setOpA(op_a);
		obj->alu[index].setOpB(op_b);
		obj->alu[index].setFNS(operation);
		return sALU[index];
	}
	else
	{
		obj->alulite[index].setOpA(op_a);
		obj->alulite[index].setOpB(op_b);
		obj->alulite[index].setFNS(operation);
		return sALULITE[index];
	}

	return sALU[index];
}


int mul_operation(CStage* obj, int op_a, int op_b, int index, int operation)
{
		obj->mul[index].setSelA(op_a);
		obj->mul[index].setSelB(op_b);
		obj->mul[index].setFNS(operation);
		return sMUL[index];
}

int muladd_operation(CStage* obj, int op_a, int op_b, int index, int operation,int iter,int per, int delay, int shift)
{
	//  acumulates till end of PER, ITER repeats X times
	obj->muladd[index].setSelA(op_a);
	obj->muladd[index].setSelB(op_b);
	obj->muladd[index].setFNS(operation);
	obj->muladd[index].setIter(iter);
	obj->muladd[index].setPer(per);
	obj->muladd[index].setDelay(delay);
	return sMULADD[index];
}

int bs_operation(CStage* obj, int op_a, int shift, int index, int operation)
{
	obj->bs[index].setData(op_a);
	obj->bs[index].setFNS(operation);
	obj->bs[index].setShift(shift);
	return sBS[index];
}

int set_ExtMem_Read(CStage* obj,int index,Acumulator ext_loop)
{
	obj->vi[index].setExtIter(ext_loop.iter);
	obj->vi[index].setExtPer(ext_loop.per);
	obj->vi[index].setExtIncr(ext_loop.incr);
	obj->vi[index].setExtShift(ext_loop.shift);
	obj->vi[index].setExtAddr(ext_loop.extAddr);
	obj->vi[index].setIntAddr(ext_loop.intAddr);
	return sVI[index];
}

int set_IntMem_Read(CStage* obj,int index,Acumulator loop)
{
	switch(loop.nloops)
	{
		case 6:
		case 5:loop.incr2+=loop.shift*loop.iter+(loop.incr*loop.per)*loop.iter; // 4 + 2*2 = 8
			   loop.incr3+=loop.shift2*loop.iter2+(loop.incr2*loop.per2)*loop.iter2;
				break;
		case 4:
		case 3:loop.incr2+=loop.shift*loop.iter+(loop.incr*loop.per)*loop.iter;
		default : break;
	}
	obj->vi[index].setIntIter(loop.iter);
	obj->vi[index].setIntPer(loop.per);
	obj->vi[index].setIntIter2(loop.iter2);
	obj->vi[index].setIntPer2(loop.per2);
	obj->vi[index].setIntIter3(loop.iter3);
	obj->vi[index].setIntPer3(loop.per3);
	obj->vi[index].setIntIncr(loop.incr);
	obj->vi[index].setIntIncr2(loop.incr2);
	obj->vi[index].setIntIncr3(loop.incr3);
	obj->vi[index].setIntShift(loop.shift);
	obj->vi[index].setIntShift2(loop.shift2);
	obj->vi[index].setIntShift3(loop.shift3);
	obj->vi[index].setDuty(loop.duty);
	obj->vi[index].setDelay(loop.delay);
	obj->vi[index].setIntStart(loop.start);
	return sVI[index];
}


int set_IntMem_Write(CStage* obj,int index,Acumulator loop,int sel)
{
	//Each pair of loops is an acumulator.
	//The pairs work independently, so when going to use the 3rd loop, the iterator is reset to 0
	//this is not intended on this specific API
	//we want to iterate over data without being reset to loop.Start;
	switch(loop.nloops)
	{
		case 6:
		case 5:loop.incr2+=loop.shift*loop.iter+(loop.incr*loop.per)*loop.iter; // 4 + 2*2 = 8
			   loop.incr3+=loop.shift2*loop.iter2+(loop.incr2*loop.per2)*loop.iter2;
				break;
		case 4:
		case 3:loop.incr2+=loop.shift*loop.iter+(loop.incr*loop.per)*loop.iter;
		default : break;
	}
	obj->vo[index].setIntIter(loop.iter);
	obj->vo[index].setIntPer(loop.per);
	obj->vo[index].setIntIter2(loop.iter2);
	obj->vo[index].setIntPer2(loop.per2);
	obj->vo[index].setIntIncr(loop.incr);
	obj->vo[index].setIntIncr2(loop.incr2);
	obj->vo[index].setIntShift(loop.shift);
	obj->vo[index].setIntShift2(loop.shift2);
	obj->vo[index].setDuty(loop.duty);
	obj->vo[index].setDelay(loop.delay);
	obj->vo[index].setIntStart(loop.start);
	obj->vo[index].setSel(sel);


	return 0;
}

int set_ExtMem_Write(CStage* obj,int index,Acumulator ext_loop)
{
	obj->vo[index].setExtIter(ext_loop.iter);
	obj->vo[index].setExtPer(ext_loop.per);
	obj->vo[index].setExtIncr(ext_loop.incr);
	obj->vo[index].setExtShift(ext_loop.shift);
	obj->vo[index].setExtAddr(ext_loop.extAddr);
	obj->vo[index].setIntAddr(ext_loop.intAddr);
	return 0;
}




/************************************************************************
 * matrix_mult
 * description:
 * Creates the Configurations for a Stage to perform a Matrix Multiplication between Matrix A and Matrix B.
 * Both Matrixes must have a size lower than half of MEM_SIZE to fit inside each Memory.
 * Parameters:
 *		input	Versat	-	CStage Object that contains the stage to implement this matrix_mult.
 *		input	matrix_a	-	Matrix A
 *		input	matrix_b	-	Matrix B
 *		input	r_a,r_b	-	Row Number of Matrix A and B
 * 		input	c_a,c_b	-	Column Number of Matrix A and B	
 * 		input	store	-	True = store Matrix Multiplication in Memory and then
 * returns: Position in the Databus to get Results of Matrix Multiplication
 ************************************************************************/
int matrix_mult(CStage* Versat,int matrix_a,int matrix_b,int result_matrix,int r_a,int c_a,int r_b,int c_b,bool store)
{
	Acumulator store_matrix_A= Acumulator();
	Acumulator store_matrix_B= Acumulator();

	// Send Data from DDR to Versat Memory
	store_matrix_A.add_loop(r_a*c_a);
	store_matrix_A.loop_settings(0,0,0,matrix_a,0);
	store_matrix_B.add_loop(r_b*c_b);
	store_matrix_B.loop_settings(0,0,0,matrix_b,0);

	
	set_ExtMem_Read(Versat,0,store_matrix_A);
	set_ExtMem_Read(Versat,1,store_matrix_B);

	Acumulator read_matrix_A = Acumulator();
	Acumulator read_matrix_B = Acumulator();

	// Read from Matrix A in Versat
		read_matrix_A.add_loop(r_a,c_a);
			read_matrix_A.add_loop(c_b,-c_a);
				read_matrix_A.add_loop(c_a,1);
					read_matrix_A.loop_settings(0);
					set_IntMem_Read(Versat,0,read_matrix_A);
	// Read from Matrix B in Versat
		read_matrix_B.add_loop(r_a,-c_b);
			read_matrix_B.add_loop(c_b,-r_b*c_b+1);
				read_matrix_B.add_loop(r_b,c_b);
					read_matrix_B.loop_settings(0);
					set_IntMem_Read(Versat,1,read_matrix_B);

	// Do multiplication of the values and accumulate.
	muladd_operation(Versat,sVI[0],sVI[1],0,MULADD_MACC,r_a*c_b,c_a,MEMP_LAT,0);

	// Store the results in Memory.
	if(store==true)
	{
		Acumulator write_matrix = Acumulator();
		write_matrix.add_loop(r_a*c_b,1);
		write_matrix.loop_settings(0,0,MEMP_LAT+MULADD_LAT,result_matrix,0);
		set_ExtMem_Write(Versat,0,write_matrix);
			write_matrix.add_loop(c_a,0);
			set_IntMem_Write(Versat,0,write_matrix,sMULADD[0]);
	}



	return sMULADD[0];
}

int dot_product(CStage* Versat,int vector_a,int vector_b,int result,int length,bool store)
{
	Acumulator store_matrix_A= Acumulator();
	Acumulator store_matrix_B= Acumulator();

	store_matrix_A.add_loop(length);
	store_matrix_A.loop_settings(0,0,0,vector_a,0);
	store_matrix_B.add_loop(length);
	store_matrix_B.loop_settings(0,0,0,vector_b,0);

	Acumulator read_matrix_A = Acumulator();
	Acumulator read_matrix_B = Acumulator();

	read_matrix_A.add_loop(length);
	read_matrix_B.add_loop(length);

	muladd_operation(Versat,sVI[0],sVI[1],0,MULADD_MACC,1,length,MEMP_LAT,0);


	if(store==true)
	{
		Acumulator write_matrix = Acumulator();
		write_matrix.add_loop(length,1);
		write_matrix.loop_settings(0,0,MEMP_LAT+MULADD_LAT,result,0);
		set_ExtMem_Write(Versat,0,write_matrix);
			write_matrix.add_loop(length,0);
			set_IntMem_Write(Versat,0,write_matrix,sMULADD[0]);
	}

	return sMULADD[0];
}
/*	numer of filters
	output dimension
	filter dimension * number of collors,
	weights
	workspace
	output
*/
int load_data(CStage* Versat,int index,int addr,int size)
{
	Acumulator load= Acumulator();
	load.add_loop(size);
	load.loop_settings(0,0,0,addr,0);
	set_ExtMem_Read(Versat,index,load);
	return index;
}
int write_data(CStage* Versat,int index,int DDR_addr,int size,int versat_addr)
{
	Acumulator load= Acumulator();
	load.add_loop(size);
	load.loop_settings(0,0,0,DDR_addr,versat_addr);
	set_ExtMem_Write(Versat,index,load);
	return index;
}


void pad_input(int pad,int new_addr,int input_addr,int channels,int height,int width)
{
	int cur=0;
	for(int i=0;i<channels;i++)
		for(int j=0;j<height+2*pad;j++)
			for(int k=0;k<width+2*pad;k++)
			{
				if(k>=width+pad || j>=height+pad || k<pad || j<pad)
					cur=0;
				else
					cur=FPGA_mem[input_addr+(k-pad)+(j-pad)*width+i*height*width];
			FPGA_mem[new_addr+k+j*(width+pad)+i*(height+pad)*(width+pad)] = cur;
			}
}
//makes it easier to compute convolutions
void xyz_to_zxy(int pad,int new_addr,int input_addr,int channels,int height,int width)
{
		for(int j=0;j<height+2*pad;j++)
			for(int k=0;k<width+2*pad;k++)
				for(int i=0;i<channels;i++)
				{
					FPGA_mem[new_addr+i+k*(channels)+j*(channels)*(width+pad)]=FPGA_mem[input_addr+k+j*width+i*height*width];
				}
}
/*
int convolutional_layer_xyz(CStage* Versat,int input_addr,int channels,int height, int width, int kernel_size, int stride, int pad,int weights_addr,int output_addr,int nkernels)
{
	Acumulator weights = Acumulator();
	Acumulator input = 	Acumulator();
	int new_addr=input_addr+channels*height*width+1;
	int out_w=((width + 2*pad - kernel_size) / stride) + 1;
	int out_h=((height + 2*pad - kernel_size) / stride) + 1;
	int in_w=width+pad;
	int in_h=height+pad;
	int rewind_kernel=-kernel_size*kernel_size;
	int	line_plus_one = in_w-kernel_size;
	
	int outputs_per_mem = (MEM_SIZE/2)/(kernel_size*kernel_size*channels);
	int out_x=(((MEM_SIZE/2)-kernel_size*kernel_size*channels)/(stride*kernel_size*channels));



		load_data(Versat,0,input_addr,channels*in_h*in_w);
		//calcuclar quantos outputs cabem na MEM_SIZE/2, Minimo Channels*k_size*k_size, fazer varias runs, para calcular as linhas todas
		
		input.add_loop(nkernels,-in_w*(in_h-kernel_size+stride));	
			input.add_loop(out_h,(in_w*stride)-stride*out_w);
				input.add_loop(out_w,-channels*in_w*in_h+stride);
					input.add_loop(channels, in_w*in_h-line_plus_one*kernel_size+rewind_kernel); // Posição final x8 depois dos 2 loops -8+16
						input.add_loop(kernel_size,line_plus_one);
							input.add_loop(kernel_size,1);
								input.loop_settings(0);
								set_IntMem_Read(Versat,0,input);


		
		load_data(Versat,1,weights_addr,kernel_size*kernel_size*nkernels);
		weights.add_loop(nkernels,kernel_size*kernel_size);
			weights.add_loop(out_h,0);
				weights.add_loop(out_w,0);
					weights.add_loop(channels,rewind_kernel);
						weights.add_loop(kernel_size,0);
							weights.add_loop(kernel_size,1);
								weights.loop_settings(0);
							set_IntMem_Read(Versat,1,weights);


		muladd_operation(Versat,sVI[0],sVI[1],0,MULADD_MACC,out_h*out_w*nkernels,kernel_size*kernel_size*channels,MEMP_LAT,0);

			Acumulator write_matrix = Acumulator();
			write_matrix.add_loop(nkernels,0);
			write_matrix.add_loop(out_h*out_w,1);
			write_matrix.loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr,0);
			set_ExtMem_Write(Versat,0,write_matrix);
				write_matrix.add_loop(kernel_size*kernel_size*channels,0);
				set_IntMem_Write(Versat,0,write_matrix,sMULADD[0]);
	return 0;
}
*/
#if nMULADD > (nVI-1)
#if (nVI-1) < nVO
#define nOUTPUTS (nVI-1)
#else
#define nOUTPUTS nVO
#endif
#else
#if nMULADD < nVO
#define nOUTPUTS nMULADD
#else
#define nOUTPUTS nVO
#endif
#endif

int load_segmented_data(CStage* Versat,int index,int addr,int size,int iter,int incr) // size for each MEM
{
	Acumulator load;
	int new_addr=addr;
	load = Acumulator();
	load.add_loop(iter,incr-size);
		load.add_loop(size,1);
		load.loop_settings(0,0,0,new_addr,0);
		set_ExtMem_Read(Versat,index,load);
	return index+nOUTPUTS;
}


int convolutional_layer_xyz(CVersat* Versat,int input_addr,int channels,int height, int width, int kernel_size, int stride, int pad,int weights_addr,int output_addr,int nkernels)
{
	Acumulator weights = Acumulator();
	Acumulator input[nOUTPUTS];
	Acumulator write_matrix[nOUTPUTS];

	int out_w=((width + 2*pad - kernel_size) / stride) + 1;
	int out_h=((height + 2*pad - kernel_size) / stride) + 1;
	int in_w=width+pad;
	int in_h=height+pad;
	int rewind_kernel=-kernel_size*kernel_size;
	int	line_plus_one = in_w-kernel_size;

	int h1=out_h/nOUTPUTS;
	int h2=out_h%nOUTPUTS;
	int w1=out_w/nOUTPUTS;
	int w2=out_w%nOUTPUTS;
	int y= ((MEM_SIZE/2)/(kernel_size*stride*channels)) - (kernel_size/stride) + 1 ; //errada? fazer calculos outra vez, exemplo MEM=64,K=2,S=1,CH=2
	int y3=y/out_w;
	int y4= y3*nOUTPUTS;
	int y2= y*nOUTPUTS;
	int line_r=out_h%y4;
	int line_r_x1=line_r/nOUTPUTS;
	int line_r_x2=line_r%nOUTPUTS;
	int width_r=out_w %y2;
	int width_r_x1=width_r/nOUTPUTS;
	int width_r_x2=width_r%nOUTPUTS;
	int aux	=	0;
	int aux_bool=0;
	int input_addr_new=input_addr;
	int output_addr_new=output_addr;
	Versat->globalClearConf();
	CStage* stage = &(Versat->stage[0]);
	cout << "ENTERED VERSAT CONV\n";
	int extra_iter = 0;
	int num_iter=0;
	cout << "INFO:\n" << "h1="<<to_string(h1)<<"\n"<<"h2="<<to_string(h2)<<"\n";
	if(y4>=out_h)
	{
		printf("CONVOLUTION CASE - FITS EVERY DATA INTO MEM\n");
		if(h2!=0)
			extra_iter= 1;
		num_iter=h1+extra_iter;
		load_data(stage,0,weights_addr,kernel_size*kernel_size*nkernels);
		
		weights.add_loop(nkernels,kernel_size*kernel_size);
			weights.add_loop(num_iter,0);
				weights.add_loop(out_w,0);
					weights.add_loop(channels,rewind_kernel);
						weights.add_loop(kernel_size,0);
							weights.add_loop(kernel_size,1);
								weights.loop_settings(0);
							set_IntMem_Read(stage,0,weights);

		aux=h2;
		input_addr_new=input_addr;
		output_addr_new=output_addr;
		for(int i=0; i<nOUTPUTS; i++) // DATA MEM CONFIG and MULADD
		{
			if(aux>0)
				aux_bool=1;
			else
				aux_bool=0;
			if(h1+aux_bool>0)
			{
				int size_per_channel=in_w*(kernel_size+stride*(num_iter-1));
				// problema! fazer load de varios segmentos diferentes,dependendo do Channel para nOutputs>1, tem de se fazer um salto.
				load_segmented_data(stage,i+1,input_addr_new,size_per_channel,channels,in_w*in_h); 
				//channels*(kernel_size+stride*(h1+aux_bool-1))*in_w

				// h1 and h2 
				input[i]= Acumulator();
				input[i].add_loop(nkernels,-in_w*((num_iter)*stride));
				input[i].add_loop(num_iter,(in_w*stride)-stride*out_w);
					input[i].add_loop(out_w,-channels*size_per_channel+stride);
						input[i].add_loop(channels, size_per_channel-line_plus_one*kernel_size+rewind_kernel);
							input[i].add_loop(kernel_size,line_plus_one);
								input[i].add_loop(kernel_size,1);
									input[i].loop_settings(0);
									set_IntMem_Read(stage,i+1,input[i]);
				aux--;

				muladd_operation(stage,sVI[i+1],sVI[0],i,MULADD_MACC,(num_iter)*out_w*nkernels,
				kernel_size*kernel_size*channels,MEMP_LAT,0);

				write_matrix[i] = Acumulator();
				write_matrix[i].add_loop(nkernels,out_w*(out_h+1)-(num_iter)*out_w);
				write_matrix[i].add_loop((num_iter)*out_w,1); 
				write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
				set_ExtMem_Write(stage,i,write_matrix[i]);
					write_matrix[i] = Acumulator();
					write_matrix[i].add_loop(nkernels,0);
					write_matrix[i].add_loop((num_iter)*out_w,1);
					write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
					write_matrix[i].add_loop(kernel_size*kernel_size*channels,0);
					set_IntMem_Write(stage,i,write_matrix[i],sMULADD[i]);

				input_addr_new+=(in_w*(stride*(h1+aux_bool)))*(DATAPATH_W/8);
				output_addr_new=output_addr_new+((h1+aux_bool)*out_w)*(DATAPATH_W/8);

			}
		}
		cout << "CHECK FOR PREVIOUS RUN\n";
		Versat->versat_debug=1;
		while (Versat->done() == 0)
        ;
		Versat->run();
		cout << "VERSAT RUNNING\n";

	}
	else if(y4>0)
	{
		printf("CONVOLUTION CASE - FITS A LINE IN EVERY DATAPATH\n");
		input_addr_new=input_addr;
		output_addr_new=output_addr;
		load_data(stage,0,weights_addr,kernel_size*kernel_size*nkernels);
		num_iter=y3;
		for(int j=0; j<(out_h/y4); j++)
		{
			weights= Acumulator();
			weights.add_loop(nkernels,kernel_size*kernel_size);
			weights.add_loop(num_iter,0);
				weights.add_loop(out_w,0);
					weights.add_loop(channels,rewind_kernel);
						weights.add_loop(kernel_size,0);
							weights.add_loop(kernel_size,1);
								weights.loop_settings(0);
							set_IntMem_Read(stage,0,weights);
			for(int i=0; i<nOUTPUTS; i++) // DATA MEM CONFIG and MULADD
			{
				if(y3>0)
				{
					int size_per_channel=in_w*(kernel_size+stride*(num_iter-1));
					load_segmented_data(stage,i+1,input_addr_new,size_per_channel,channels,in_w*in_h); //channels*(kernel_size+stride*(h1+aux_bool-1))*in_w
					// y3
				input[i]= Acumulator();
				input[i].add_loop(nkernels,-in_w*((num_iter)*stride));	//-in_w*(in_h-kernel_size+stride)
					input[i].add_loop(num_iter,(in_w*stride)-stride*out_w);
						input[i].add_loop(out_w,-channels*size_per_channel+stride);
							input[i].add_loop(channels, size_per_channel-line_plus_one*kernel_size+rewind_kernel); // Posição final x8 depois dos 2 loops -8+16
								input[i].add_loop(kernel_size,line_plus_one);
									input[i].add_loop(kernel_size,1);
									input[i].loop_settings(0);
									set_IntMem_Read(stage,i+1,input[i]);

					muladd_operation(stage,sVI[i+1],sVI[0],i,MULADD_MACC,num_iter*out_w*nkernels,kernel_size*kernel_size*channels,MEMP_LAT,0);

					write_matrix[i] = Acumulator();
					write_matrix[i].add_loop(nkernels,out_w*(out_h+1)-(num_iter)*out_w );
					write_matrix[i].add_loop((num_iter)*out_w,1); // here, why is it not writting correctly<>
					write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
					set_ExtMem_Write(stage,i,write_matrix[i]);
					write_matrix[i] = Acumulator();
					write_matrix[i].add_loop(nkernels,0); // CHECK HERE LATER
					write_matrix[i].add_loop((num_iter)*out_w,1);
					write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
					write_matrix[i].add_loop(kernel_size*kernel_size*channels,0);
					set_IntMem_Write(stage,i,write_matrix[i],sMULADD[i]);



					input_addr_new+=(in_w*(stride*(num_iter)))*(DATAPATH_W/8);
					output_addr_new=output_addr_new+((num_iter)*out_w)*(DATAPATH_W/8);

				}
			}
			cout << "CHECK FOR PREVIOUS RUN\n";
			Versat->versat_debug=1;
			while (Versat->done() == 0)
        		;
			Versat->run();
			cout << "VERSAT RUNNING\n";
		}
		if( line_r != 0 ) // last run
		{
			aux=line_r_x2;
			if(line_r_x2!=0)
				extra_iter= 1;
			num_iter=line_r_x1+extra_iter;
			for(int i=0; i<nOUTPUTS; i++) // DATA MEM CONFIG and MULADD
			{
				if(aux>0)
					aux_bool=1;
				else
					aux_bool=0;
				if(line_r_x1+aux_bool>0)
				{
					int size_per_channel=in_w*(kernel_size+stride*(num_iter-1));
					// problema! fazer load de varios segmentos diferentes,dependendo do Channel para nOutputs>1, tem de se fazer um salto.
					load_segmented_data(stage,i+1,input_addr_new,size_per_channel,channels,in_w*in_h); //channels*(kernel_size+stride*(h1+aux_bool-1))*in_w

					// h1 and h2 
					input[i]= Acumulator();
					input[i].add_loop(nkernels,-in_w*((num_iter)*stride));	//-in_w*(in_h-kernel_size+stride)
					input[i].add_loop(num_iter,(in_w*stride)-stride*out_w);
						input[i].add_loop(out_w,-channels*size_per_channel+stride);
							input[i].add_loop(channels, size_per_channel-line_plus_one*kernel_size+rewind_kernel); // Posição final x8 depois dos 2 loops -8+16
								input[i].add_loop(kernel_size,line_plus_one);
									input[i].add_loop(kernel_size,1);
										input[i].loop_settings(0);
										set_IntMem_Read(stage,i+1,input[i]);
					aux--;

					muladd_operation(stage,sVI[i+1],sVI[0],i,MULADD_MACC,(num_iter)*out_w*nkernels,kernel_size*kernel_size*channels,MEMP_LAT,0);

					write_matrix[i] = Acumulator();
					write_matrix[i].add_loop(nkernels,out_w*(out_h+1)-(num_iter)*out_w);
					write_matrix[i].add_loop((num_iter)*out_w,1); // here, why is it not writting correctly<>
					write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
					set_ExtMem_Write(stage,i,write_matrix[i]);
						write_matrix[i] = Acumulator();
						write_matrix[i].add_loop(nkernels,0); // CHECK HERE LATER
						write_matrix[i].add_loop((num_iter)*out_w,1);
						write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
						write_matrix[i].add_loop(kernel_size*kernel_size*channels,0);
						set_IntMem_Write(stage,i,write_matrix[i],sMULADD[i]);

					input_addr_new+=(in_w*(stride*(line_r_x1+aux_bool)))*(DATAPATH_W/8);
					output_addr_new=output_addr_new+((line_r_x1+aux_bool)*out_w)*(DATAPATH_W/8);

				}
			}
			cout << "CHECK FOR PREVIOUS RUN\n";
			Versat->versat_debug=1;
			while (Versat->done() == 0)
        		;
			Versat->run();
			cout << "VERSAT RUNNING\n";
		}
	}
	else if(y2>=out_w)
	{
		printf("CONVOLUTION CASE - FITS A LINE IN EVERY DATAPATH\n");
		input_addr_new=input_addr;
		output_addr_new=output_addr;
		load_data(stage,0,weights_addr,kernel_size*kernel_size*nkernels);

		for(int j=0; j<out_h; j++)
		{
			weights = Acumulator();
			//weights.add_loop(nkernels,kernel_size*kernel_size);
			//weights.add_loop(out_h,0);
			weights.add_loop(nkernels,kernel_size*kernel_size);
				weights.add_loop(w1+1,0);
					weights.add_loop(channels,rewind_kernel);
						weights.add_loop(kernel_size,0);
							weights.add_loop(kernel_size,1);
								weights.loop_settings(0);
							set_IntMem_Read(stage,0,weights);
		
			aux=w2;
			for(int i=0; i<nOUTPUTS; i++)
			{
				//w1 and w2
				if(aux>0)
				aux_bool=1;
				else
				aux_bool=0;
				if(w1+aux_bool>0)
				{
					load_data(stage,i+1,input_addr_new,channels*(kernel_size+stride*(w1+aux_bool-1)));
					// h1 and h2 
					input[i]= Acumulator();
					//input[i].add_loop(nkernels,-in_w*(in_h-kernel_size+stride));	
					//input[i].add_loop(out_h,(in_w*stride)-stride*out_w);
					input[i].add_loop(nkernels,-in_w*(in_h-kernel_size+stride)); // check to see if OK
						input[i].add_loop(w1+aux_bool,-channels*in_w*in_h+stride);
							input[i].add_loop(channels, in_w*in_h-line_plus_one*kernel_size+rewind_kernel); // Posição final x8 depois dos 2 loops -8+16
								input[i].add_loop(kernel_size,line_plus_one);
									input[i].add_loop(kernel_size,1);
										input[i].loop_settings(0);
										set_IntMem_Read(stage,0,input[i]);
					aux--;

					muladd_operation(stage,sVI[i+1],sVI[0],i,MULADD_MACC,(w1+aux_bool)*nkernels,kernel_size*kernel_size*channels,MEMP_LAT,0);

					write_matrix[i] = Acumulator();
					write_matrix[i].add_loop(nkernels,-(w1+aux_bool)+out_w*out_h);
					write_matrix[i].add_loop(w1+aux_bool,1);
					write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
					set_ExtMem_Write(stage,0,write_matrix[i]);
					// need to duplicate the code because in intMem it will write sequentially, in output ADDR it will write correctly
						write_matrix[i] = Acumulator();
						write_matrix[i].add_loop(nkernels,0);
						write_matrix[i].add_loop(w1+aux_bool,1);
						write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
						write_matrix[i].add_loop(kernel_size*kernel_size*channels,0);
						set_IntMem_Write(stage,0,write_matrix[i],sMULADD[0]);


					input_addr_new+=channels*(kernel_size+stride*(w1+aux_bool-1));
					output_addr_new+=(w1+aux_bool);
				}
			}
		//run
		}
	}
	else if(y2>0)
	{
		load_data(stage,0,weights_addr,kernel_size*kernel_size*nkernels);
		input_addr_new=input_addr;
		output_addr_new=output_addr;
		weights = Acumulator();
			weights.add_loop(nkernels,kernel_size*kernel_size);
				weights.add_loop(w1+1,0);
					weights.add_loop(channels,rewind_kernel);
						weights.add_loop(kernel_size,0);
							weights.add_loop(kernel_size,1);
								weights.loop_settings(0);
							set_IntMem_Read(stage,0,weights);
		for(int l=0; l<out_h; l++)
		{
			for(int j=0; j<out_w/y2; j++)
			{
				
				for(int i=0; i<nOUTPUTS; i++)
				{
					//y
					load_data(stage,i+1,input_addr_new,channels*(kernel_size+stride*(y-1)));
					// h1 and h2 
					input[i]= Acumulator();
					//input[i].add_loop(nkernels,-in_w*(in_h-kernel_size+stride));	
					//input[i].add_loop(out_h,(in_w*stride)-stride*out_w);
					input[i].add_loop(nkernels,-in_w*(in_h-kernel_size+stride)); // check to see if OK
						input[i].add_loop(y,-channels*in_w*in_h+stride);
							input[i].add_loop(channels, in_w*in_h-line_plus_one*kernel_size+rewind_kernel); // Posição final x8 depois dos 2 loops -8+16
								input[i].add_loop(kernel_size,line_plus_one);
									input[i].add_loop(kernel_size,1);
										input[i].loop_settings(0);
										set_IntMem_Read(stage,0,input[i]);
					aux--;

					muladd_operation(stage,sVI[i+1],sVI[0],i,MULADD_MACC,y*nkernels,kernel_size*kernel_size*channels,MEMP_LAT,0);

					write_matrix[i] = Acumulator();
					write_matrix[i].add_loop(nkernels,-y+out_w*out_h);
					write_matrix[i].add_loop(y,1);
					write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
					set_ExtMem_Write(stage,0,write_matrix[i]);
					// need to duplicate the code because in intMem it will write sequentially, in output ADDR it will write correctly
						write_matrix[i] = Acumulator();
						write_matrix[i].add_loop(nkernels,0);
						write_matrix[i].add_loop(y,1);
						write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
						write_matrix[i].add_loop(kernel_size*kernel_size*channels,0);
						set_IntMem_Write(stage,0,write_matrix[i],sMULADD[0]);


					input_addr_new+=channels*(kernel_size+stride*(y-1));
					output_addr_new+=y;
				}
				//run
			}
			if(width_r != 0)
			{
				// width x1 and x2
				//y
				//r1 and r2
				aux=width_r_x2;
				if(aux>0)
				aux_bool=1;
				else
				aux_bool=0;
				for(int i=0; i<nOUTPUTS; i++)
				{
					load_data(stage,i+1,input_addr_new,channels*(kernel_size+stride*(width_r_x1+aux_bool-1)));
					// h1 and h2 
					input[i]= Acumulator();
					//input[i].add_loop(nkernels,-in_w*(in_h-kernel_size+stride));	
					//input[i].add_loop(out_h,(in_w*stride)-stride*out_w);
					input[i].add_loop(nkernels,-in_w*(in_h-kernel_size+stride)); // check to see if OK
						input[i].add_loop(width_r_x1+aux_bool,-channels*in_w*in_h+stride);
							input[i].add_loop(channels, in_w*in_h-line_plus_one*kernel_size+rewind_kernel); // Posição final x8 depois dos 2 loops -8+16
								input[i].add_loop(kernel_size,line_plus_one);
									input[i].add_loop(kernel_size,1);
										input[i].loop_settings(0);
										set_IntMem_Read(stage,0,input[i]);
					aux--;

					muladd_operation(stage,sVI[i+1],sVI[0],i,MULADD_MACC,y*nkernels,kernel_size*kernel_size*channels,MEMP_LAT,0);

					write_matrix[i] = Acumulator();
					write_matrix[i].add_loop(nkernels,-(width_r_x1+aux_bool)+out_w*out_h);
					write_matrix[i].add_loop(y,1);
					write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
					set_ExtMem_Write(stage,0,write_matrix[i]);
					// need to duplicate the code because in intMem it will write sequentially, in output ADDR it will write correctly
						write_matrix[i] = Acumulator();
						write_matrix[i].add_loop(nkernels,0);
						write_matrix[i].add_loop(width_r_x1+aux_bool,1);
						write_matrix[i].loop_settings(0,0,MEMP_LAT+MULADD_LAT,output_addr_new,0);
						write_matrix[i].add_loop(kernel_size*kernel_size*channels,0);
						set_IntMem_Write(stage,0,write_matrix[i],sMULADD[0]);


					input_addr_new+=channels*(kernel_size+stride*(width_r_x1+aux_bool-1));
					output_addr_new+=width_r_x1+aux_bool;
				}
			}	
		}
	
	}
	else{
		printf("Invalid Convolution setup\n");
		exit(1);
	}
	return 0;
}