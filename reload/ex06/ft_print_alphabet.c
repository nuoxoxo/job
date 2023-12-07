/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 14:13:15 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/09 14:13:28 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    <unistd.h>

/*

// DRIVE

void    ft_print_alphabet(void);
void    ft_putchar(char c);

int     main()
{
        ft_print_alphabet();
}

*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_alphabet(void)
{
	int	i;

	i = 'a';
	while (i <= 'z')
                ft_putchar(i++);
}
