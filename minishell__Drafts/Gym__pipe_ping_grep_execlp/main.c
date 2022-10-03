/*
 *
 * subject: pipe ping result to grep
 *
 */

/*
 * in pipe_fd[2]: 0 is the read end, 1 the write end
 *
 * the main proc creates 2 processes, one for *ping, the other for *grep
 * and to `channel` the two processes, the main proc needs to create a *pipe
 *
 */

#include "unistd.h"
#include "sys/wait.h"

int	main()
{
	int	pipe_fd[2];
	int	pid_1, pid_2;

	if (pipe(pipe_fd) == -1)
	{
		return 1;
	}
	pid_1 = fork(); // ping
	if (pid_1 == -1)
	{
		return 2;
	}
	if (! pid_1) // check if in the child, 0 means we are in the child
	{
		// Child process 1 (ping)

		dup2(pipe_fd[1], STDOUT_FILENO);
		// dup2 replaces its standard output with the write end of pipp
		// line below is idem, because stdout_fileno expands to 1
		// dup2(fd[1], 1);

		close(pipe_fd[1]); // is copied, remains open, should be closed
		close(pipe_fd[0]); // is not in use

		execlp("ping", "ping", "-c", "5", "google.com", NULL); 

	}

	// in Parent once we leave child scope

	pid_2 = fork(); // grep
	if (pid_2 == -1)
	{
		return 3;
	}
	if (! pid_2)
	{
		// Child process 2 (grep)

		dup2(pipe_fd[0], STDIN_FILENO);
		// replaces child's standard input with the read end of pipp
		close(pipe_fd[0]);
		close(pipe_fd[1]);

		execlp("grep", "grep", "round", NULL);
	}

	close(pipe_fd[1]); // close the write end otherwise child2 keeps waiting
	close(pipe_fd[0]); // not needed but recommended

	waitpid(pid_1, NULL, 0);
	waitpid(pid_2, NULL, 0);

}
