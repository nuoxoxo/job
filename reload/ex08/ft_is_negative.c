/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:14:10 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/09 14:14:12 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

/*

// DRIVE

void    ft_is_negative(int hello);
void    ft_putchar(char world);

int     main()
{
        ft_is_negative(0);
        ft_is_negative(-1);
        ft_is_negative(2147483647);
        ft_is_negative(-2147483648);
        ft_is_negative(1);
}

*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_is_negative(int n)
{
	if (n < 0)
	{
		ft_putchar('N');
	}
	else
	{
		ft_putchar('P');
	}
}
