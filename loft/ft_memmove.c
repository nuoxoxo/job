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

//      memmove copies n characters from str2 to str1
//      memmove is safer than memcpy for overlapping memory blocks

#include "libft.h"

void	*ft_memmove(void *des, const void *src, size_t size)
{
        void    *ptr;

        if (!des || !src || !size)
            return (NULL);
        ptr = des;
        if (ptr == src)
            return (ptr);
        else if (ptr < src)
        {
            while (size)
            {
                *(unsigned char *) des = *(unsigned char *) src;
                des++;
                src++;
                size--;
            }
        }
        else
        {
            des += size - 1;
            src += size - 1;
            while (size)
            {
                *(unsigned char *) des = *(unsigned char *) src;
                des--;
                src--;
                size--;
            }
        }
        return (ptr);
}

/*

//      DRIVE

#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 32, i;
            char    s1[max], s2[max];

            ft_putstr("enter s1 : ");
            fgets(s1, max, stdin);
            s1[ft_strlen(s1) - 1] = 0;
            ft_putstr("enter s2 : ");
            fgets(s2, max, stdin);
            s2[ft_strlen(s2) - 1] = 0;
            ft_putstr("enter n  : ");
            scanf("%i", &i);
            LOAD;
            printf("ft_memmove  : %s\n", (char *) ft_memmove(s1, s2, i));
            printf("memmove     : %s\n", (char *) memmove(s1, s2, i));
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
