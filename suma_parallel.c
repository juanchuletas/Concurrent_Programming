#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define N 100
#define HILOS 4


void llena_arreglo(int Array[])

{
	int i;
	
	for (i=0;i<N; i++)
	{
		Array[i] = i+1;
		
	}
}

int main ()
{
	int Array[N],suma_total=0;

	
	
	int tid, nthreads;
	llena_arreglo(Array);
	omp_set_num_threads(HILOS);
	#pragma omp parallel private (tid) 
	{
		int j,ini,fin,suma=0,parcial = 0;

		tid = omp_get_thread_num();

		ini = (N/HILOS)*tid;
		fin  = (N/HILOS)*(tid+1);
		
		for(j=ini;j<fin;j++)
		{
			parcial = parcial + Array[j];
		}
		
		#pragma omp critical
			suma_total = suma_total + parcial;
	}
		
	printf("Suma total es %d\n",suma_total);
	return 0;	
}
