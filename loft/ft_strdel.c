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

//      address of a string needs to be freed
//      set its pointer to NULL
//      same logic as ft_memdel()

#include "libft.h"

void    ft_strdel(char **str_arr)
{
        if (!str_arr || !*str_arr)
            return ;
	free(*str_arr);
	*str_arr = NULL;
}
