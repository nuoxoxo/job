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

//  calloc() reserves storage space for an array of count elements, 
//  each of length size bytes. 
//  all the bits of each element have an initial value of 0.

void    *ft_calloc(size_t count, size_t size)
{
        unsigned char   *p;

        if (!count || !size)
            return (NULL);
        if (!(p = malloc(count * size)))
            return (NULL);
        ft_bzero(p, count * size);
        return (p);
}

/*

//  DRIVE

#include "ft_bzero.c"
#include "ft_putstr.c"
#include "ft_putendl.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        unsigned char*  mem;
        size_t          size;
        size_t          count;
        int             flag = 0;

        while (1)
        {
            printf("enter count : ");
            scanf("%lu", &count);
            printf("enter size : ");
            scanf("%lu", &size);
            mem = ft_calloc(count, size);
            LOAD;
            if (!flag)
            {
                printf("%p\n\n", mem);
                flag++;
            }
            else
            {
                printf("memory is freed and when allocated : \n\n");
                printf("%p\n", mem);
            }
            OUT;
            free(mem);
            fflush(stdin);
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
