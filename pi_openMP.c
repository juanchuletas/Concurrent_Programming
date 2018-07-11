#include <stdio.h>
#include <math.h>

#define  n_steps 1000000


int main()
{
	int i;
	double step,pi,x,sum;


	step = 1.0/(double)n_steps;
	sum = 0.0;

#pragma omp parallel for \
	private(x) reduction(+:sum)
	

	for(i=0;i<n_steps;i++)
	{
		x = (i+0.5)*step;
		sum = sum + 4.0/(1.0 + x*x);

	}

	pi = step*sum;
	printf("Pi =%lf\n",pi);
}
