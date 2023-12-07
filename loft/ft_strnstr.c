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

char    *ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t		i;
	size_t		j;

	if (ft_strlen(to_find) == 0)
            return ((char *) str);
        i = -1;
	while (str[++i])
	{
            j = 0;
	    while (str[i + j] == to_find[j] && i + j < n)
            {
                j++;
		if (j == ft_strlen(to_find))
                    return ((char *) &str[i]);
	    }
	}
	return (0);
}

/*

//  DRIVE

#include <string.h>
#include <stdio.h>
#include "ft_putendl.c"
#include "ft_putstr.c"

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int	main(void)
{
        while (1)
        {
            int     max = 64;
            char    hays[max];
            char    need[max];
            int     n;

            fflush(stdin);
            ft_putstr("haystack : ");
            fgets(hays, max, stdin);
            fflush(stdin);
            ft_putstr("needle   : ");
            fgets(need, max, stdin);
            fflush(stdin);
            ft_putstr("size     : ");
            scanf("%i", &n);
            hays[ft_strlen(hays) - 1] = 0;
            need[ft_strlen(need) - 1] = 0;
            LOAD;
            printf("string.h : %s\n", strnstr(hays, need, n));
            printf("libft.h  : %s\n", ft_strnstr(hays, need, n));
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
