//Ricardo Carrillo 
//05/09/2020
//Lab 6: Wack A Mole
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <string.h>



void signalHandler(int sig){
  signal(sig, signalHandler);
  pid_t mole;
  if(!(mole == 0)){
   return EXIT_FAILURE; 
  }
  
  if(sig == SIGTERM){
  return EXIT_SUCCESS;
  }
  
}


int main(int argc, char **argv){
  pid_t mole;
  int devnull;
  struct rlimit rlim;
  umask(0);
  mole = fork();
  
  if(mole > 0){
   return EXIT_SUCCESS; 
  }
  else if(mole == 0){
    
    
    
  
  return EXIT_SUCCESS;
  }
  
  getrlimit(RLIMIT_NOFILE, &rlim);
  
	if(rlim.rlim_max == RLIM_INFINITY){
	rlim.rlim_max = 1024;
	}
  
	for(unsigned int i = 0; i < rlim.rlim_max; i++){
	close(i);
	}
	
  devnull = open("/dev/null", O_RWDR);
	dup(devnull, 0);
  	dup(devnull, 1);
	dup(devnull, 2);

	while(1){
		pause();
	}
	
  return 0;
}
