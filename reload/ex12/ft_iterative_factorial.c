/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 12:57:29 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/19 18:04:22 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

// DRIVE

#include <stdio.h>

int     ft_iterative_factorial(int nb);

int     main()
{
    printf("%i! = %i\n", 0, ft_iterative_factorial(0));
    printf("%i! = %i\n", 1, ft_iterative_factorial(1));
    printf("%i! = %i\n", 2, ft_iterative_factorial(2));
    printf("%i! = %i\n", 3, ft_iterative_factorial(3));
    printf("%i! = %i\n", 4, ft_iterative_factorial(4));
    printf("%i! = %i\n", 5, ft_iterative_factorial(5));
    printf("%i! = %i\n", 6, ft_iterative_factorial(6));
    printf("%i! = %i\n", 12, ft_iterative_factorial(12));
}

*/

int	ft_iterative_factorial(int nb)
{
	int	i;

	if (nb == 0 || nb == 1)
		return (1);
	if (nb < 0)
		return (0);
	i = nb;
	while (i > 1)
	{
		nb *= i - 1;
		i--;
	}
	return (nb);
}
