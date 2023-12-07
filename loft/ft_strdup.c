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

//      ft_strlen

char	*ft_strdup(const char *src)
{
	char    *ptr;
	char	*des;
	int     len;

	if (!src)
            return (NULL);
        len = ft_strlen(src);
        des = malloc(sizeof(char) * (len + 1));
	ptr = des;
	if (!des)
	    return (NULL);
	while (*src)
	    *des++ = *src++;
	*des = '\0';
	return (ptr);
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

int     main()
{
        const int   max = 512;
        while (1)
        {
            char    src[max];
            char    *des;

            ft_putstr("Enter something  : ");
            fgets(src, max, stdin);
            src[ft_strlen(src) - 1] = 0;
            LOAD;
            des = ft_strdup(src);
            ft_putstr("strdup   : ");
            ft_putendl(des);
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
