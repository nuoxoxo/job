/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/__/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef FT_LIST_H
#define FT_LIST_H

typedef struct      s_list
{
    void            *data;
    struct  s_list  *next;
}                   t_list;

#endif
