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

void    ft_bzero(void *s, size_t n)
{
        ft_memset(s, 0, n);
}

/*

//  DRIVE

#include "ft_memset.c"
#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        int     max = 64;
        char    s[max];

        while (1)
        {
            ft_putstr("enter string : ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            LOAD;
            ft_putstr("your string  : ");
            ft_putendl(s);
            printf("address      : %p\n", &s);
            ft_bzero(s, max);
            ft_putstr("after bzero  : ");
            ft_putendl(s);
            printf("address      : %p\n", &s);
            fflush(stdin);
            OUT;
        }

        return (0);
}

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
