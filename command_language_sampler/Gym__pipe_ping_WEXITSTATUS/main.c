#include "stdlib.h" // exit
#include "unistd.h" // null
#include "sys/wait.h"
#include "stdio.h"
#include "fcntl.h" // open

# define c1 "\x1b[33m"
# define c2 "\x1b[34m"
# define nc "\x1b[0m"

# define GOOGLE "google.com"	// Correct
// # define GOOGLE "google.goo"	// Wrong on purpose

int	main()
{
	int		pipe_fd[2];
	int		fork_pid;
	int		ok;
	int		wstatus;
	int		status_code;

	if (pipe(pipe_fd) == -1)
	{
		exit (1);
	}
	fork_pid = fork();
	if (fork_pid == -1)
	{
		exit (2);
	}
	if (! fork_pid)
	{
		ok = execlp("ping", "ping", "-c", "5", GOOGLE, NULL);
		if (ok == -1)
		{
			return(printf(c1 "command not found. \n" nc), 1);
		}
	}
	wait(& wstatus);
	if (WIFEXITED(wstatus)) /* IMPORTANT */
	{
		status_code = WEXITSTATUS(wstatus); /* IMPORTANT */
		if (! status_code)
			return (printf(c1 "child finished successfully. \n" nc), 0);
		return (printf(c1 "child failed. status: %d \n" nc, status_code), 0);
	}
	return 0;
}
