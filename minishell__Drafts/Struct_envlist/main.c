#include "Envlist.h"

int g_exit_status = 0;

int	main(int c, char *v[], char *envp[])
{
	t_env	*env_copy;

	g_exit_status = 0;

	env_copy = envp_to_envlist(envp, NULL);
	// printf("here be \n"); // debugged

	envlist_print(env_copy);
	// printf("here af \n"); // debugged

	envlist_free(env_copy);

	(void) c;
	(void) v;
}
