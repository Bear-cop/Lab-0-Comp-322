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
  umask(0);
  mole = fork();
  
  if(mole > 0){
   return EXIT_SUCCESS; 
  }
  else if(mole == 0){
    
    
    
  }
  
  return EXIT_SUCCESS
}
