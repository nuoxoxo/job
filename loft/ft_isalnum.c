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

int     ft_isalnum(int c)
{
        if (ft_isalpha(c) || ft_isdigit(c))
            return (1);
        return (0);
}

/*

#include "ft_putendl.c"
#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include <stdio.h>

//  DRIVE

int     main(void)
{
        char    c;

        while (1)
        {
            ft_putendl("Enter a byte : ");
            scanf("%c", &c);
            if (!ft_isalnum(c)) ft_putendl("not alnum");
            else                ft_putendl("is alnum");
            fflush(stdin);
        }

        return (0);
}

*/
