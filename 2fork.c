#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main ()
{
	int i,n=3,tid;

	for(i=0; i<n; i++)
	{
		tid = fork();
		if(tid==0)
		{
			break;
		}

	printf("i=%di\n",i);

	}

	sleep(15);


	return 0;
}


