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

void    list_merge(t_list **begin_list1, t_list *begin_list2);
void    list_sort(t_list **begin_list, int (*cmp)());

void    ft_sorted_list_merge(t_list **begin_list1, \
        t_list *begin_list2, int (*cmp)())
{
        list_merge(begin_list1, begin_list2);
        list_sort(begin_list1, cmp);
}

void    list_merge(t_list **begin_list1, t_list *begin_list2)
{
        t_list      *head;

        if (!begin_list2)   return ;
        if (!*begin_list1 && begin_list2)
        {
            *begin_list1 = begin_list2;
            return ;
        }
        head = *begin_list1;
        while (head->next)  head = head->next;
        head->next = begin_list2;
}

void    list_sort(t_list **begin_list, int (*cmp)())
{
        t_list  *p;
        void    *temp;

        p = *begin_list;
        if (!p) return ;
        while (p->next)
        {
            if (cmp(p->data, p->next->data) > 0)
            {
                temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
                p = *begin_list;
            }
            else
                p = p->next;
        }
}



// DRIVE

#include <string.h>
#include <stdio.h>

t_list  *pp(int n, char **s);
t_list  *ce(void *d);
void    list_print(t_list *p);

int     main(int argc, char **argv)
{
        t_list      *list_1;
        t_list      *list_2, *list_3, *list_4, *list_5, *list_6;
        
        list_1 = pp(argc, argv);
        list_2 = ce((char *)"hello, world!");
        list_3 = ce((char *)"1024");
        list_4 = ce((char *)"Good morning.");
        list_5 = ce((char *)"+ (plus sign)");
        list_6 = ce((char *)"  (space)");
        list_2->next = list_3;
        list_3->next = list_4;
        list_4->next = list_5;
        list_5->next = list_6;
        
        printf("\n\n- Here is list 1 : \n");
        list_print(list_1);
        printf("\n- Here is list 2  :\n");
        list_print(list_2);
        
        ft_sorted_list_merge(&list_1, list_2, strcmp);
        printf("\n- Merged & sorted :\n");
        list_print(list_1);
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


