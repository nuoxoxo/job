/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ___ <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int     ft_isdigit(int c)
{
        if (c > '9' || c < '0')
            return (0);
        return (1);
}

/*

#include "ft_putendl.c"
#include <stdio.h>

//  DRIVE

int     main(void)
{
        char    c;

        while (1)
        {
            ft_putendl("Enter a byte : ");
            scanf("%c", &c);
            if (!ft_isdigit(c)) ft_putendl("NO");
            else                ft_putendl("YES");
            fflush(stdin);
        }

        return (0);
}

*/
