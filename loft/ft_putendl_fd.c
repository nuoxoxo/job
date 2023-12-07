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

void    ft_putendl_fd(char const *s, int fd)
{
        if (!s)
            return ;
        while (*s)
            write(fd, s++, 1);
        write(fd, "\n", 1);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include <stdio.h>

int main()
{
    char    warning[] = "\nusage: a displayable should be either 0 or 2\n";
    char    s[64];
    int     f;

    while (1)
    {
        ft_putstr("Type something : ");
        fgets(s, 64, stdin);
        ft_putstr("Choose your fd : ");
        scanf("%i", &f);
        usleep(500000);
        ft_putstr("You");
        usleep(500000);
        ft_putstr(" have");
        usleep(500000);
        ft_putstr(" typed");
        usleep(500000);
        ft_putstr(" : ");
        if (f < 1 || f > 2) ft_putstr(warning);
        else                ft_putendl_fd(s, f);
        fflush(stdin);
    }

    return (0);
}

*/
