/* ************************************************************************** */
/*                                                                            */
/*                                                       .!.      .:+!^!+:.   */
/*   _                                                  .":      .:!    .:!   */
/*                                                    :!. .!:         !:.     */
/*   By: nuo <marvin@42.fr>                         +.+  :+:       :.:        */
/*                                                .:+!+:._.:.    +.+          */
/*   Created: ____/__/__ __:__:__ by nuo               :..    ...             */
/*   Updated: ____/__/__ __:__:__ by nuo              :._    .:.:_:.:.:.      */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

char	*ft_strncat(char *des, char *src, int n)
{
	int		i;
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(des) + 2));
	if (!res)
	{
		return (NULL);
	}
	i = 0;
	while (des[i] != '\0')
	{
		res[i] = des[i];
		i++;
	}
	res[i] = *src;
	res[i + 1] = '\0';
	(void) n;
	return (res);
}
