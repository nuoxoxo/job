/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int     *ft_map(int *tab, int length, int(*f)(int))
{
        int     *arr;
        int     i;
        arr = malloc(sizeof(int) * length);
        if (!arr)
                return (NULL);
        i = 0;
        while (i < length)
        {
            arr[i] = f(tab[i]);
            i++;
        }
        return (arr);
}

/*

#include <stdio.h>

int     f_modulo(int n)
{
        int     num = n % 10;
        return  num;
}

// DRIVE

int     main()
{
        int     tab[] = {0, -81, 512, -1024, 2147483647, -2147483648};
        int     *arr = ft_map(tab, 6, f_modulo);
        int     i = 0;
        while (i < 6)
        {
            printf("%i  =  %i %% 10\n", arr[i], tab[i]);
            i++;
        }
}

*/
