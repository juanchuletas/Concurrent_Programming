#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#define NUM_THREADS	4
#define TAM 100
int z[TAM];
int total = 0;
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;

void* suma(void *threadid)
{
   int taskid,i;
   int inicio,fin;
   int parcial;

   taskid = (intptr_t) threadid;

   inicio = TAM/NUM_THREADS*taskid;
   fin = (TAM/NUM_THREADS)*(taskid+1);

   for(i=inicio;i<fin;i++)
   {
   	   pthread_mutex_lock(&m1);
	   total = total + z[i];
           pthread_mutex_unlock(&m1);
   }

   printf("Soy el hilo %d mi parcial es %d\n",taskid,total);

   //pthread_mutex_lock(&m1);
   //total = total + parcial; //REGION CRITICA
   //pthread_mutex_unlock(&m1);

   pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
	pthread_t threads[NUM_THREADS];
	long taskids[NUM_THREADS];
	int rc, t,i;


	for(i=0;i<TAM;i++)
	{
		z[i] = i+1;
	}

	for(t=0;t<NUM_THREADS;t++) 
	{
  		taskids[t] = t;
  		rc = pthread_create(&threads[t], NULL, suma, (void *) taskids[t]);
	}


	for(t=0;t<NUM_THREADS;t++) 
	{
		pthread_join(threads[t],NULL);
	}
	printf("El total es %d\n",total);
}

