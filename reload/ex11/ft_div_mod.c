/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nuo  <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 09:23:56 by nuo               #+#    #+#             */
/*   Updated: 2021/08/07 09:24:18 by nuxu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*

//DRIVE

#include <stdio.h>

void    ft_div_mod(int one, int two, int *hello, int *world);

int     main()
{
        int a = 5;
        int b = 2;
        int x, y;
        ft_div_mod(a, b, &x, &y);
        printf("%i / %i = %i\n%i %% %i = %i",a,b,x,a,b,y);
}

*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
