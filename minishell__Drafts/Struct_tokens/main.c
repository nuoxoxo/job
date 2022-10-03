#include "v6.h"

int g_exit_status = 0;

int	main(int c, char *v[], char *envp[])
{
	t_token		*tokenlist;
	t_atom		*atomlist;
	t_env		*envlist;
	char		*line;

	//handle_signal(READLINE); // New . READLINE is 0

	g_exit_status = 0;
	envlist = envp_to_envlist(envp);

	// envlist_print(envlist);		// printer debugger 1
	// print_char_star_array(envlist_to_arr(envlist)); // printer debugger 2

	//atomlist = NULL; // to not SEGV, nullify inside while
	tokenlist = NULL;
	while (1)
	{
		atomlist = NULL; // to not SEGV, nullify alst here
		line = readline(PROMPT2);
		print_input(line);
		if (!slen(line))
			continue ;
		if (atomlist_get(line, & atomlist, envlist))
			print_atomlist(atomlist);
		else
			continue ;
		if (tokenlist_get(& tokenlist, atomlist, envlist))
			print_tokenlist(tokenlist);
		/*
		if (heredoc_1st_layer(tokenlist))
			print( color3 "heredoc ok. :-) \n" noc);
		else
			print( color3 "heredoc fails. > .< \n" noc);
		*/
		if (tokenlist)
		{
			tokenlist_free(tokenlist);
			tokenlist = NULL;
		}
	}
	envlist_free(envlist); // we only need to free the environ list
	(void) c;
	(void) v;

	//atomlist_free(atomlist);
	//tokenlist_free(tokenlist);
	//(void) tokenlist;
}
