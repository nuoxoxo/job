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

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	        i++;
	return (s1[i] - s2[i]);
}

/*

//  DRIVE

#include "ft_putendl.c"
#include "ft_putchar.c"
#include "ft_putstr.c"
#include "ft_putnbr.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int	main(void)
{
        while (1)
        {
            const int   max = 512;
            char        s1[max];
            char        s2[max];

            ft_putstr("Enter s1 : ");
            fgets(s1, max, stdin);
            fflush(stdin);
            ft_putstr("Enter s2 : ");
            fgets(s2, max, stdin);
            fflush(stdin);
            LOAD;
            ft_putstr("libft    : ");
            ft_putnbr(ft_strcmp(s1, s2));
            ft_putendl("");
            ft_putstr("standard : ");
            ft_putnbr(strcmp(s1, s2));
            OUT;
        }

        return (0);
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
