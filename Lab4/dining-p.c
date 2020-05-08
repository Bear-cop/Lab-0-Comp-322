#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#define CHOPSTICK1
#define CHOPSTICK2
sem_t* left;
sem_t* right;
int end = 0;

void eat(int num){
	fprintf(stdout, "Philosopher #%d is eating\n", num);
  usleep(rand());
}
void think(int num){
	fprintf(stdout, "Philosopher #%d is thinking\n", num);
	usleep(rand());
}


//handles the signal and sets end to 1
void signalHandler(int sig){
//reregister signal handler
	signal(SIGTERM, signalHandler);
	printf("SIGTERM (%d) received...\n", sig);
	end = 1;
}

//destroys all semaphores
void destroy(){
	sem_close(right);
	sem_close(left);
	sem_unlink(CHOPSTICK1);
	sem_unlink(CHOPSTICK2);
	sem_destroy(right);
	sem_destroy(left);
}

//signal is sent, checks arguments, and 
//manuvers semaphore to become availabe for use
//to complete the philosopher cycles
int main(int argc, char** argv){
	if(argc == 3) {
      	  int seats = atoi(argv[1]);
      	  int position = atoi(argv[2]);
	  int cycles;
        if(seats < position) {
            printf("Error: not enough seats\n");
		return EXIT_FAILURE;
		
        }else {
            cycles = 0;
            signal(SIGTERM, signalHandler);
            right = sem_open(CHOPSTICK1, O_CREAT, 0660, 1);
            left = sem_open(CHOPSTICK2, O_CREAT, 0660, 1);
            do {
                sem_wait(right);
                sem_wait(left);
                eat(position);
                sem_post(right);
                sem_post(left);
                think(position);
                cycles++;
            }
            while(end); 
            //if done
            if(end != 1) {
                //print message to stderr
                fprintf(stderr, "Philosopher #%d completed %d cycles.\n", position, cycles);
            }
            destroy();
        }
	}
    //otherwise
    else {
        //print message to stderr
		fprintf(stdout, "Error: Please give number of seats and position.\n");
    }
    return EXIT_SUCCESS;
}
