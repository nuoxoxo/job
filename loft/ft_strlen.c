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

size_t  ft_strlen(const char *s)
{
        int     i;

        i = 0;
        while (s[i])
            i++;
        return (i);
}

/*

//  DRIVE

#include "ft_putendl.c"
#include "ft_putchar.c"
#include "ft_putstr.c"
#include "ft_putnbr.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        const int   max = 128;
        while (1)
        {
            char    s[max];
            ft_putstr("Enter a phrase : ");
            fgets(s, max, stdin);
            s[ft_strlen(s) - 1] = 0;
            LOAD;
            ft_putstr("strlen : ");
            ft_putnbr(ft_strlen(s));
            ft_putchar('\n');
            fflush(stdin);
            OUT;
        }

        return (0);
}

void    loading(void)
{
        int     rand;

        rand = 1000 * 32;
        ft_putstr("printing");
        for (int i = 12; i > 0; i--)
        {
            usleep(rand);
            ft_putstr(".");
        }
        ENDL;
}

*/
