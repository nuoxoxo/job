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

void    ft_list_reverse(t_list **begin_list)
{
        t_list  *self;
        t_list  *p;
        t_list  *n;

        if (*begin_list)
        {
            self = *begin_list;
            p = NULL;
            n = NULL;
            while (self)
            {
                n = self->next;
                self->next = p;
                p = self;
                self = n;
            }
            *begin_list = p;
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
        t_list  *ptr1 = NULL;
        t_list  *ptr2 = NULL;
        int     i;
        
        p = pp(argc, argv);
        ptr1 = p;
        i = 0;

        printf("\noriginal list \n\n");
        while (i < argc - 1)
        {
            printf("[%i] : %s\n", i, (char*)ptr1->data);
            ptr1 = ptr1->next;
            i++;
        }
        printf("\n");

        ft_list_reverse(&p);
        ptr2 = p;
        i = 0;

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
