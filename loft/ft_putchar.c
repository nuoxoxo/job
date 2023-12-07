/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ___ <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_putchar(char c)
{
        write(1, &c, 1);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include <stdio.h>

int     main(void)
{
    char    c;

    while (1)
    {
        ft_putstr("Enter one character : ");
        scanf("%c", &c);
        ft_putstr("Let's put this char : ");
        ft_putchar(c);
        ft_putchar('\n');
        fflush(stdin);
    }

    return (0);
}

*/
