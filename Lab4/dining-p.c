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

#define chopstick1
#define chopstick2
int end = 0;
int ph;

void eat(int num){
	fprintf(stdout, "Philosopher #%d is eating\n", num);
  usleep(rand());
}


void think(int num){
	fprintf(stdout, "Philosopher #%d is thinking\n", num);
	usleep(rand());
}


void deallocate(sem_t* right, sem_t* left){

	sem_close(right);
	sem_close(left);

	sem_unlink(chopstick1);
	sem_unlink(chopstick2);

	sem_destroy(right);
	sem_destroy(left);

}

void signalHandler(int sig){
//reregister signal handler
	signal(SIGTERM, signalHandler);
	printf("SIGTERM (%d) received...\n", sig);
	end = 1;
}


int main(int argc, char** argv){
  if(argc < 3){
    printf("need more arguments", argc);
    return EXIT_FAILURE;
  }
	int seats = atoi(argv[1]);
  	int position = atoi(argv[2]);
	int cycles;
	sem_t* left;
	sem_t* right;
	char place[50];

	strcpy(left, "/");
	strcat(left, argv[2]);

	strcpy(right, "/");
	strcat(right, place);
	
	 if(seats < position) {
          	  printf("Error: not enough seats\n");
         }else{
		cycles = 0;
		signal(SIGTERM, signalHandler);
		right = sem_open(chopstick1, O_CREAT,0660, 1);
		left = sem_open(chopstick2, O_CREAT,0660, 1);
			do{
		//wait for right & left semaphore
			sem_wait(right);
			sem_wait(left);
			eat(position);
		//show left & right are available
			sem_post(right);
			sem_post(left);
			think(position);
			cycles++;
			}while(end);
		 if(end !=1 ){
			 fprintf(stdout, "Philosopher #%d completed cycle runs.\n",position, cycles);
		 }
		 deallocate(left,right);
	 }
	
	else{
		fprintf(stderr,"Enter more seats and positions");
	}
		 return EXIT_SUCCESS;
}

