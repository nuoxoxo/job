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

void    ft_putstr_fd(char const *s, int fd)
{
        while (*s)
            write(fd, s++, 1);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include <stdio.h>

int     main(void)
{
    char    *warning = "\nusage: a viewable fd range should be 1 or 2\n";
    char    s[64];
    int     f;

    while (1)
    {
        ft_putstr("Type something : ");
        fgets(s, 64, stdin);
        ft_putstr("Choose your fd : ");
        scanf("%i", &f);
        ft_putstr("You have typed : ");
        if (f < 1 || f > 2) ft_putstr(warning);
        else                ft_putstr_fd(s, f);
        ft_putstr("--\n");
        fflush(stdin);
    }

    return (0);
}

*/
