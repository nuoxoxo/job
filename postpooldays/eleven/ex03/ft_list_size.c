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

int     ft_list_size(t_list *begin_list)
{
        t_list  *ptr;
        int     i;

        i = 0;
        ptr = begin_list;
        if (!ptr)
            return (i);
        while (ptr)
        {
            i++;
            ptr = ptr->next;
        }
        return (i);
}

/*

// DRIVE

#include <stdlib.h>
#include <stdio.h>

t_list  *pp(int x, char **y);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        t_list  *lst, *p;

        lst = pp(argc, argv);
        p = lst;
        printf("\nsize : %i\n\nlist : \n\n", ft_list_size(lst));
        while (p)
        {
            printf("%s\n", (char*)p->data); p = p->next;
            if (!p) printf("\n");
        }
}

t_list  *pp(int ac, char **av)
{
        t_list  *head;
        t_list  *p;
        int     i;

        i = 1;
        if (ac < 2) return (NULL);
        head = ce(av[i++]);
        p = head;
        while (i < ac)
        {
            p->next = ce(av[i++]);
            p = p->next;
        }
        return (head);
}

t_list  *ce(void *data)
{
        t_list  *p;

        p = malloc(sizeof(t_list));
        if (!p) return (NULL);
        p->data = data;
        p->next = NULL;
        return (p);
}

*/
