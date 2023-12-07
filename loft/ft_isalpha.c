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

int     ft_isalpha(int c)
{
        if ((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A'))
            return (1);
        return (0);
}

/*

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
            if (!ft_isalpha(c)) ft_putendl("No");
            else                ft_putendl("Yes");
            fflush(stdin);
        }

        return (0);
}

*/
