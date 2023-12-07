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

char*   ft_strsub(char const *str, unsigned int start, size_t size)
{
        size_t  i;
        size_t  len;
        char*   sub;

        if (!str)
            return (NULL);
        len = ft_strlen(str);
        if (!len || len < size || len < start)
            return (NULL);
        sub = (char *) malloc(len + 1);
        if (!sub)
            return (NULL);
        i = 0;
        while (i < size && i < len)
            sub[i++] = str[start++];
        sub[i] = 0;
        return (&sub[0]);
}

/*

//      DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include "stdio.h"

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 32, start, size;
            char    s[max];

            ft_putstr("enter string : ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            fflush(stdin);
            ft_putstr("enter start  : ");
            scanf("%i", &start);
            fflush(stdin);
            ft_putstr("enter size   : ");
            scanf("%i", &size);
            fflush(stdin);
            LOAD;
            ft_putstr("result : ");
            ft_putendl(ft_strsub(s, start, size));
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
