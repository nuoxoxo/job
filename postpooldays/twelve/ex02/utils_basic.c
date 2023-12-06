/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void    msg(char *arg, int n)
{
    char    *msg_illegal_offset, *msg_illegal_option;
    char    *msg_option_require, *msg_file, *msg_usage;

    msg_file = "No such file or directory\n";
    msg_usage = "usage: tail [-c #] [file ...]\n";
    msg_illegal_offset = "tail: illegal offset -- ";
    msg_illegal_option = "tail: illegal option -- ";
    msg_option_require = "tail: option requires an argument -- ";
    if (n == 0)
    {
        write(2, "tail: ", 6);
        write(2, arg, len(arg));
        write(2, ": ", 2);
        write(2, msg_file, len(msg_file));
    }
    else if (n == 1)
    {
        write(2, msg_illegal_option, len(msg_illegal_option));
        write(2, &arg[1], 1);
        write(2, "\n", 1);
        write(2, msg_usage, len(msg_usage));
    }
    else if (n == 2)
    {
        write(2, msg_option_require, len(msg_option_require));
        write(2, &arg[1], 1);
        write(2, "\n", 1);
        write(2, msg_usage, len(msg_usage));
    }
    else if (n == 3)
    {
        write(2, msg_illegal_offset, len(msg_illegal_offset));
        write(2, arg, len(arg));
        write(2, "\n", 1);
    }
}

int     atoi_easy(char *s)
{
    int     sign;
    int     tt;
    int     i;

    sign = 1;
    tt = 0;
    i = 0;
    while (s[i] == ' ' || (s[i] < 14 && s[i] > 8))
        i++;
    if (s[i] == '+')
        i++;
    else if (s[i] == '-')
    {
        sign *= -1;
        i++;
    }
    while (s[i] <= '9' && s[i] >= '0')
    {
        tt = tt * 10 + s[i] - '0';
        i++;
    }
    return (sign * tt);
}

int     len(char *s)
{
    int     i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}
