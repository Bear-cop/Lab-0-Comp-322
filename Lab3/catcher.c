#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <fcntl.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>
#include <time.h> 

static int count = 0;
static char* SIGS[27] = {"HUP", "INT", "QUIT", "ILL", "TRAP",
                         "ABRT", "BUS", "FPE", "KILL", "USR1",
                         "SEGV", "USR2", "PIPE", "ALRM", "TERM", 
                         "STKFLT", "CHLD", "CONT", "STOP", "TSTP",
                         "TTIN", "TTOUT", "URG", "XCPU", "XFSZ",
                         "VTALRM", "PROF", "WINCH"};

void sigHandler(int sig){
  
  
  
}


void sigCatch(int sig){
  
  
  
}

int main(int argc, char **argv){
pid_t pid;

time_t sec;
time(&sec);

  
  retrun 0;
  

}
