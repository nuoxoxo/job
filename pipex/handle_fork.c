#include "Pipex.h"

/*
int	main(int c, char **v, char **env)
{
	int		pipefd[2];
	int		pipe_ret;
	pid_t		pid;	// int also works

	if (c != 5)
		return (usage(), 1);
	pipe_ret = pipe(pipefd);		// pipe
	if (pipe_ret == -1)
		_error_exit_("Error on calling pipe() \n");
	pid = fork();			// fork
	if (pid == -1)
		_error_exit_("Error on calling fork() \n");
	if (pid == 0)
		XCQ_Child(v, env, pipefd); // CHILD
	waitpid(pid, NULL, 0); // pid_t waitpid(pid_t pid, int *status, int option)
	XCQ_Parent(v, env, pipefd); // PARENT

	return (0);
}
*/

/*
 *
 * 	0777 (octal)
 * 		=
 * 	binary 0b 111 111 111
 * 		=
 * 	permissions rwxrwxrwx
 * 		=
 * 	decimal 511
 *
 *
 */

void	XCQ_Parent(char **arg, char **env, int pipe_fd[2])
{
	int		outfile;

	outfile = open(arg[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		_error_exit_("Error on calling open() inside parent \n");
	dup2(pipe_fd[0], STDIN_FILENO); // from pipe take something
	dup2(outfile, STDOUT_FILENO); // from stdout to fileout
	close(pipe_fd[1]);
	XCQ(arg[3], env);
}

/*
 *
 *	parent process
 *
 *	- get data from the pipe
 *	- then change the output to fileout
 *	- on closing the fileout, execute the command
 *
 *
 */

void	XCQ_Child(char **arg, char **env, int pipe_fd[2])
{
	int		file_in;

	file_in = open(arg[1], O_RDONLY, 0777); // read_only because we only read XD
	if (file_in == -1)
		_error_exit_("Error on calling open() inside child \n");
	dup2(pipe_fd[1], STDOUT_FILENO); // from stdout to pipe
	dup2(file_in, STDIN_FILENO);
	close(pipe_fd[0]);
	XCQ(arg[2], env);
}

/*
 *
 *	child process
 *
 *	- a child is the one who runs inside a fork
 *	- she is in a fork now
 *	- she takes the filein
 *	- put the Output inside a Pipe
 *	- on closing the fileIn, execute the command
 *
 *
 */
