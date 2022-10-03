#include "v6.h"

/*
◦ echo 	with option ’-n’ 
◦ cd 	with only a relative or absolute path
◦ pwd 	without any options 
◦ export without any options 
◦ unset without any options 
◦ env 	without any options and any arguments 
◦ exit 	without any options 	::: Here :::
*/

void	builtin_exit(int exit_type)
{
	if (exit_type == EXIT)
	{
		ft_putstr_fd("[Process completed]\n", STDOUT_FILENO);
		g_exit_status = 0;
		exit(g_exit_status);
	}
}
