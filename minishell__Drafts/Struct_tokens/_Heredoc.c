#include "v6.h"

static int	heredoc_2nd_layer(t_atom *node);

int	heredoc_1st_layer(t_token *node)
{
	g_exit_status = 0;
	while (node)
	{
		if (heredoc_2nd_layer(node->REDIR_IN) == 0)
		{
			return (0);
		}
		node = node->next;
	}
	return (1);
}

//	(file scoped)

static int	heredoc_2nd_layer(t_atom *node)
{
	// need filename
	// enter 3rd layer
	// need stderr msg display
	return (node == null);
}


