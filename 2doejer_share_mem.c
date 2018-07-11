#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>


int main ()
{
	int *shm;
	int ide_mem_com;
	int hijo,status,total,parcial=0;;
	int i,N=100;
	int x[100];
	ide_mem_com=shmget(3456,2,IPC_CREAT|0666);
	shm=shmat(ide_mem_com,NULL,0);

	*shm=0;

	for(i=0;i<N;i++)
	{
		x[i]=i+1;
	}

	int tid=fork();
	if(tid!=0)
	{
		for(i=0;i<N/2;i++)
		{
			parcial = parcial + x[i];
		}
		printf("Soy el padre %d\n",getpid());
		hijo=wait(&status);
		total = parcial + *shm;
		printf("El valor total es %d\n",total);
	 	//sleep(1);	
	}
	else
	{
		//sleep(10);
	//	*shm=1;
		for(i=N/2;i<N;i++)
		{
			parcial = parcial +x[i];
		}
		printf("Soy el hijo %d\n",getpid());
		*shm=parcial;
		
	}
	return 0;

}
