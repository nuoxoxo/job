#include "stdlib.h" // exit
#include "unistd.h" // null
#include "sys/wait.h"
#include "stdio.h"
#include "fcntl.h" // open

# define c1 "\x1b[33m"
# define c2 "\x1b[34m"
# define nc "\x1b[0m"

int	main()
{
	int	pipe_fd[2];
	int	pid_1;
	int	ok;
	int	wstatus;
	int	status_code;

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
		ok = execlp("ping", "ping", "-c", "5", "google.com", NULL);
		//ok = execlp("ping", "ping", "-c", "5", "google.moc", NULL);
		if (ok == -1)
		{
			return(printf(c1 "command not found. \n" nc), 1);
		}
	}

	wait(& wstatus);

	if (WIFEXITED(wstatus)) /* HERE */
	{
		status_code = WEXITSTATUS(wstatus); /* HERE*/

		if (! status_code)
			return (printf(c1 "child successful. \n" nc), 0);
		return (printf(c1 "child failed. status: %d \n" nc, status_code), 0);
	}
	return 0;
}
