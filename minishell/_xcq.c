#include "v6.h"

/*		helper func		*/

int		tokenlist_count_node(t_token *);
int		atomlist_count_node(t_atom *);
void	exit_if_path_error(char *, struct stat, char *);
void	ft_free_string_grid(char **argv); // in extended

//

/*		xcq fork & xcq child		*/

void	xcq_fork(t_token *token, t_env *envlist);

//

/*		xcq - ideal form			*/

// void		xcq(envlist, tokenlist);

//

/*		xcq - step-by-step			*/

//	1. inside loop
//		pipe	➜ pipe(token->pipe_id)
//		fork	➜ Execute one token* a time, need envlist*
//		close	(the write end, 1)
//	2. out of the loop
//		wait	➜ (wait for a pointer to head of tokens)

void	xcq(t_env *e, t_token *t)
{
	int		count = tokenlist_count_node(t);

	print(color0 "xcq: \"there are %d tokens in the list.\"" nl noc, count);
	if (count > 128)
	{
		ft_putstr_fd(PROMPT "pipe: Too many open files", STDERR_FILENO);
		return ;
	}
	while (t)
	{
		t->pid = 0;
		// pipe		➜ pipe(token->pipe_id)
		// fork		➜ TODO . Exeq 1 token* a time, need envlist*
		// close	➜ (close the write end, pipe_id[1])
		t = t->next;
	}
	// wait	➜ (wait for a pointer to head of tokens)
	(void) e;
	(void) t;
	return ;
}

void	xcq_fork(t_token *t, t_env *e)
{
	int				fork_id;

	fork_id = fork();
	t->pid = fork_id;
	if (fork_id < 0)
	{
		exit_error_message("fork");
	}
	if (!fork_id) // Child
	{
		//	pre-xcq main

		//		1 - check in-/outfiles
		check_io_file(t);

		//		2 - setup redirection . 2.1 - handle error - exit on err
		redirection_config(t);

		//	xcq main
		//	 - xcq main, need token & envlist	// TODO
		// 	xcq_main(token, elist);
	}
	(void) e;
	(void) t;
}

//	count nodes in a list

int	tokenlist_count_node(t_token *node)
{
	int		res;

	res = 0;
	while (node)
	{
		res++;
		node = node->next;
	}
	return (res);
}

int	atomlist_count_node(t_atom *node)
{
	int			res;

	res = 0;
	while (node)
	{
		node = node->next;
		++res;
	}
	return (res);
}

//	free

void	ft_free_string_grid(char **argv)
{
	int		i = -1;

	while (argv[++i])
		free(argv[i]);
	free(argv);
}

//	error exit

void	exit_if_path_error(char *path, struct stat info, char *command)
{
	if (!path || info.st_mode == S_IFDIR)
		exit_error_message(command);
}
