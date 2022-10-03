#include "unistd.h"
#include "signal.h"
#include "stdio.h"

void    handler(int n);

int     main()
{
        struct  sigaction       sa;

        sa.sa_handler = handler;
        sa.sa_flags = 0;
        sigaction(SIGINT, &sa, NULL);
        sigaction(SIGTERM, &sa, NULL);
        sigaction(SIGABRT, &sa, NULL);

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
}
