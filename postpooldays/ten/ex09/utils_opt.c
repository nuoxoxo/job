/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_opt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void    putlong(long n);

void    ft_add(int a, int b)
{
        long    n;

        n = a + b;
        putlong(n);
}

void    ft_sub(int a, int b)
{
        long    n;

        n = a - b;
        putlong(n);
}

void    ft_div(int a, int b)
{
        long    n;

        n = a / b;
        putlong(n);
}

void    ft_mul(int a, int b)
{
        long    n;

        n = a * b;
        putlong(n);
}

void    ft_mod(int a, int b)
{
        long    n;

        n = a % b;
        putlong(n);
}
