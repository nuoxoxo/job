#include "unistd.h"
#include "signal.h"
#include "stdio.h"

void    handler(int n);

int     main()
{
        signal(SIGINT, handler);        // -2
        signal(SIGABRT, handler);       // -6
        signal(SIGTERM, handler);       // -15

        while (1)
        {
            printf("Hello World. %d \n", getpid());
            sleep(1);
        }
}

void    handler(int n)
{
        (void)  n;
        write(STDOUT_FILENO, "  signal received. \n", 20);
        
        //write(1, "  signal received. \n", 20);
}
