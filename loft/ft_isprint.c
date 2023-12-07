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

int     ft_isprint(int c)
{
        if (c < ' ' || c > '~')
            return (0);
        return (1);
}

/*

//  in terminal press ctrl+v and test a control character

#include "ft_isalpha.c"
#include "ft_isdigit.c"
#include "ft_putendl.c"
#include <stdio.h>

int     main(void)
{
        char    c;

        while (1)
        {
            ft_putendl("Enter a byte : ");
            scanf("%c", &c);
            if (!ft_isprint(c)) ft_putendl("not printable");
            else                ft_putendl("printable");
            fflush(stdin);
        }

        return (0);
}

*/
