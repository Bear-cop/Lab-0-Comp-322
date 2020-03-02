#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/times.h>

void epochTime(char word[]){

	time_t clock; //variable for START/STOP times
	clock = time(NULL);
	printf("%s: %ld\n",word, clock);

}

void report(pid_t pid,int stat){

	if(pid == 0){
		printf("PPID: %d, PID: %d\n",getppid(),getpid());
		exit(0);
	}

	else{
		printf("PPID: %d, PID: %d, CPID: %d, RETVAL: %d\n",getppid(),getpid(),pid,stat);
	}

}

int main(){

	struct tms tick; //variable for  user/system time
	int status; //variable for status of child process
	pid_t cpid; //variable for child process creation

	epochTime("START");

	times(&tick); //time starts
	cpid = fork();
	waitpid(-1,&status,0);

	report(cpid,status);
	printf("USER: %jd, SYS: %jd\nCUSER: %jd, CSYS: %jd\n",tick.tms_utime,tick.tms_stime,tick.tms_cutime, tick.tms_cstime);

	epochTime("STOP");

	return(0);

}
