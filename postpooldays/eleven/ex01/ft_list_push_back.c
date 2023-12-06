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

void    ft_list_push_back(t_list **begin_list, void *data)
{
        t_list  *ptr;

        if (!*begin_list)
            *begin_list = ce(data);
        else
        {
            ptr = *begin_list;
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = ce(data);
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

#include <stdio.h>

int     main(int argc, char **argv)
{
        (void)  argc;
        char    *data1 = argv[1];
        int     data2 = atoi(argv[2]);
        t_list  *ptr;
        
        ptr = NULL;
        ft_list_push_back(&ptr, data1);
        printf("\n%s\n", (char*)ptr->data);
        printf("%p <----- null\n", ptr->next);

        ft_list_push_back(&ptr, &data2);
        printf("\n%s\n", (char*)ptr->data);
        printf("%i <----- this int is added here\n\n", *(int*)ptr->next->data);
}

*/
