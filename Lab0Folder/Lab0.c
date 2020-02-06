#include <stdio.h>
        int main(){
                char num;
                char name_file;
                File *fl;
                gets(name_file);
                fl = fopen(name_file,"r");
                if(fl == NULL){
                        perror("Ooopsie file not read\n");
                        exit(EXIT_FAILURE);
                }
                printf("Original   ASCII   Decimal   Parity   T. Error  \n -------- -------- -------- -------- --------");
        }
~           
