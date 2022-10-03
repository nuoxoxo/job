#include "v5.h"

int	main(int c, char *v[], char *envp[])
{
	t_atom		*atomlist;
	t_env		*envlist;
	char		*line;

	//handle_signal(READLINE); // New . READLINE is 0

	g_exit_status = 0;
	envlist = envp_to_envlist(envp);

	// envlist_print(envlist);		// printer debugger 1
	// print_char_star_array(envlist_to_arr(envlist)); // printer debugger 2

	atomlist = NULL;
	while (1)
	{
		line = readline(PROMPT2);
		print_input(line);
		if (line)
		{
			if (atomlist_get(line, & atomlist, envlist))
				atomlist_print(atomlist);
		}
		/*
		else
		{
			ft_putendl_fd("exit", STDOUT_FILENO);
			break ;
		}
		*/
	}
	atomlist_free(atomlist);
	envlist_free(envlist);
	(void) c;
	(void) v;
}
