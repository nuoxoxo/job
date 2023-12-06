#include "unistd.h"
#include "stdio.h"

int	main()
{
	int	fork_pid;
	int	i = 1;

	printf("i = %d \n", i);
	fork_pid = fork();
	if (fork_pid == 0)
		printf("child  (++i): i = %d (pid: %d) \n", ++i, fork_pid);
	else
		printf("parent (--i): i = %d (pid: %d) \n", --i, fork_pid);
}
