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

//      memcmp does not stop comparing after a null character unlike strcmp

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
        while (*(unsigned char *) s1 == *(unsigned char *) s2 && --n)
        {
            s1++;
            s2++;
        }
        return (*(unsigned char *) s1 - *(unsigned char *) s2);
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
        while (1)
        {
            int     max = 32, i;
            char    s1[max], s2[max];

            fflush(stdin);
            ft_putstr("enter string s1  : ");
            fgets(s1, max, stdin);
            s1[ ft_strlen(s1) - 1 ] = 0;
            fflush(stdin);
            ft_putstr("enter string s2  : ");
            fgets(s2, max, stdin);
            s2[ ft_strlen(s2) - 1 ] = 0;
            fflush(stdin);
            ft_putstr("enter range n    : ");
            scanf("%i", &i);
            LOAD;
            printf("ft_memcmp   : %i\n", ft_memcmp(s1, s2, i));
            printf("memcmp      : %i\n", memcmp(s1, s2, i));
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
