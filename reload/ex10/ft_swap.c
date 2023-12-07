/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo  <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 09:20:56 by nuo               #+#    #+#             */
/*   Updated: 2021/08/07 15:51:20 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

// DRIVE

#include <stdio.h>

void    ft_swap(int *a, int *b);

int     main()
{
        int x = 1024;
        int y = -2147483648;
        printf("x : %i\ny : %i\n\n", x, y);
        ft_swap(&x, &y);
        printf("x : %i\ny : %i\n", x, y);
}

*/

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}