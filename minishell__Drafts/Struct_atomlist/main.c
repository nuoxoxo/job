#include "Atomlist.h"

int	g_exit_status;

void	stringlist_print(t_atom *stringlist);

int	main(int c, char *v[], char *envp[])
{
	t_atom		*stringlist;
	t_env		*envlist;
	char		*line;

	g_exit_status = 0;
	envlist = envp_to_envlist(envp);
	envlist_print(envlist);
	while (47 * 59 * 71)
	{
		line = readline(PROMPT);
		if (line)
		{
//			stringlist_get(line, & stringlist, envlist);
			if (stringlist_get(line, & stringlist, envlist))
				stringlist_print(stringlist);
		}
	}
	stringlist_free(stringlist);
	envlist_free(envlist);
	(void) c;
	(void) v;
}
