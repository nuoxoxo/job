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

void    handler(int sig)
{
        if (sig == 2)
        {
                write(1, " kill 2 (SIGINT) sent.       \n", 30);
        }
        else if (sig == 6)
        {
                write(1, " kill 6 (SIGABRT) sent.      \n", 30);
        }
        else if (sig == 15)
        {
                write(1, " kill 15 (SIGTERM) sent.     \n", 30);
        }
        else
        {
                write(STDOUT_FILENO, "  signal received. \n", 20);
        }
}
