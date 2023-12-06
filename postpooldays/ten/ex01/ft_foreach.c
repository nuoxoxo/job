/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    ft_foreach(int *tab, int length, void(*f)(int))
{
        int     i;

        i = 0;
        while (i < length)
        {
                f(tab[i]);
                i++;
        }
}

/*

// DRIVE

#include <unistd.h>

void    put_one_positive_digit_and_break(int n);

int     main()
{
        int     arr[] = {0, 9, 2, 7, 4, 6, 3, 5, 1, 8};
        ft_foreach(arr, 10, &put_one_positive_digit_and_break);
}

void    put_one_positive_digit_and_break(int n)
{
        char    c;
        if (n < 10 && n >= 0)
        c = n % 10 + '0';write(1, &c, 1);write(1, "\n", 1);
}

*/
