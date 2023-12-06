#include "stdlib.h" // exit
#include "unistd.h" // null
#include "sys/wait.h"
#include "stdio.h"
#include "fcntl.h"

# define c1 "\x1b[33m"
# define c2 "\x1b[36m"
# define nc "\x1b[0m"
# define GOOGLE "google.com"
// # define GOOGLE "google.123"

int	main()
{
	int	pipe_fd[2];
	int	pid_1;
	int	ok;
	int	wstatus;
	int	status_code;
	int	file; // new

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
		// new
		file = open("in.0", O_WRONLY | O_CREAT, 0777);
		if (file == -1)
		{
			return file;
		}
		printf(c2 "file: %d \n" nc, file);

		// test 1 : correct line

		dup2(file, STDOUT_FILENO);
	
		// test 2 : just a test

		//int file2 = dup2(file, STDOUT_FILENO);
		//printf(c2 "file2: %d \n" nc, file2); // noshow as stdout is swapped

		close(file);

		ok = execlp("ping", "ping", "-c", "5", GOOGLE, NULL);
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
			return (printf(c1 "child finished successfully. \n" nc), 0);
		return (printf(c1 "child failed. \nstatus code: %d \n" nc, status_code), 0);
	}
	return 0;
}
