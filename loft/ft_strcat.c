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

char	*ft_strcat(char *des, const char *src)
{
        int    i;
        int    j;

        i = 0;
        j = 0;
        while (des[i])
            i++;
        while (src[j])
        {
            des[i + j] = src[j];
            j++;
        }
        des[i + j] = 0;
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
            const int       max = 64;
            char            des_com[max], des_usr[max];
            char            src[max];
            int             len_src, len_des;

            ft_putstr("enter src : ");
            fgets(src, max, stdin);
            len_src = strlen(src);
            src[ len_src - 1 ] = '\0';
            ft_putstr("enter dst : ");
            fgets(des_com, max, stdin);
            len_des = strlen(des_com);
            des_com[ len_des - 1 ] = '\0';
            strcpy(des_usr, des_com);
            LOAD;
            printf("-- compare two results --\n");
            strcat(des_com, src);
            ft_strcat(des_usr, src);
            printf("comp : %s\n", des_com);
            printf("user : %s\n", des_usr);
            memset(src, 0, max);
            memset(des_com, 0, max);
            memset(des_usr, 0, max);
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
