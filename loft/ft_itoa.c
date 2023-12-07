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

int     digit_count(long n);

char    *ft_itoa(int n)
{
        char    *res;
        long    num;
        int     i;

        if (!n)
            return ("0");
        num = n;
        i = digit_count(num);
        res = (char *) malloc(sizeof(char) * (i + 1));
        if (!res)
            return (NULL);
        res[i--] = 0;
        if (num < 0)
        {
            res[0] = '-';
            num *= -1;
        }
        while (num)
        {
            res[i] = num % 10 + '0';
            num /= 10;
            i--;
        }
        return (res);
}

int     digit_count(long n)
{
        int     i;

        i = 0;
        if (n < 0)
        {
            n *= -1;
            i += 1;
        }
        while (n)
        {
            i++;
            n /= 10;
        }
        return (i);
}

/*

//  DRIVE

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

#include "ft_putendl.c"
#include "ft_putstr.c"
#include <stdio.h>
#include <errno.h>

void    loading(void);

int     main(void)
{
        
        while (1)
        {
            long    num;
            int     fd;

            ft_putstr("enter an int : ");
            fd = scanf("%ld", &num);
            LOAD;
            if (fd == 1)
                printf("testing itoa : %s\n", ft_itoa(num));
            else
                printf("\n%s\nPlease try again ...\n", strerror(errno));
            fflush(stdin);
            OUT;
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
