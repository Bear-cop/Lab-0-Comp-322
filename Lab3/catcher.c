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
  
  
}

int main(int argc, char **argv){
pid_t pid;


  
  retrun 0;
  

}
