#include "Envlist.h"

int g_exit_status = 0;

int	main(int c, char *v[], char *envp[])
{
	t_env		*envlist;

	g_exit_status = 0;
	envlist = envp_to_envlist(envp);
	envlist_print(envlist);
	envlist_free(envlist);

	(void) c;
	(void) v;
}
