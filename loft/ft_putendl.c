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

void    ft_putendl(char const *s)
{
        if (!s)
            return ;
        while (*s)
            write(1, s++, 1);
        write(1, "\n", 1);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include <stdio.h>

int main()
{
    char    s[64];

    while (1)
    {
        ft_putstr("Type something : ");
        fgets(s, 64, stdin);
        usleep(600000);
        ft_putstr("You");
        usleep(600000);
        ft_putstr(" have");
        usleep(600000);
        ft_putstr(" typed");
        usleep(600000);
        ft_putstr(" : ");
        ft_putendl(s);
        fflush(stdin);
    }

    return (0);
}

*/
