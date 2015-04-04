#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "pidinfo.h"

#include <unistd.h>

/* Part I */
void run_current()
{
        int* pid = malloc(sizeof(int));
	int fd;
	int address = (int)pid;
	printf("%p\n", pid);
	printf("%x\n", address);
	fd = open("/sys/kernel/kernellab/kcurrent", O_WRONLY);
	write(fd, (void*)address, sizeof(int));
	close(fd);

        printf("Current PID: %d\n", *pid);
}

/* Part II */
void run_pid()
{
        struct pid_info info;


        /* Your code here. */


        printf("PID: %d\n", info.pid);
        printf("COMM: %s\n", info.comm);
        printf("State: %ld", info.state);
}


int main()
{
        run_current();    
//        run_pid();
        return EXIT_SUCCESS;
}
