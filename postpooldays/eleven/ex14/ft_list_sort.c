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

void    ft_list_sort(t_list **begin_list, int (*cmp)())
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

/*

// DRIVE

#include <string.h>
#include <stdio.h>

void    ft_list_sort(t_list **begin_list, int (*cmp)());
t_list  *pp(int n, char **s);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        t_list      *p;
        t_list      *head;

        p = pp(argc, argv);
        head = p;
        printf("\nlist unsorted :\n------------\n");
        while (head)
        {
            printf("%s\n", (char *)head->data);
            head = head->next;
        }
        printf("------------");
        ft_list_sort(&p, strcmp);
        head = p;
        printf("\nlist sorted : \n------------\n");
        while (head)
        {
            printf("%s\n", (char*)head->data);
            head = head->next;
        }
        printf("------------\n");
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

*/
