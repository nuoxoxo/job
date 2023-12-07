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

void    *ft_memchr(const void *s, int c, size_t n)
{
        unsigned char   *p;
        size_t          i;

        p = (unsigned char *) s;
        i = 0;
        while (*p && i < n)
        {
            if (*p == c)
                return (p);
            p++;
            i++;
        }
        return (NULL);
}

/*

//  DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include "ft_bzero.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        int     max = 64;
        int     i;
        char    s[max];
        char    c;

        while (1)
        {
            ft_putstr("enter string : ");
            fgets(s, max, stdin);
            s[ft_strlen(s) - 1] = 0;
            ft_putstr("enter a char : ");
            scanf("%c", &c);
            ft_putstr("enter a size : ");
            scanf("%i", &i);
            LOAD;
            printf("ft_memchr : %s\n", ft_memchr(s, c, i));
            printf("memchr    : %s\n", memchr(s, c, i));
            ft_bzero(s, 0);
            fflush(stdin);
            OUT;
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
