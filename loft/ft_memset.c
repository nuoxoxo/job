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

void    *ft_memset(void *destination, int c, size_t n)
{
        unsigned char   *des;

        des = destination;
        while (n--)
        {
            *(unsigned char*) des = (unsigned char) c;
            des++;
        }
        return (destination);
}

/*

//  DRIVE

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
        const int   max = 64;
        char        s[max];

        while (1)
        {
            ft_putstr("type words : ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            LOAD;
            ft_putstr("words typed  : ");
            ft_putendl(s);
            printf("address: %p\n", &s);
            ft_putstr("after memset : ");
            ft_memset(s, 0, max);
            ft_putendl(s);
            printf("address: %p\n", &s);
            OUT;
            fflush(stdin);
        }
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
