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
#include "ft_strlen.c"

char    *ft_strrchr(const char *s, int c)
{
	int         i;
	

        if (!c)
            return (0);
        i = ft_strlen((char *) s);
	while (s[--i])
	{
            if (s[i] == c)
                return ((char *) &s[i]);
	}
	return (0);
}

/*

//  DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include <string.h>
#include <stdio.h>

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
            chr = getchar();
            LOAD;
            str[ft_strlen(str) - 1] = 0;
            printf("ft_strrchr  : %s\n", ft_strrchr(str, chr));
            printf("string.h    : %s\n", strrchr(str, chr));
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
