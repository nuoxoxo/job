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

//      argument pointer to a memory area needs to be freed
//      set pointer to NULL
//      same logic as ft_strdel()
//      **  added one condition: don't call free() on a null ptr

#include "libft.h"

void	ft_memdel(void **ap)
{
        if (!ap || !*ap)
            return ;
	free(*ap);
	*ap = NULL;
}
