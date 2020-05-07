//Ricardo Carrillo 
//LAB 3 - Catcher
//05/07/2020

#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h> 

time_t sec;
static int term = 0;
static int count = 0;
//all types of signals that can be caught
static char* SIGS[27] = {"HUP", "INT", "QUIT", "ILL", "TRAP",
                         "ABRT", "BUS", "FPE", "KILL", "USR1",
                         "SEGV", "USR2", "PIPE", "ALRM", "TERM", 
                         "STKFLT", "CHLD", "CONT", "STOP", "TSTP",
                         "TTIN", "TTOUT", "URG", "XCPU", "XFSZ",
                         "VTALRM", "PROF", "WINCH"};


//catches signal at whatever time
void sigCatch(int sig){
  time(&sec);

  if(sig == 15) {
        term++;
    }
  else{
        term = 0;
    }
if(sig == SIGUSR1) {
        fprintf(stdout, "SIGUSR1 caught at %ld\n", sec);
	    
    } else if(sig == SIGUSR2) {
        fprintf(stdout, "SIGUSR2 caught at %ld\n", sec);
	    
    }else {
        
        fprintf(stdout, "SIG%s caught at %ld\n", SIGS[sig - 1], sec);
    }
    count++;
  
}

//handles the signal and displays it to user
int main(int argc, char **argv){
	
	//gets pid # and print it
	pid_t pid;
	fprintf(stderr, "Catcher $$: = %d\n", getpid());
	
for(int i = 1; i < argc; i++) {
        for(int j = 0; j < 27; j++) {
  		//checks for USR1
          if(strcmp(argv[i], "USR1")){
           signal(SIGUSR1, sigCatch);
            }
		//checks for USR2
            if(strcmp(argv[i], "USR2")) {
		signal(SIGUSR2, sigCatch);
	    }else {
		    
		signal(j+1, sigCatch); 
		    
          }//end else
		
        }//end for j
	
 }//end for i
  
  	while(term < 3){
    	pause();
  	}//end while
	
	fprintf(stderr, "Catcher: total signal count = %d\n", count);
  
  return 0;
  

}//end main
