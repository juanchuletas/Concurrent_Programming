#include <mpi.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    int tid;

    MPI_Comm_rank(MPI_COMM_WORLD,&tid);
    
    sleep(tid*5);

    printf("soy el proceso %d llego a la barrera\n",tid);
   
    MPI_Barrier(MPI_COMM_WORLD);

    printf("soy el proceso %d salgo de la barrera\n",tid);

    MPI_Finalize();
}

