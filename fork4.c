#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/time.h>

int main()
{
	int pid;
	struct timeval t1, t2;
	double et;
	gettimeofday(&t1, NULL);
	pid=fork();
	if(pid<0)
	{
		printf("Error: Fork Failed!!!");
		exit(1);
	}
	else if (pid==0)
	{
		printf("In Child process address space\n");
		execlp("","ls",NULL);
	}
	else
	{
		printf("In Parent process address space\n");
		wait(NULL);
		printf("Child process completed\n");
		gettimeofday(&t2, NULL);
		et= (t2.tv_sec-t1.tv_sec) * 1000.0;
		et+= (t2.tv_usec-t1.tv_usec) / 1000.0;
		fprintf(stderr, "Elapsed Time= %5.3fms \n", et);
		exit(0);
	}	
}

