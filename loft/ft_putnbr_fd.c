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

void    ft_putnbr_fd(int num, int fd)
{
        unsigned int    n;
        char            c;

        n = num;
        if (num < 0)
        {
            write(fd, "-", 1);
            n *= -1;
        }
        if (n > 9)
            ft_putnbr(n / 10);
        c = n % 10 + 48;
        write(fd, &c, 1);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include "ft_putnbr.c"
#include <stdio.h>

int     main(void)
{
    char    *s = "Usage: a displayable fd should be either 1 or 2";

    while (1)
    {
        int     i;
        int     f;
        ft_putstr("integer : ");
        scanf("%i", &i);
        ft_putstr("your fd : ");
        scanf("%i", &f);
        if (f != 1 && f != 2)
            ft_putstr(s);
        else
        {
            ft_putstr("display : ");
            ft_putnbr_fd(i, f);
        }
        ft_putstr("\n--\n");
        fflush(stdin);
    }
}

*/
