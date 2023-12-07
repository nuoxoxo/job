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

char	*ft_strcpy(char *des, const char *src)
{
	char	*tmp;

	tmp = des;
	while (*src)
            *tmp++ = *src++;
	*tmp = '\0';
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
            int     max = 64;
            char    src[max], des_ft[max], des_lib[max];
            
            ft_putstr("source : ");
            fgets(src, max, stdin);
            ft_putstr("target : ");
            fgets(des_ft, max, stdin);
            src[ft_strlen(src) - 1] = des_ft[ft_strlen(des_ft) - 1] = 0;
            strcpy(des_lib, des_ft);
            ft_strcpy(des_ft, src);
            strcpy(des_lib, src);
            LOAD;
            ft_putstr("strcpy : ");
            ft_putendl(des_lib);
            ft_putstr("libft  : ");
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
