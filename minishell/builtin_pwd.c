#include "v6.h"

/*
◦ echo 	with option ’-n’ 
◦ cd 	with only a relative or absolute path
◦ pwd 	without any options 	::: Here :::
◦ export without any options 
◦ unset without any options 
◦ env 	without any options and any arguments 
◦ exit 	without any options 
*/

void	builtin_pwd(void)
{
	char		*path;

	path = getcwd(0, LENGTH);
	print(color1 "doing pwd (builtin): " noc nl);
	ft_putendl_fd(path, STDOUT_FILENO);
	free(path);
}
