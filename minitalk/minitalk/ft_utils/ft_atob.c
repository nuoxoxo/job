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

#include "../minitalk.h"

char	*ft_atob(char *s, int len)
{
	char	*binary;
	char	c;
	int		i;
	int		b;

	if (!s)
		return (0);
	binary = (char *) malloc(sizeof(char) * ((len + 1) * 8 + 1));
	binary[0] = '\0';
	i = -1;
	while (++i < len)
	{
		c = s[i];
		b = 8;
		while (--b > -1)
		{
			if (c & (1 << b))
				ft_strcat(binary, "1");
			else
				ft_strcat(binary, "0");
		}
	}
	ft_strcat(binary, "00001010");
	return (binary);
}
