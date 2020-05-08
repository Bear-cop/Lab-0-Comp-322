#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <signal.h>



int ph;

void eat(){
	srand(time(0));
	int random = rand() % (1000000 + 1 - 0) + 0;
	usleep(random);
	printf("Philosopher %d is eating.\n", ph);
}

void thinking(){
	srand(time(0));
	int random = rand() % (1000000 + 1 - 0) + 0;
	usleep(random);
	printf("Philosopher %d is thinking.\n", ph);
}



int main(int argc, char** argv){
  if(argc < 3){
    printf("need more arguments", argc);
    return EXIT_FAILURE;
  }
  
  
}

