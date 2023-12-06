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

void    ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
        t_list      *head;

        if (!begin_list2)
            return ;
        if (!*begin_list1 && begin_list2)
        {
            *begin_list1 = begin_list2;
            return ;
        }
        head = *begin_list1;
        while (head->next)
            head = head->next;
        head->next = begin_list2;
}

/*

// DRIVE

#include <stdio.h>

t_list  *pp(int n, char **s);
t_list  *ce(void *d);
void    ft_list_merge(t_list **begin_list1, t_list *begin_list2);
void    list_print(t_list *p);

int     main(int argc, char **argv)
{
        t_list      *list_1;
        t_list      *list_2, *list_3, *empty;
        
        list_1 = pp(argc, argv);
        list_2 = ce((char *)"hello world");
        list_3 = ce((char *)"good music");
        list_2->next = list_3;
        
        printf("\n\n- Here is list 1 : \n");
        list_print(list_1);
        printf("\n- Here s list 2 : \n");
        list_print(list_2);
        
        ft_list_merge(&list_1, list_2);
        
        printf("\n- Lists 1 & 2 merged : \n");
        list_print(list_1);
        
        printf("\n- If a null list is merged : \n");
        
        empty = NULL;
        ft_list_merge(&list_1, empty);
        list_print(list_1);
        
        printf("\n"); 
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
        if (!p) return NULL;
        p->data = data;
        p->next = NULL;
        return (p);
}

void    list_print(t_list *p)
{
        while (p)
        {
            printf("%s\n", (char *)p->data);
            p = p->next;
        }
        printf("\n");
}

*/
