#include <mpi.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(NULL, NULL);
    int tid;
    int dato[2];
    int x[10];
    dato[0]=-1;
    dato[1]=-1;
    int y;



   
    MPI_Comm_rank(MPI_COMM_WORLD,&tid);

 
    printf("soy el proceso %d mis datos ANTES son %d, %d\n",tid,dato[0],dato[1]);

    

    
    if(tid==0)
    {  dato[0]=1;
       dato[1]=2;

       for(int i=0;i<10;i++)
         x[i]=i+1;
    }

    MPI_Bcast(dato,2,MPI_INT,0,MPI_COMM_WORLD);

    printf("soy el proceso %d mis datos DESPUES son %d, %d\n",tid,dato[0],dato[1]);




    MPI_Scatter(x,2,MPI_INT,dato,2,MPI_INT,0,MPI_COMM_WORLD);


    printf("soy el proceso %d mis datos son es %d %d\n",tid,dato[0],dato[1]);


    MPI_Finalize();
}

