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

//      Frees the memory of this link and every successor with del and free(3).
//      set the pointer to NULL

#include "libft.h"

void    ft_lstdel(t_list **lst, void (*del)(void *, size_t))
{
        t_list  *ptr;

        if (!(*lst) || !(*del))
            return ;
        while (*lst)
        {
            ptr = (*lst)->next;
            del((*lst)->content, (*lst)->content_size);
            free(*lst);
            *lst = ptr;
        }
}

/*
typedef struct      s_list
{
    void            *content;
    size_t          content_size;
    struct s_list   *next;
}                   t_list;
*/
