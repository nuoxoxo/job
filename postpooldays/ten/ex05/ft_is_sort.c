/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     is_ordered(int *a, int s, int i, int len, int(*f)(int, int));

int     ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int main;
    int fork;
    int i;

    if (length < 1) return (0);
    if (length == 1 || length == 2) return (1);
    main = f(tab[0], tab[1]);
    i = 2;
    if (main == 0)
    {
        while (i < length && f(tab[i - 1], tab[i]) == 0)
            i++;
        if (i == length) return (1);
        fork = f(tab[i - 1], tab[i]);
        return (is_ordered(tab, fork, i, length, f));
    }
    return (is_ordered(tab, main, i, length, f));
}

int     is_ordered(int *arr, int sign,\
        int index, int length, int(*f)(int, int))
{
    int i;

    i = index;
    while (i < length)
    {
        if ((sign < 0 && f(arr[i - 1], arr[i]) > 0)
            || (sign > 0 && f(arr[i - 1], arr[i]) < 0))
            return (0);
        i++;
    }
    return (1);
}

/*

// DRIVE

#include <stdio.h>

int     diff(int a, int b);

int     main()
{
        int arr_1[] = {0, 1, 2, 3};
        printf("{0,1,2,3} : %i\n", ft_is_sort(arr_1, 4, &diff));
        int arr_2[] = {3, 2, 1, 0};
        printf("{3,2,1,0} : %i\n", ft_is_sort(arr_2, 4, &diff));
        int arr_3[] = {2, 2, 10};
        printf("{2,2,10} : %i\n", ft_is_sort(arr_3, 3, &diff));
        int arr_4[] = {};
        printf("{} : %i\n", ft_is_sort(arr_4, 0, &diff));
        int arr_5[] = {21};
        printf("{21} : %i\n", ft_is_sort(arr_5, 1, &diff));
        int arr_6[] = {21, 21};
        printf("{21,21} : %i\n", ft_is_sort(arr_6, 2, &diff));
        int arr_7[] = {2, 2, 1, 2};
        printf("{2,2,1,2} : %i\n", ft_is_sort(arr_7, 4, &diff));
        int arr_8[] = {-2, -2, -10, -2};
        printf("{-2,-2,-10,-2} : %i\n", ft_is_sort(arr_8, 4, &diff));
        int arr_9[] = {-2, 1, 2, 2, 3, 3, 4, 5, 6, 6, 10, 10};
        printf("{-2,1,2,2,3,3,4,5,6,6,10,10} : %i\n",\
            ft_is_sort(arr_9, 12, &diff));
        int arr_10[] = {-2, 1, 2, 2, 3, 3, 4, 5, 6, 6, 12, 11};
        printf("{-2,1,2,2,3,3,4,5,6,6,12,11} : %i\n",\
            ft_is_sort(arr_10, 12, &diff));
}

int     diff(int a, int b)
{
        return (a - b);
}

*/
