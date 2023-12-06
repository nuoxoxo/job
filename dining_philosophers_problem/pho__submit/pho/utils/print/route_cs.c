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

#include "print.h"

int	route_chr(int c)
{
	return (write(1, & c, 1));
}

int	route_str(char *s)
{
	int	i;

	i = 6;
	if (!s)
	{
		write(1, "(NULL)", i);
		return (i);
	}
	i = -1;
	while (s[++i])
		write(1, & s[i], 1);
	return (i);
}
