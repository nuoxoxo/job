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

void    ft_putchar_fd(char c, int fd)
{
        write(fd, &c, 1);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include <stdio.h>

int     main(void)
{
    char    *msg = "\nusage: a displayable fd should be either 1 or 2";
    char    c;
    int     f;

    while (1)
    {
        ft_putstr("Enter one character : ");
        scanf("%c", &c);
        ft_putstr("Pick a filedescptor : ");
        scanf("%i", &f);
        ft_putstr("Let's put this char : ");
        if (f < 1 || f > 2) ft_putstr(msg);
        else                ft_putchar_fd(c, f);
        ft_putstr("\n--\n");
        fflush(stdin);
    }

    return (0);
}

*/
