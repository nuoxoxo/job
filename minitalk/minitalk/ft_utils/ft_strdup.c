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

char	*ft_strdup(char *src)
{
	char	*ptr;
	char	*des;
	int		size;

	size = (int) ft_strlen(src);
	des = (char *) malloc(sizeof(char) * (size + 1));
	if (!des)
	{
		return (NULL);
	}
	ptr = des;
	while (*src)
	{
		*des++ = *src++;
	}
	*des = 0;
	return (ptr);
}
