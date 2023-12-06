/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_cal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_utils.h"
#include "ft_opp.h"

void    calc(int L, int R, char *c)
{
    int i;

    if (R == 0)
    {
        if (ft_strcmp(c, "/") == 0)
        {
            write(1, "Stop : division by zero", 23);
            return ;
        }
        else if (ft_strcmp(c, "%") == 0)
        {
            write(1, "Stop : modulo by zero", 21);
            return ;
        }
    }
    
    i = 0;
    while (g_opptab[i].op)
    {
        if (ft_strcmp(c, g_opptab[i].op) == 0)
        {
            ops(L, R, g_opptab[i].fn);
            return ;
        }
        i++;
    }
    ft_usage(L, R);
    return ;
}

void    ops(int a, int b, void(*f)(int, int))
{
        return (f(a, b));
}

int     ft_strcmp(char *a, char *b)
{
        int i;
        
        i = 0;
        while (a[i] && b[i] && a[i] == b[i])
            i++;
        return (a[i] - b[i]);
}
