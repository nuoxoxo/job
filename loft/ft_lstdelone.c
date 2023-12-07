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

//      given a pointer to a link
//      free the memory of the link’s content using del()
//      free the link’s memory using free()
//      the memory of next must not be freed under any circumstance

#include "libft.h"

void    ft_lstdelone(t_list **lst, void (*del)(void *, size_t))
{
        t_list  *ptr;

        ptr = NULL;
        if (!(*lst) || !(*del))
            return ;
        del((*lst)->content, (*lst)->content_size);
        free(*lst);
        *lst = ptr;
}

/*
typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;
*/
