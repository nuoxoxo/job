#include "v6.h"

int g_exit_status = 0;

int	main(int c, char *v[], char *envp[])
{
	enum e_btn_type		builtin_type; // New
	t_token			*tokenlist;
	t_atom			*atomlist;
	t_env			*envlist;
	char			*line;
	int			status;

	//handle_signal(READLINE); // New . READLINE is 0

	g_exit_status = 0;
	envlist = envp_to_envlist(envp);

	// envlist_print(envlist);		// printer debugger 1
	// print_char_star_array(envlist_to_arr(envlist)); // printer debugger 2

	//atomlist = null; // to not SEGV, nullify inside while
	tokenlist = null;
	while (1)
	{
		line = readline(PROMPT);
		print_input(line);
		if (!ft_strlen(line))
			continue ;
		add_history(line);

		// atom
		atomlist = null; // to not SEGV, nullify alst here
		if (atomlist_get(line, & atomlist, envlist))
			print_atomlist(atomlist);
		else
			continue ;

		// token
		if (tokenlist_get(& tokenlist, atomlist, envlist))
			print_tokenlist(tokenlist);

		// heredoc
		if (heredoc_1st_layer(tokenlist))
			print( color2 "heredoc ok. :D " noc nl);
		else
			print( color2 "heredoc fails. xD " noc nl);

		// builtin_typeof
		builtin_type = builtin_typeof(tokenlist->cmd, tokenlist);
		print_builtin_type(builtin_type);

		// check infile & outfile before xcq builtin
		status = check_io_file(tokenlist);
		print(color1 "infile/outfile check result: %d " nl noc, status);
		
		//if (builtin_type != NONE && !(tokenlist->next)) // ibid.
		if (builtin_type && !(tokenlist->next)) // ibid.
		{
			builtin_atom(envlist, tokenlist, builtin_type);
		}
		else
		{
			// xcq(envlist, tokenlist);
		}
		// cleanup
		if (tokenlist)
		{
			heredoc_unlink(tokenlist);
			tokenlist_free(tokenlist);
			tokenlist = null;
		}
		// print("\nreached bottom of main :) \n");
	}
	envlist_free(envlist); // we only need to free the environ list
	(void) c;
	(void) v;
	(void) builtin_type; // New
	(void) *tokenlist;
	(void) *atomlist;
	(void) *envlist;
	(void) *line;
	(void) status;

	//atomlist_free(atomlist);
	//tokenlist_free(tokenlist);
}
