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

void    *ft_memcpy(void *des, const void *src, size_t n)
{
        unsigned char   *ptr;

        ptr = des;
        while (n)
        {
            *ptr = *(unsigned char *) src;
            ptr++;
            src++;
            n--;
        }
        return (des);
}

/*

//      DRIVE

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include <stdio.h>

void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 32, i;
            char    s1[max], s2[max];

            ft_putstr("enter s1 : ");
            fgets(s1, max, stdin);
            s1[ft_strlen(s1) - 1] = 0;
            ft_putstr("enter s2 : ");
            fgets(s2, max, stdin);
            s2[ft_strlen(s2) - 1] = 0;
            ft_putstr("enter n  : ");
            scanf("%i", &i);
            LOAD;
            printf("ft_memcpy   : %s\n", (char *) ft_memcpy(s1, s2, i));
            printf("memcpy      : %s\n", (char *) memcpy(s1, s2, i));
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
