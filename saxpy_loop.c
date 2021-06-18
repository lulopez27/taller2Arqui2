/*SAXPY loop*/
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
static long array_size = 100000; //100000 1000 50
void saxpy_cpu(float a, float *x, float *y, float *z);
void rand_array();
int main (){
	  
	double start_time, run_time;

	float x[array_size],y[array_size],z[array_size];
	rand_array(x);
	rand_array(y);
	float a = (float)rand()/(float)(1+rand());
	int procnum = 8;
	for (int i=1;i<=procnum*2;i++){
		omp_set_num_threads(i);
		start_time = omp_get_wtime();
		int iam,nt;
#pragma omp parallel default(shared) private(iam,nt)
{
	iam = omp_get_thread_num();
	nt = omp_get_num_threads();
#pragma omp single
	printf("threads = %d ",omp_get_num_threads());
#pragma omp for reduction(+:z)
	for (int i = iam; i < array_size; i = i + nt)
		z[i] = a * x[i] + y[i];
	}
	run_time = omp_get_wtime() - start_time;
	printf("RunTime = %f, with array size of = %ld \n",run_time,array_size);
}
}

void rand_array(float* array){
   long i;
   for (i = 0; i < array_size; i++) {
      array[i] = (float)rand()/(float)(i+1);
   }
}