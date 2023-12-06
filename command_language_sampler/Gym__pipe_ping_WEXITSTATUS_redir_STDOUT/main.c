#include "stdlib.h" // exit
#include "unistd.h" // null
#include "sys/wait.h"
#include "stdio.h"
#include "fcntl.h"

# define c1 "\x1b[33m"
# define c2 "\x1b[36m"
# define nc "\x1b[0m"
# define Simple_File "in.0"
# define HOST "google.com"
//# define HOST "google.cmo"

/* Goal */

// What we want to do is:
//	1. ping google.com 5 times in a child process
//	2. the noutput is captured and redirected, before it is printed on stdout
//	3. in the child, we will do the following
//		3.1 touch a file, open it, and receive a file descriptor
//		3.2 dup2()
//			- we use dup2() to make a copy of STDOUT
//			- we make a copy of STDERR too
//		3.4 the replies echoed back by the HOST is saved in an file
//		3.5 error msg is also written to file if ping fails

//			

int	main()
{
	int	pipe_fd[2];
	int	pid_1;
	int	ok;
	int	file;
	int	wstatus;
	int	status_code;

	// step 1

	if (pipe(pipe_fd) == -1)
	{
		exit (1);
	}
	pid_1 = fork();
	if (pid_1 == -1)
	{
		exit (2);
	}

	// exec in the child

	if (pid_1 == 0)
	{
		file = open(Simple_File, O_WRONLY | O_CREAT, 0777);
		if (file == -1)
		{
			return file;
		}

		printf(c2 "(file descriptor: %d) \n" nc, file);

		dup2(file, STDOUT_FILENO);
		dup2(file, STDERR_FILENO);
		close(file);
		ok = execlp("ping", "ping", "-c", "5", HOST, NULL); // modify param here
		if (ok == -1)
		{
			return(printf(c1 "command not found. \n" nc), 1);
		}
	}

	wait(& wstatus);

	if (WIFEXITED(wstatus)) /* HERE */
	{
		status_code = WEXITSTATUS(wstatus); /* HERE */

		if (status_code == 0)
			return (printf(c1 "child successful. \n" nc), 0);
		return (printf(c1 "child failed. status: %d \n" nc, status_code), 0);
	}
	return 0;
}
