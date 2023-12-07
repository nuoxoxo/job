/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo  <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 10:36:57 by nuo               #+#    #+#             */
/*   Updated: 2021/08/10 14:12:54 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*

// Drive

void    ft_putstr(char *s);

int     main(int chartreuse, char **gribouillage)
{
    (void)  chartreuse;
    ft_putstr(gribouillage[1]);
}

*/

void	ft_putstr(char *str)
{
    if (str)
    {
        while (*str)
            write(1, str++, 1);
    }
}
