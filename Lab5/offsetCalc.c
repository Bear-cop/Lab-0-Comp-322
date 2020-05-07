#include <stdio.h>
#include <stdlib.h>

void printA(int num){
    printf("The address %d contains:\n", num);
 
}

void printPN(int num){
  printf("Page Number = %d\n", num);
  
}

void printO(int num){
  printf("Offset = %d\n", num);
  
}

int main(int argc, char **argv){
  //define local variables
  //4kb = 4096 bytes
  const int size = 4096;
  unsigned int pageNum, address, offset;
  
  //check if # is < than 2
  if(argc < 2){
   printf("Error: not enough number of arguments");
    
    return EXIT_FAILURE;
  }//end if
  
  //Convert value into integer
  address = atoi(argv[1]);
  //computation of page number and offset
  pageNum = address/size;
  offset = address % size;
  
  //Display address, page number, and offset
printA(address);
printPN(pageNum);
printO(offset);
  
  return 0;
  
}//end main
