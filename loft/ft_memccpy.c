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

//      per definition, copy stops when
//      1)  n characters are copied
//      2)  char c is found (and COPIED)

#include "libft.h"

void  *ft_memccpy(void *destination, const void *source, int c, size_t n)
{
        unsigned char   *des;
        unsigned char   *src;


        des = (unsigned char*) destination;
        src = (unsigned char*) source;
        while (n)
        {
            *des = *src;
            des++;
            if (*src == (unsigned char) c)
                return (des);
            src++;
            n--;
        }
        return (NULL);
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
            char    s1[max], s2[max], c;

            ft_putstr("enter src : ");
            fgets(s1, max, stdin);
            s1[ft_strlen(s1) - 1] = 0;
            ft_putstr("enter des : ");
            fgets(s2, max, stdin);
            s2[ft_strlen(s2) - 1] = 0;
            fflush(stdin);
            ft_putstr("enter c  : ");
            c = getchar();
            fflush(stdin);
            ft_putstr("enter n  : ");
            scanf("%i", &i);
            LOAD;
            printf("ft_memccpy  : %s\n", (char *) ft_memccpy(s2, s1, c, i));
            printf("memccpy     : %s\n", (char *) memccpy(s2, s1, c, i));
            ft_putendl("(return: pointer to last char copied.)");
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
