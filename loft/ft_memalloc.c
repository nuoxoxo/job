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

void    *ft_memalloc(size_t size)
{
        void    *p;

        if (size < 1)
            return (NULL);
        p = (void *) malloc(size);
        if (!p)
            return (NULL);
        ft_memset(p, 0, size);
        return (p);
}

/*

#include "ft_bzero.c"

void    *ft_memalloc(size_t size)
{
        void    *p;

        if (size < 1)   return (NULL);
        p = (void *) malloc(size);
        if (!p) return (NULL);
        ft_bzero(p, size);
        return (p);
}

*/


//  DRIVE

/*

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

#include "ft_memset.c"
#include "ft_putstr.c"
#include "ft_putendl.c"
#include <stdio.h>

void    loading(void);

int     main(void)
{
        void    *mem;
        int     i;

        mem = NULL;
        while (1)
        {
            ft_putstr("enter a size (between 1 - 32 incl.): ");
            scanf("%i", &i);
            i = i > 32 ? 32 : i;
            mem = ft_memalloc(i);
            LOAD;
            while (--i > -3)
                printf("%i : %p\n", i, &mem[i]);
            free(mem);
            OUT;
            fflush(stdin);
            ft_putendl("--");
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
