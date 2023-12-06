/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_usage(char *c)
{
    write(1, "error : only [ - + * / % ] are accepted.", 40);
    return ;
}

int     ft_atoi(char *s)
{
    int sign = 1;
    int tt, i;
    
    tt = i = 0;
    while (s[i] == ' ' || (s[i] < 14 && s[i] > 8))
        i++;
    if (s[i] == '-' || s[i] == '+')
    {
        if (s[i] == '-')    sign *= -1;
        i++;
    }
    while (s[i] <= '9' && s[i] >= '0')
    {
        tt = tt * 10 + s[i] - '0';
        i++;
    }
    return (sign * tt);
}

void    putlong(long n)
{
    char    c;

    if (n < 0)
    {
        n *= -1;
        write(1, "-", 1);
    }
    if (n < 10 && n >= 0)
    {
        c = n + '0';
        write(1, &c, 1);
    }
    else
    {
        putlong(n / 10);
        c = n % 10 + '0';
        write(1, &c, 1);
    }
}
