#include "unistd.h"
#include "stdio.h"
#include <sys/wait.h>

#define N       printf("\n")

int     main()
{
        int     pid = fork();
        int     count, i;
        int     w = wait(0); // until one of its child processes exits or a signal is received
        if (!pid)
        {
                printf("(c) \n");
                count = 1;
        }
        else
        {
                printf("(p) \n");
                count = 6;
        }
        i = count;
        while (i < count + 5)
        {
                printf("%d ", i++);
                fflush(stdout); // omittable
        }
        N;
        printf("return of fork : %d \n", pid);
        printf("return of wait : %d \n", w);
        // returns the pid of the terminated child process
        // returns -1 if a process has no child process (indicating it is the child)
        N;
        return (0);
}
