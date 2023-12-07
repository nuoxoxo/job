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

char	*ft_strncpy(char *des, const char *src, unsigned int n)
{
	unsigned int	i;

	i = -1;
	while (src[++i] && i < n)
            des[i] = src[i];
        i--;
	while (++i < n)
    	    des[i] = '\0';
	return (des);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include "ft_strlen.c"
#include "ft_putendl.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        while (1)
        {
            int     i;
            int     max = 64;
            char    src[max], des_ft[max], des_lib[max];
            
            ft_putstr("source : ");
            fgets(src, max, stdin);
            ft_putstr("target : ");
            fgets(des_ft, max, stdin);
            src[ft_strlen(src) - 1] = des_ft[ft_strlen(des_ft) - 1] = 0;
            ft_putstr("up to  : ");
            strcpy(des_lib, des_ft);
            scanf("%i", &i);
            ft_strncpy(des_ft, src, i);
            strncpy(des_lib, src, i);
            LOAD;
            ft_putstr("strncpy  : ");
            ft_putendl(des_lib);
            ft_putstr("ft       : ");
            ft_putendl(des_ft);
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
