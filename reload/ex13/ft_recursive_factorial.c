/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 13:52:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/19 18:04:32 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

// DRIVE

#include <stdio.h>

int     ft_recursive_factorial(int nb);

int     main()
{
    printf("%i! = %i\n", 0, ft_recursive_factorial(0));
    printf("%i! = %i\n", 1, ft_recursive_factorial(1));
    printf("%i! = %i\n", 2, ft_recursive_factorial(2));
    printf("%i! = %i\n", 3, ft_recursive_factorial(3));
    printf("%i! = %i\n", 4, ft_recursive_factorial(4));
    printf("%i! = %i\n", 5, ft_recursive_factorial(5));
    printf("%i! = %i\n", 6, ft_recursive_factorial(6));
    printf("%i! = %i\n", 12, ft_recursive_factorial(12));
}

*/

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 1 || nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}
