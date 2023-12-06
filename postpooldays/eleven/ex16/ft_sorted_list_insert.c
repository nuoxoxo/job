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

#include <stdlib.h>
#include "ft_list.h"

t_list  *ce(void *d);
void    push_front(t_list **head, void *data);
void    push_back(t_list **head, void *data);

void    ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)()) 
{
        t_list      *new;
        t_list      *p;

        p = *begin_list;
        if (!p || cmp(p->data, data) > 0)
        {
            push_front(begin_list, data);
            return ;
        }
        while (p)
        {
            if (p->next && cmp(p->next->data, data) > 0)
            {
                new = ce(data);
                new->next = p->next;
                p->next = new;
                return ;
            }
            if (!p->next)
            {
                push_back(&p, data);
                return ;
            }
            p = p->next;
        }
}

void    push_front(t_list **head, void *data)
{
        t_list  *p;

        if (!*head)
            *head = ce(data);
        else
        {
            p = ce(data);
            p->next = *head;
            *head = p;
        }
}

void    push_back(t_list **head, void *data)
{
        t_list  *p;

        if (!*head)
            *head = ce(data);
        else
        {
            p = *head;
            while (p->next) p = p->next;
            p->next = ce(data);
        }
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

/*

// DRIVE

#include <string.h>
#include <stdio.h>

void    list_sort(t_list **list, int (*cmp)());
void    list_print(t_list *list);
t_list  *pp(int n, char **s);

int     main(int argc, char **argv)
{
        t_list  *head;
        char    *data;

        data = "hello, world!";
        
        head = pp(argc, argv);
        printf("\nOriginal list : \n---------------\n");
        list_print(head);
        
        list_sort(&head, strcmp);
        printf("\nSorted list : \n---------------\n");
        list_print(head);
        
        ft_sorted_list_insert(&head, data, strcmp);
        printf("\n\"%s\" inserted : \n----------------------\n", data);
        list_print(head);

        printf("\n");
}

void    list_sort(t_list **list, int (*cmp)())
{
        t_list  *p;
        void    *temp;

        p = *list;
        if (!p) return ;
        while (p->next)
        {
            if (cmp(p->data, p->next->data) > 0)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                p = *list;
            }
            else    p = p->next;
        }
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
