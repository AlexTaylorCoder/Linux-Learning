#include <stdlib.h>
#include <stdio.h>

#define SEG_SIZE 2

typedef struct Process {
	int pid;
	char *buff; //mock buffer would ref contained data
	
	int prio;	
	int niceness;
} Process;

typedef struct Scheduler {
	int seg;
	int len;
	int cap;
	Process *buff;

} Scheduler;

int main() {
//MSFQ impl
//based on num create arrs
//would prob make sense to create new tier arr once exceeds vals
//So can just use contiguo array with len
//
	Process pr1 = {1, "test\0", 3, 2};
	Process pr2 = {1, "test2\0", 3, 2};

	Process procs[] = {pr1, pr2};
	Scheduler s = {SEG_SIZE, 2, 2,procs};

	return 1;

}
