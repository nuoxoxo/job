#include "v6.h"

void	handle_signal_exit(int);
void	handle_sigquit(int);
void	handle_sigint(int);

void	handle_signal(enum e_sig_mode mode)
{
	if (mode == READLINE)
	{
		signal(SIGINT, handle_sigint);
		signal(SIGQUIT, handle_sigquit);
	}
	else if (mode == HEREDOC)
	{
		signal(SIGINT, handle_signal_exit);
		signal(SIGQUIT, handle_sigquit);
	}
	else if (mode == SIG_WAIT)
	{
		signal(SIGINT, SIG_IGN);
		signal(SIGQUIT, SIG_IGN);
	}
}

void	handle_sigint(int signum)
{
	if (signum != SIGINT)
		return ;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b\n", STDOUT_FILENO);
	rl_on_new_line();
	//rl_replace_line("", 1);
	rl_redisplay();
}

void	handle_sigquit(int signum)
{
	if (signum != SIGQUIT)
		return ;
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b", STDOUT_FILENO);
}

void	handle_signal_exit(int signum)
{
	rl_on_new_line();
	rl_redisplay();
	ft_putstr_fd("  \b\b\n", STDOUT_FILENO);
	rl_on_new_line();
	//rl_replace_line("", 1);
	(void) signum;
    exit(1);
}
