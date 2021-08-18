#include <pthread.h>
#include <stdio.h>
#include <sys/time.h>
void *PrintHello(void*id)
{
	printf("Hello from Thread %p\n", id);
}
void main ()
{
	struct timeval t1, t2; double et;
	gettimeofday(&t1, NULL); pthread_t thread0, thread1;
	pthread_create(&thread0, NULL, PrintHello, (void*)0); 
	pthread_join(thread0, NULL);
	gettimeofday(&t2, NULL);
	et= (t2.tv_sec-t1.tv_sec)*1000.0;
	et+= (t2.tv_usec-t1.tv_usec)/1000.0;
	fprintf(stderr, "Elapsed Time= %5.3fms \n", et);
}
