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

void    ft_putstr(char const *s)
{
        while (*s)
            write(1, s++, 1);
}

/*

//  DRIVE

#include <stdio.h>

int     main(void)
{
    char    s[64];

    while (1)
    {
        ft_putstr("Type something : ");
        fgets(s, 64, stdin);
        ft_putstr("You have typed : ");
        ft_putstr(s);
        fflush(stdin);
    }

    return (0);
}

*/
