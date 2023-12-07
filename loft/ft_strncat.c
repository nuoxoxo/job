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

char	*ft_strncat(char *des, const char *src, size_t n)
{
        size_t    i;
        size_t    j;

        i = 0;
        j = 0;
        while (des[i])
            i++;
        while ((src[j]) && j < n)
        {
            des[i] = src[j];
            i++;
            j++;
        }
        des[i] = 0;
        return (des);
}

/*

//  DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        while (1)
        {
            const int   max = 64;
            char        des_com[max], des_usr[max];
            int         len_src, len_des;
            char        src[max];
            size_t      size;

            ft_putstr("enter src : ");
            fgets(src, max, stdin);
            len_src = strlen(src);
            src[ len_src - 1 ] = '\0';
            ft_putstr("enter dst : ");
            fgets(des_com, max, stdin);
            len_des = strlen(des_com);
            des_com[ len_des - 1 ] = '\0';
            ft_putstr("enter n   : ");
            scanf("%zi", &size);
            strcpy(des_usr, des_com);
            strncat(des_com, src, size);
            ft_strncat(des_usr, src, size);
            LOAD;
            printf("-- compare results --\n");
            printf("stdlib  : %s\n", des_com);
            printf("my lib  : %s\n", des_usr);
            fflush(stdin);
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
