#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main ()
{     
        int tid;   
    
	tid=fork();//crea un proceso hijo

 	if(tid==0)
	{
		execl("./hola2", "hola2", (char *)0);
		printf("soy %d mi tid es %d\n",getpid(),tid);
	}

	sleep(6);
 	

	return 0;
}
