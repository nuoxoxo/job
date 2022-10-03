/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nuo               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nuo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_jan06.h"
//#include "get_next_line.h"

int	len(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

char	*sc(int c, char *s)
{
	int	i;

	if (!s)
		return (0);
	if (!c)
		return ((char *) &s[len(s)]);
	i = -1;
	while (s[++i])
	{
		if (c == s[i])
			return ((char *) &s[i]);
	}
	return (0);
}
