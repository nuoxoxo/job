#include "unistd.h"
#include "stdio.h"

int	main()
{
        int pid = fork();
        printf("Hello World. pid: %d ret: %d ", getpid(), pid);
        if (!pid)
        {
                printf("(child)");
        }
        printf("\n");
        return (0);
}
