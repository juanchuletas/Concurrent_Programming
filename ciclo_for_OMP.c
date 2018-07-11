#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 20
#define HILOS 2

int main ()
{
	
	int nthreads,tid;
	omp_set_num_threads(HILOS);
	#pragma omp parallel
	{
		int i;
		#pragma omp for
			for (i=0;i<N;i++)
			{
				printf("i=%d, soy el hilo %d\n",i,omp_get_thread_num());
			}
	}
	return 0;	
}
