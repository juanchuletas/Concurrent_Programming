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
	int hijo,status;
	int i,N=5;
	ide_mem_com=shmget(3456,2,IPC_CREAT|0666);
	shm=shmat(ide_mem_com,NULL,0);

	*shm=0;

	int tid=fork();
	if(tid!=0)
	{
		for(i=0;i<N;i++)
		{
			*shm=(*shm)+1;
		}
		printf("Soy el padre %d\n",getpid());
		hijo=wait(&status);
		printf("El valor de la variable compartida es %d\n",*shm);
		//*shm= *shm+1;
	 	//sleep(1);	
	}
	else
	{
		//sleep(10);
	//	*shm=1;
		for(i=0;i<N;i++)
		{
			*shm= (*shm) + 1;
		}
		printf("Soy el hijo %d\n",getpid());
		printf("El valor de la variable compartida es %d\n",*shm);
		
	}
	return 0;

}
