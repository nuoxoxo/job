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

#include "./../minishell.h"

void	catch_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, & handle_sigint);
}

void	handle_sigint(int sig)
{
	if (sig ^ SIGINT || errno ^ EINTR)
		return ;
	ft_putstr_fd("\n", 0);
	rl_on_new_line();
	rl_redisplay();
	g_exit_status = 130;
}

/*

void	handle_sigint(int sig)
{
	if (sig ^ SIGINT || errno ^ EINTR)
		return ;
	ft_putstr_fd("\n", 0);
	ft_putstr_fd("prompt> ", 0); // wonder if neccessary . to test on ubu
	rl_on_new_line();
	rl_replace_line("", 0); // error at compile time . to test on ubu
	rl_redisplay();
	g_exit_status = 130;
}

*/
