/* ************************************************************************** */
/*                                                                            */
/*                                                        ...      :::::::    */
/*   _                                                  ...      :::    :::   */
/*                                                    ... ...         :::     */
/*   By: nuo <marvin@42.fr>                         ...  ...       :::        */
/*                                                ...........   :::           */
/*   Created: ____/__/__ __:__:__ by nuo               ...    :::             */
/*   Updated: ____/__/__ __:__:__ by nuo              ...   ::::::::.fi       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sender(int ___, char *__, int *_);
void	prompt(int _);

int	main(int c, char **v)
{
	int		bts;
	int		pid;
	int		len;
	char	*bin;

	if (c != 3)
		prompt(0);
	pid = ft_atoi(v[1]);
	if (pid < 0)
		prompt(1);
	len = ft_strlen(v[2]);
	bin = ft_atob(v[2], len);
	if (!bin)
		prompt(2);
	bts = -8;
	sender(pid, bin, &bts);
	if (bin)
	{
		free(bin);
	}
	ft_printf("Server received %d bits, %d bytes \n", bts, bts / 8);
	return (0);
}

void	sender(int pid, char *s, int *b)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] == '1')
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		++(*b);
		usleep(1e3);
	}
}

//	usleep min : 16

void	prompt(int n)
{
	int	i;

	i = 42;
	if (!n)
	{
		write(1, "usage: ./client server_pid message       \n", i);
	}
	if (n == 1)
	{
		write(1, "negative pid.                            \n", i);
	}
	if (n == 2)
	{
		write(1, "not enough space.                        \n", i);
	}
	exit (0);
}
