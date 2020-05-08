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


void deallocate(sem_t* chopstick[], char left[], char right[]){

	sem_close(chopstick[0]);
	sem_close(chopstick[1]);

	sem_unlink(left);
	sem_unlink(right);

	sem_destroy(chopstick[0]);
	sem_destroy(chopstick[1]);

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
	
	char chopstick1[50];
	char chopstick2[50];

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
			 fprintf(stderr, "Philosopher #%d completed cycle runs.\n",position, cycles);
		 }
		 
	 }
		deallocate(chopstick1, left, right);
		deallocate(chopstick2, left, right);
		 return EXIT_SUCCESS;
}

