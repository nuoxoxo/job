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

int     ft_toupper(int c)
{
        if (c <= 'z' && c >= 'a')
            c -= 'a' - 'A';
        return (c);
}

/*

#include "ft_putchar.c"
#include "ft_putstr.c"
#include <stdio.h>

//  DRIVE

int     main(void)
{
        char    c;

        while (1)
        {
            ft_putstr("Enter a char : ");
            scanf("%c", &c);
            ft_putstr("char uppered : ");
            ft_putchar(ft_toupper(c));
            ft_putstr("\n--\n");
            fflush(stdin);
        }

        return (0);
}

*/
