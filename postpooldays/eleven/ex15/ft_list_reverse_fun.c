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

void    ft_list_reverse_fun(t_list *begin_list)
{
        t_list  *curr;
        void    *temp;
        int     size, i, j;

        curr = begin_list;
        size = 0;
        while (curr)
        {
            size++;
            curr = curr->next;
        } 
        i = 0;
        while (i < size - 1)
        {
            j = i;
            curr = begin_list;
            while (j < size - 1)
            {
                temp = curr->data;
                curr->data = curr->next->data;
                curr->next->data = temp;
                curr = curr->next;
                j++;
            }
            i++;
        }
}

/*

// DRIVE

#include    <stdio.h>

t_list  *pp(int n, char **s);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        t_list  *p;
        t_list  *ptr1;
        t_list  *ptr2;
        int     i;
        
        p = pp(argc, argv);
        ptr1 = p;
        i = 0;
        printf("\noriginal list \n\n");
        
        while (ptr1)
        {
            printf("[%i] : %s\n", i, (char*)ptr1->data);
            ptr1 = ptr1->next;
            i++;
        }
        printf("\n");

        ft_list_reverse_fun(p);
        i = 0;
        
        ptr2 = p;
        printf("reversed list \n\n");
        while (ptr2)
        {
            printf("[%i] : %s\n", i, (char*)ptr2->data);
            ptr2 = ptr2->next;
            i++;
        }
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
        if (!p) return (NULL);
        p->data = data;
        p->next = NULL;
        return (p);
}

*/
