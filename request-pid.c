#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>

#include "pidinfo.h"

/* Part I */
void run_current()
{
        int pid = 0;


        /* Your code here. */


        printf("Current PID: %d\n", pid);
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
        run_pid();
        return EXIT_SUCCESS;
}
