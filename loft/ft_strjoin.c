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

//      ft_strcpy
//      ft_strcat
//      ft_strlen

char*   ft_strjoin(char const *prefix, char const *suffix)
{
        size_t      len;
        char*       res;

        if (!prefix || !suffix)
            return (NULL);
        len = ft_strlen((char *) prefix) + ft_strlen((char *) suffix) + 1;
        res = (char *) malloc(sizeof(char *) * len);
        if (!res)
            return (NULL);
        ft_strcpy(res, (char *) prefix);
        ft_strcat(res, (char *) suffix);
        return (res);
}

/*

//      DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include "ft_strcpy.c"
#include "ft_strcat.c"
#include "stdio.h"

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 64;
            char    prefix[max], suffix[max], *s;

            fflush(stdin);
            ft_putstr("Enter the left part  : ");
            fgets(prefix, max, stdin);
            prefix[ft_strlen(prefix) - 1] = 0;
            fflush(stdin);
            ft_putstr("Enter the right part : ");
            fgets(suffix, max, stdin);
            suffix[ft_strlen(suffix) - 1] = 0;
            LOAD;
            s = ft_strjoin(prefix, suffix);
            ft_putendl(s);
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
