/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nxu <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/0_/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: 2021/0_/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list  *ce(void *d);

void    ft_list_push_front(t_list **begin_list, void *data)
{
        t_list  *ptr;

        if (!*begin_list)
            *begin_list = ce(data);
        else
        {
            ptr = ce(data);
            ptr->next = *begin_list;
            *begin_list = ptr;
        }
}

t_list  *ce(void *data)
{
        t_list  *ptr;

        ptr = malloc(sizeof(t_list));
        if (!ptr)
            return (NULL);
        ptr->data = data;
        ptr->next = NULL;
        return (ptr);
}

/*

// DRIVE

#include    <stdio.h>

int     main(int argc, char **argv)
{
        (void)  argc;
        
        char    *data1 = argv[1];
        int     data2 = atoi(argv[2]);
        t_list  *ptr;

        ptr = NULL;
        ft_list_push_front(&ptr, data1);
        printf("\nhead : %s\n", (char*)ptr->data);
        
        ft_list_push_front(&ptr, &data2);
        printf("\nhead : %i", *(int*)ptr->data);
        printf("\nnext : ");
        printf("%s\n\n", (char*)ptr->next->data);
}

*/
