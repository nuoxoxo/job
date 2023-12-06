/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ops(int a, int b, void(*f)(int, int));
void    calc(int a, int b, char c);
void    putlong(long n);
void    ft_mult(int a, int b);
void    ft_add(int a, int b);
void    ft_sub(int a, int b);
void    ft_div(int a, int b);
void    ft_mod(int a, int b);
int     ft_atoi(char *s);

int     main(int argc, char **argv)
{
        char    c;
        int     L;
        int     R;

        if (argc != 4)
                return (0);
        c = *argv[2];
        L = ft_atoi(argv[1]);
        R = ft_atoi(argv[3]);
        calc(L, R, c);
        write(1, "\n", 1);
        return (0);
}

void    calc(int L, int R, char c)
{
    int n;

    n = 0;
    if (R == 0 && (c == '/' || c == '%'))
    {
        if (c == '/')
            write(1, "Stop : division by zero", 23);
        if (c == '%')
            write(1, "Stop : modulo by zero", 21);
        return ;
    }
    if (c == '+')
        ops(L, R, &ft_add);
    else if (c == '-')
        ops(L, R, &ft_sub);
    else if (c == '*')
        ops(L, R, &ft_mult);
    else if (c == '/')
        ops(L, R, &ft_div);
    else if (c == '%')
        ops(L, R, &ft_mod);
    else
        write(1, "0", 1);
}

void    ops(int a, int b, void(*f)(int, int))
{
        return (f(a, b));
}
