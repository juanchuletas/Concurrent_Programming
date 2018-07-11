#include <stdio.h>
#include <omp.h>


int main ()
{
#pragma omp parallel
	{
		printf("hola mundo\n");
	}
	
	return 0;
}
