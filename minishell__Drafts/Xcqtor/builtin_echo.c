#include "v6.h"

/*
◦ echo 	with option ’-n’ 	::: Here :::
◦ cd 	with only a relative or absolute path
◦ pwd 	without any options 
◦ export without any options 
◦ unset without any options 
◦ env 	without any options and any arguments 
◦ exit 	without any options 
*/

static int	builtin_echo_has_n_flag(char *s); // file scope

void	builtin_echo(t_atom *atom)
{
	int		flag;

	print(color1 "doing echo (builtin): " noc nl); // dbg
	flag = 0;
	if (atom)
	{
		flag = builtin_echo_has_n_flag(atom->str);
		if (flag)
			atom = atom->next;
		while (atom)
		{
			ft_putstr_fd(atom->str, STDOUT_FILENO);
			atom = atom->next;
			if (atom)
				ft_putstr_fd(" ", STDOUT_FILENO);
		}
		if (flag)
			return ;
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
}

static int	builtin_echo_has_n_flag(char *s)
{
	if (!ft_strncmp(s, "-n", 2))
	{
		return (1);
	}
	/*
	s += 2;
	while (*s)
	{
		if (*s != 'n')
		{
			return (1);
		}
		s++;
	}
	*/
	return (0);
}
