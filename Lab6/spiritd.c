//Ricardo Carrillo 
//05/09/2020
//Lab 6: Wack A Mole
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/resource.h>
#include <fcntl.h>
#include <signal.h>
#include <time.h>
#include <syslog.h>
#include <limits.h> 
#include <string.h>
#include <sys/wait.h>

void signalHandler();
char* mDirect;

//This method Handles signal and kills signal when 
//specific signals and processes are invoked
//it also creates mole processes
void signalHandler(int sig){
  signal(sig, signalHandler);
  char *mole;
  pid_t ppid;
  pid_t cpid;
  int random;	
	
  if(!(ppid == 0)){
   kill(ppid, SIGKILL);
  }
	
  if(sig == SIGTERM){
  kill(getpid(), SIGKILL);
  }
  random = (rand()%2);
  char args[3];		
  if(random == 1){
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

//in the main method it creates pathing so 
// we know where lab6.log is created at our home
//also gives Dameon process.
//p.s it opens and closes all file descriptors and hands
//them off to devnull
int main(){
  pid_t mole;
  char hDirect [PATH_MAX];
  int devnull;
  struct rlimit rlim;
 	
	
  mole = fork();
  
  if(mole > 0){
	  
   exit(0); 
	
	  
  }else if(mole == 0){
      umask(0);  
  	getcwd(mDirect, sizeof(mDirect));
  	strcat(mDirect, "/mole");
      setsid(); 
      chdir("/");
  	printf("Daemon pid:", getpid());
  	strcat(hDirect, getenv("HOME"));
  	strcat(hDirect, "/lab6.log");
	if((open(hDirect, O_CREAT, 0770)) == -1){  
		printf("ERROR cant reach Home Directory");
  		return EXIT_FAILURE;
	}
  }
  
  getrlimit(RLIMIT_NOFILE, &rlim);
  
	if(rlim.rlim_max == RLIM_INFINITY){
	rlim.rlim_max = 1024;
	}
  
	for(unsigned int i = 0; i < rlim.rlim_max; i++){
	close(i);
	}
	
  devnull = open("/dev/null", O_RDWR);
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
