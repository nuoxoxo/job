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

int     ft_tolower(int c)
{
        if (c <= 'Z' && c >= 'A')
            c += 'a' - 'A';
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
            ft_putstr("char lowered : ");
            ft_putchar(ft_tolower(c));
            ft_putchar('\n');
            fflush(stdin);
        }

        return (0);
}

*/
