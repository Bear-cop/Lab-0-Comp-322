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
static char* SIGS[27] = {"HUP", "INT", "QUIT", "ILL", "TRAP",
                         "ABRT", "BUS", "FPE", "KILL", "USR1",
                         "SEGV", "USR2", "PIPE", "ALRM", "TERM", 
                         "STKFLT", "CHLD", "CONT", "STOP", "TSTP",
                         "TTIN", "TTOUT", "URG", "XCPU", "XFSZ",
                         "VTALRM", "PROF", "WINCH"};


void sigCatch(int sig){
  time(&sec);

  if(n == 15) {
        term++;
    }
  else{
        term = 0;
    }
if(n == SIGUSR1) {
        fprintf(stdout, "SIGUSR1 caught at %ld\n", sec);
	    
    } else if(n == SIGUSR2) {
        fprintf(stdout, "SIGUSR2 caught at %ld\n", sec);
	    
    }else {
        
        fprintf(stdout, "SIG%s caught at %ld\n", SIGS[n-1], sec);
    }
    count++;
  
}

int main(int argc, char **argv){
pid_t pid;
for(int i = 1; i < argc; i++) {
        for(int j = 0; j < 27; j++) {
  
          if(strcmp(argv[i], "USR1")){
            
          }
        }
 }
  
  while(term < 3){
    pause();
  }

  
  retrun 0;
  

}
