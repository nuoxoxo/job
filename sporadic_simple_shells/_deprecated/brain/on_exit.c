/* ************************************************************************** */
/*                                                                            */
/*                            \\             /`/``                            */
/*                            ~\o o_       0 0\                               */
/*                            / \__)      (u  ); _  _                         */
/*                     / \/ \/  /           \  \/ \/ \                        */
/*                    /(   . . )            (         )\                      */
/*                   /  \_____/              \_______/  \                     */
/*                       []  []               [[] [[]    *.                   */
/*                       []] []]              [[] [[]                         */
/*                                                                            */
/* ****************************************************************** nxu *** */

#include "minishell.h"

void	usage(void)
{
	exit_prompt(2, "Usage: ./minishell [ no trailing arguments ]", 1);
}

void	exit_prompt(int fd, char *msg, int exit_code)
{
	ft_putstr_fd(msg, fd); /* libft ver. as opposed to . puts_fd(fd, msg) */
	exit_safe(exit_code);
}

void	exit_safe(int exit_code)
{
	clean_all();
	exit(exit_code);
}

void	clean_all()
{
	// do nothing just yet
	return ;
}
