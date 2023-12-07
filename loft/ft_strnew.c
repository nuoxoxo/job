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

char    *ft_strnew(size_t size)
{
        return ((char *) ft_memalloc(size));
}

/*

//  DRIVE - same test as ft_memalloc

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

#include "ft_memalloc.c"
#include "ft_putendl.c"
#include "ft_putstr.c"
#include <stdio.h>

void    loading(void);

int     main(void)
{
        char    *str;
        int     i;

        str = NULL;
        while (1)
        {
            ft_putstr("enter a size (between 1 - 32 incl.): ");
            scanf("%i", &i);
            i = i > 32 ? 32 : i;
            str = ft_strnew(i);
            LOAD;
            while (--i > -3)    printf("%i : %p\n", i, &str[i]);
            fflush(stdin);
            free(str);
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
