//Ricardo Carrillo
//05/09/2020
//moles.c for Wack A Mole

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if (argc < 2) {
        exit(EXIT_FAILURE);
    }

    FILE *logfile = fopen(argv[2], "a+");
	fprintf(logfile, "Pop %s\n", argv[1]);
    fclose(logfile); 
}
