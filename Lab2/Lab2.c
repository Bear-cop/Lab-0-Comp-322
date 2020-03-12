#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){

	fork();
	fprintf(stderr,"Hello");

}
