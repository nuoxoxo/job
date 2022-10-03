#include "v6.h"

/*
◦ echo 	with option ’-n’ 
◦ cd 	with only a relative or absolute path
◦ pwd 	without any options 
◦ export without any options 
◦ unset without any options 
◦ env 	without any options and any arguments	::: Here ::: 
◦ exit 	without any options 
*/

void	builtin_env(t_atom *atom, t_env *node)
{
	char		*m;

	// subject not clear:
	// """without any options and any arguments"""
	// does it mean any argument will lead to nosaj file? 

	if (atom->next)
	{
		m = ft_strjoin_triple("env: ", atom->next->str,
				": No such file or directory \n");
		ft_putstr_fd(m, STDOUT_FILENO);
		free(m);
		return ;
	}
	// node_print(node); // can't use printf
	while (node)
	{
		if (node->val)
		{
			ft_putstr_fd(node->key, STDOUT_FILENO);
			ft_putstr_fd("=", STDOUT_FILENO);
			ft_putendl_fd(node->val, STDOUT_FILENO);
		}
		node = node->next;
	}
}
