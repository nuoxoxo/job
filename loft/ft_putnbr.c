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

void    ft_putnbr(int num)
{
        unsigned int    n;
        char            c;

        n = num;
        if (num < 0)
        {
            write(1, "-", 1);
            n *= -1;
        }
        if (n >= 10)
            ft_putnbr(n / 10);
        c = n % 10 + 48;
        write(1, &c, 1);
}

/*

//  DRIVE

#include "ft_putstr.c"
#include <stdio.h>

int     main()
{
        while (1)
        {
            long    li;
            ft_putstr("Enter an integer : ");
            scanf("%li", &li);
            ft_putstr("Here is your int : ");
            ft_putnbr(li);
            ft_putstr("\n--\n");
            fflush(stdin);
        }

        return (0);
}

*/
