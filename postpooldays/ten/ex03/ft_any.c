/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuxu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 10:46:48 by nuxu              #+#    #+#             */
/*   Updated: 2021/08/12 11:43:02 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int     ft_any(char **tab, int(*f)(char*))
{
        int     i = 0;
        while   (tab[i])
        {
                if (f(tab[i]) == 1)
                        return (1);
                i++;
        }
        return (0);
}

/*

// DRIVE

#include <stdio.h>

int     is_len_even(char *s)
{
        int     i = 0;
        if (!s) return 0;
        while (s[i])    i++;
        if (!(i % 2))     return 1;
        return 0;
}

int     main(int argc, char **argv)
{
        (void)  argc;
        printf("%i\n", ft_any(argv, &is_len_even));
}

*/
