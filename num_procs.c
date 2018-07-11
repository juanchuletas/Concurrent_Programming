#include <stdio.h>
#include <omp.h>


int main ()
{
	int num;
	num  = omp_get_num_procs();
	#pragma omp parallel
	{
		printf("hay %d procesadores disponibles\n",num);
	}

	return 0;
}
