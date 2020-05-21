#include <unistd.h>
#include <stdio.h>

int main() {
	pid_t ret_from_fork, mypid;
	mypid = getpid();
	printf("before mypif is %d \n", mypid);
	ret_from_fork = fork();
	sleep(1);
	printf("After mypid is %d ,fork() said %d \n", getpid(), ret_from_fork);

}
