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

t_list  *ft_list_last(t_list *begin_list)
{
        t_list      *end;

        end = begin_list;
        if (!end)
            return (NULL);
        while (end->next)
            end = end->next;
        return (end);
}

/*

// DRIVE

#include <stdio.h>

t_list  *pp(int argc, char **argv);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        t_list  *p;
        int     i;

        if (!(p = pp(argc, argv)))  return 0;


        printf("\ndata of the last item : %s\n", (char*)ft_list_last(p)->data);
        printf("\nthe full list : \n");
        
        i = 0;
        while (p)
        {
            printf("[%i] : %s\n", i, (char*)p->data);
            p = p->next;
            i++;
        }

        printf("\n");
}

t_list  *pp(int ac, char **av)
{
        t_list  *head, *p;
        int     i = 1;
        
        if (ac < 2) return NULL;
        head = ce(av[i++]);
        p = head;
        while   (i < ac)
        {
                p->next = ce(av[i++]);
                p = p->next;
        }
        return  head;
}

t_list  *ce(void *data)
{
        t_list  *p;
        
        p = malloc(sizeof(t_list));
        if (!p) return NULL;
        p->data = data;
        p->next = NULL;
        return  p;
}

*/
