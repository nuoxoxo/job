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

int     ft_strnequ(char const *s1, char const *s2, size_t n)
{
        if (!s1 && !s1)
            return (0);
        if (!s1 || !s2)
            return (1);
        if (!ft_strncmp(s1, s2, n))
            return (0);
        return (1);
}

/*

//  DRIVE

#include "ft_strncmp.c"
#include "ft_putnbr.c"
#include "ft_putstr.c"
#include "ft_putendl.c"
#include "ft_putchar.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int	main(void)
{
        const int   max = 512;
        char        s1[max];
        char        s2[max];
        size_t      nc;
        int         n;

        while (1)
        {
            ft_putstr("Enter s1 : ");
            fgets(s1, max, stdin);
            ft_putstr("Enter s2 : ");
            fgets(s2, max, stdin);
            do
            {
                ft_putstr("Enter n  : ");
                scanf("%i", &n);
            }
            while (n < 0 || n > 64);
            LOAD;
            ft_putstr("$ strnequ result : ");
            ft_putnbr(ft_strnequ(s1, s2, n));
            ft_putchar('\n');
            ft_putstr("$ strncmp result : ");
            nc = strncmp(s1, s2, n);
            ft_putnbr(nc);
            ft_putstr(" ---> strnequ should be ");
            nc = nc ? 1 : 0;
            ft_putchar(nc + '0');
            OUT;
            fflush(stdin);
        }

        return (0);
}

//

void    loading(void)
{
        int     rand;

        rand = 1000 * 32;
        ft_putstr("loading");
        for (int i = 12; i > 0; i--)
        {
            usleep(rand);
            ft_putstr(".");
        }
        ENDL;
}

*/
