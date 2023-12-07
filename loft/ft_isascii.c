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

int     ft_isascii(int c)
{
        if (c < 0 || c > 127)
            return (0);
        return (1);
}

/*

//  test diacritics in french

#include "ft_putendl.c"
#include <stdio.h>

//  DRIVE

int     main(void)
{
        char    c;

        while (1)
        {
            ft_putendl("Enter a byte : ");
            scanf("%c", &c);
            if (!ft_isascii(c)) ft_putendl("not ascii");
            else                ft_putendl("is ascii");
            fflush(stdin);
        }

        return (0);
}

*/
