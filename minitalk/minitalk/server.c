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

void	handler(int _);

int	main(void)
{
	ft_putstr("Server PID: ");
	ft_putnbr((int) getpid());
	ft_putstr("\nListening... \n");
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}
	write(1, "\n", 1);
	return (0);
}

void	handler(int sig)
{
	static char	*bins;
	static int	n;
	char		c;

	if (!bins)
	{
		bins = ft_strdup("");
		n = 1;
	}
	else
		++n;
	if (sig == SIGUSR1)
		bins = ft_strncat(bins, "1", 1);
	else
		bins = ft_strncat(bins, "0", 1);
	if (n == 8)
	{
		c = ft_btoc(bins);
		write(1, &c, 1);
		free(bins);
		bins = NULL;
	}
}
