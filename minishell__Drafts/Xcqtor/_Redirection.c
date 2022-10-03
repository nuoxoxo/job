#include "v6.h"

void	config_outfile(t_atom *atom);
void	config_infile(t_atom *atom);

void	redirection_config(t_token *node)
{
	if (node->prev && dup2(node->prev->pipe_fd[0], STDIN_FILENO) < 0)
	{
		exit_error_message("dup2");
	}
	if (node->REDIR_IN)
	{
		config_infile(node->REDIR_IN);
	}
	if (node->next && dup2(node->pipe_fd[1], STDOUT_FILENO) < 0)
	{
		exit_error_message("dup2");
	}
	if (node->REDIR_OUT)
	{
		config_outfile(node->REDIR_OUT);
	}
	close(node->pipe_fd[0]);
	close(node->pipe_fd[1]);
}

void	config_infile(t_atom *atom)
{
	int			fd;

	while (atom)
	{
		if (atom->next == null)
			break ;
		atom = atom->next;
	}

	fd = open(atom->str, O_RDONLY);
	if (fd < 0)
		exit_error_message(atom->str);
	if (dup2(fd, STDIN_FILENO) < 0)
	{
		exit_error_message(atom->str);
	}
	close(fd);
}

void	config_outfile(t_atom *atom)
{
	int			fd;

	while (atom)
	{
		if (atom->next == null)
			break ;
		atom = atom->next;
	}
	if (atom->type == T_REDIR_OUT)
	{
		fd = open(atom->str, O_WRONLY | O_TRUNC | O_CREAT, 0644); // Trunc
	}
	else
	{
		fd = open(atom->str, O_WRONLY | O_APPEND | O_CREAT, 0644); // Append
	}
	if (fd < 0)
		exit_error_message(atom->str);
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		exit_error_message(atom->str);
	}
	close(fd);
}
