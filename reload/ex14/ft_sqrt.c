/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 15:19:56 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/18 20:36:11 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 46340 ( bigggest number to square w/o overflowing a 32-bit integer )
 * est la dernière valeur entière représentant la plus 
 * grande valeur d'un int qui possède la racine carré
 * entière donc cela ne sert à rien d'aller plus loin   */

/*

// DRIVE

#include    <stdio.h>

int         ft_sqrt(int n);

int main()
{
            printf("sqrt(-1)            = %i\n", ft_sqrt(-1));
            printf("sqrt(0)             = %i\n", ft_sqrt(0));
            printf("sqrt(4)             = %i\n", ft_sqrt(4));
            printf("sqrt(81)            = %i\n", ft_sqrt(81));
            printf("sqrt(625)           = %i\n", ft_sqrt(625));
	    printf("sqrt(2147395600)    = %i\n", ft_sqrt(2147395600));
            printf("sqrt(2147483647)    = %i\n", ft_sqrt(2147483647));
}

*/

int	ft_sqrt(int nb)
{
	int	x;

	x = 1;
	while (x * x <= nb && x <= 46340)
	{
		if (x * x == nb)
			return (x);
		x++;
	}
	return (0);
}
