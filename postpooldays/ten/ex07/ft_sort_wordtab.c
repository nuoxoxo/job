/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_wordtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_strcmp(char *a, char *b);

void    ft_sort_wordtab(char **tab)
{
    char    *tmp;
    int     counter;
    int     i;

    if (!tab[1])
        return ;
    counter = -1;
    while (counter != 0)
    {
        i = 1;
        counter = 0;
        while (tab[i])
        {
            if (ft_strcmp(tab[i - 1], tab[i]) > 0)
            {
                tmp = tab[i - 1];
                tab[i - 1] = tab[i];
                tab[i] = tmp;
                counter += 1;
            }
            i++;
        }
    }
}

int     ft_strcmp(char *a, char *b)
{
    int i;

    i = 0;
    while (a[i] && b[i] && a[i] == b[i])
        i++;
    return (a[i] - b[i]);
}

/*

// DRIVE

#include <stdio.h>

void    ft_sort_wordtab(char **arr);
int     ft_strcmp(char *a, char *b);


int     main(int argc, char **argv)
{
        int i = 0;
        while (i < argc) printf("%s\n", argv[i++]);
        printf("\n");
        ft_sort_wordtab(argv);
        i = 0;
        while (i < argc) printf("%s\n", argv[i++]);
}

*/
