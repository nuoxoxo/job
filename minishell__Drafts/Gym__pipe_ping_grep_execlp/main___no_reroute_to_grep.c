#include "unistd.h"
#include "stdlib.h"
#include "string.h"
#include "sys/wait.h"
#include "stdio.h"

int	main()
{
	int	pipe_fd[2];
	int	pid_1;

	if (pipe(pipe_fd) == -1)
	{
		exit (1);
	}
	pid_1 = fork();
	if (pid_1 == -1)
	{
		exit (2);
	}
	if (! pid_1)
	{
		// This scope: Child process 1 (ping)

		execlp("ping", "ping", "-c", "5", "google.com", NULL); 

		// execute . list . path
		// is variadic
		// argument will be passed as /L/ist
		// system will search for program file in /P/ATH variable
	}
	waitpid(pid_1, NULL, 0);

}
