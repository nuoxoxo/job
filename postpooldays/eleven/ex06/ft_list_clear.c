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

void    ft_list_clear(t_list **begin_list)
{
        t_list  *ptr;

        if (*begin_list)
            return ;
        while   (*begin_list)
        {
            ptr = *begin_list;
            *begin_list = (*begin_list)->next;
            free(ptr);
        }
        *begin_list = NULL;
}

/*

// DRIVE

#include <stdio.h>

t_list  *pp(int n, char **s);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        (void)  argc;
        
        t_list  *p;
        int     i;

        if (!(p = pp(argc, argv)))  return 0;

        i = 0;
        printf("\nBefore : \n\n");
        
        while (p)
        {
            printf("[%i] : %s\n", i, (char*)p->data);
            p = p->next;
            i++;
        }

        ft_list_clear(&p);
        printf("\nAfter : %p\n\n", p);
}

t_list  *pp(int n, char **s)
{
        t_list  *head, *p;
        int     i = 1;

        if (n < 2)  return NULL;
        head = ce(s[i++]);
        p = head;
        while (i < n)
        {
            p->next = ce(s[i++]);
            p = p->next;
        }
        return  head;
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
