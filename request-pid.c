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

	FILE* fp = fopen("/sys/kernel/kernellab/kcurrent", "w");
	fprintf(fp, "%p", pid);
	fclose(fp);

        printf("Current PID: %d\n", *pid);
}

/* Part II */
void run_pid()
{
        struct pid_info info;

	struct sysf_message* msg = malloc(sizeof(struct sysf_message));

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
