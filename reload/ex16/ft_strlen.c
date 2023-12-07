/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo  <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 15:54:18 by nuo               #+#    #+#             */
/*   Updated: 2021/08/07 15:55:59 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

// Drive

#include    <stdio.h>

int     ft_strlen(char *s);

int     main(int a, char **s)
{
        (void)  a;
        printf("%i\n", ft_strlen(s[1]));
}

*/

int	ft_strlen(char *str)
{
	int	i;

        if (!str)
        {
                return (0);
        }
	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
