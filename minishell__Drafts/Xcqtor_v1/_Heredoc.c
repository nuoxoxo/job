#include "v6.h"

int		heredoc_2nd_layer(t_atom *node);
char		*heredoc_path_builder(void);

int	heredoc_1st_layer(t_token *node)
{
	g_exit_status = 0;
	while (node)
	{
		if (!heredoc_2nd_layer(node->REDIR_IN))
		{
			return (0);
		}
		node = node->next;
	}
	return (1);
}

int	heredoc_3rd_layer(t_atom *node, char *filename)
{
	char		*line;
	int		fd;

	// handle_signal(HEREDOC);
	fd = open(filename, O_WRONLY | O_CREAT, 0777);
	while (1024)
	{
		line = readline("> ");
		if (!ft_strcmp(node->str, line))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fd);
		free(line);
	}
	close(fd);
	exit(0);
}

void	heredoc_unlink(t_token *node)
{
	t_atom		*node_in;

	while (node)
	{
		node_in = node->REDIR_IN;
		while (node_in)
		{
			if (node_in->type == T_HEREDOC)
			{
				unlink(node_in->str);
			}
			node_in = node_in->next;
		}
		node = node->next;
	}
}

//	(file scope)

int	heredoc_2nd_layer(t_atom *node)
{
	int		pid;
	char		*filename;

	while (node)
	{
		if (node->type == T_HEREDOC)
		{
			filename = heredoc_path_builder();
			pid = fork();
			if (! pid)
			{
				heredoc_3rd_layer(node, filename);
			}
			handle_signal(SIG_WAIT);
			free(node->str);
			node->str = filename;
			wait(& g_exit_status);
			handle_signal(READLINE);
			if (WEXITSTATUS(g_exit_status) == 1)
			{
				g_exit_status = WEXITSTATUS(g_exit_status);
				return (0);
			}
		}
		node = node->next;
	}
	//return (node == null);
	return (1);
}

char	*heredoc_path_builder(void)
{
	int		num;
	char		*filename;
	char		*file_num;
	struct stat	info;

	num = 0;
	file_num = ft_itoa(num);
	filename = ft_strjoin_protected("/tmp/", file_num);
	if (!filename)
		ft_exit_error_alloc();
	while (! stat(filename, & info))
	{
		free(file_num);
		file_num = ft_itoa(++num);
		free(filename);
		filename = ft_strjoin_protected("/tmp/", file_num);
		if (! filename)
			ft_exit_error_alloc();
	}
	free(file_num);
	return (filename);
} 
