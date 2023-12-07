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

char    *ft_strchr(const char *s, int c)
{
	int         i;
	
        if (!c)
            return (0);
        i = -1;
	while (s[++i])
	{
            if (s[i] == c)
                return ((char *) &s[i]);
	}
	return (0);
}

/*

//  DRIVE

#include <string.h>
#include <stdio.h>
#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int	main(void)
{
        while (1)
        {
            int     max = 64;
            char    str[max];
            char    chr;

            fflush(stdin);
            ft_putstr("enter str    : ");
            fgets(str, max, stdin);
            fflush(stdin);
            ft_putstr("enter chr    : ");
            scanf("%c", &chr);
            LOAD;
            ft_putendl("--");
            str[ft_strlen(str) - 1] = 0;
            printf("ft_strchr   : %s\n", ft_strchr(str, chr));
            printf("string.h    : %s\n", strchr(str, chr));
            OUT;
        }
}

//

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
