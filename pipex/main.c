#include "Pipex.h"

int	main(int c, char **v, char **env)
{
	int		pipefd[2];
	int		pipe_ret;
	pid_t		pid;	// int also works

	if (c != 5)
		return (usage(), 1);
	pipe_ret = pipe(pipefd);		// pipe
	if (pipe_ret == -1)
		error_exit("Error on calling pipe() \n");
	pid = fork();			// fork
	if (pid == -1)
		error_exit("Error on calling fork() \n");
	if (pid == 0)
		child_process(v, env, pipefd); // CHILD
	waitpid(pid, NULL, 0); // pid_t waitpid(pid_t pid, int *status, int option)
	parent_process(v, env, pipefd); // PARENT

	return (0);
}

/*
 *	int	pipe(int pipefd[2]);
 */

///

/*
void	parent_process(char **argv, char **envp, int pipe_fd[2])
{
	int		file_out;

	file_out = open(arg[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (file_out == -1)
		error_exit("Error on calling open() inside parent \n");
	dup2(pipe_fd[0], STDIN_FILENO); // from pipe take something
	dup2(file_out, STDOUT_FILENO); // from stdout to fileout
	close(fd[1]);
	exec_cmd(arg[3], env);
}

void	child_process(char **arg, char **env, int pipe_fd[2])
{
	int		file_in;

	file_in = open(arg[1], O_RDONLY, 0777); // read_only because we only read XD
	if (file_in == -1)
		error_exit("Error on calling open() inside child \n");
	dup2(pipe_fd[1], STDOUT_FILENO); // from stdout to pipe
	dup2(file_in, STDIN_FILENO);
	close(pipe_fd[0]);
	exec_cmd(arg[2], env);
}
*/
