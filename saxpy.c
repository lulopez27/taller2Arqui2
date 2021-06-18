/*SAXPY*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
static long array_size = 50; //100000 1000 50
void saxpy_cpu(float a, float *x, float *y, float *z);
void rand_array();
int main (){
	  
   double start_time, run_time;

   float x[array_size],y[array_size],z[array_size];
   rand_array(x);
   rand_array(y);
   float a = (float)rand()/(float)(1+rand());
   start_time = omp_get_wtime();
   saxpy_cpu(a,x,y,z);
   run_time = omp_get_wtime() - start_time;
   printf("RunTime = %f, with array size of = %ld \n",run_time,array_size);
}



void saxpy_cpu(float a, float *x, float *y, float *z){
	for (int i = 0; i < array_size; ++i)
		z[i] = a * x[i] + y[i];
}

void rand_array(float* array){
   long i;
   for (i = 0; i < array_size; i++) {
      array[i] = (float)rand()/(float)(i+1);
   }
}