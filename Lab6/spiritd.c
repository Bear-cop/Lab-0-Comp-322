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

char* mDirect;

void signalHandler(int sig){
  signal(sig, signalHandler);
  char *mole;
  pid_t ppid;
  pid_t cpid;
  int rand;	
  if(!(ppid == 0)){
   return EXIT_FAILURE; 
  }
  if(sig == SIGTERM){
  return EXIT_SUCCESS;
  }
  rand = rand()%2;
  char args[3];		
  if(rand == 1){
	  mole = "mole1"; 
	  cpid = fork();
	  if(sig == SIGUSR1){
		if(cpid == 0){
			args[0] = mDirect;
			args[1] = mole;
			args[2] = NULL;
			execve(args[0], args, NULL);
		}
	  }
  }else {
	mole = "mole2";
	  cpid = fork();
	  if(sig == SIGUSR2){
	  	if(cpid == 0){
			args[0] = mDirect;
			args[1] = mole;
			args[2] = NULL;
			execve(args[0], args, NULL);
		}
	  }
  }
	return 0;
}


int main(){
  pid_t mole;
  char hDirect [PATH_MAX], buffer[4096];
  int devnull;
  struct rlimit rlim;
 	
	
  mole = fork();
  
  if(mole > 0){
   return EXIT_SUCCESS; 
  }
  else if(mole == 0){
  umask(0);  
  getsid();
  getcwd(mDirect, sizeof(mDirect));
  strcat(mDirect, "/mole");
  chdir("/");
    
  
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
	dup2(devnull, 0);
  	dup2(devnull, 1);
	dup2(devnull, 2);

	while(1){
		pause();
	}
	
	signal(SIGTERM, signalHandler);
	signal(SIGUSR1, signalHandler);
	signal(SIGUSR2, signalHandler);	
}
