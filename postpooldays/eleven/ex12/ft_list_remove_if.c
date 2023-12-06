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

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
        t_list      *temp;
        t_list      *p;

        while (*begin_list && !cmp((*begin_list)->data, data_ref))
        {
            temp = *begin_list;
            *begin_list = (*begin_list)->next;
            free(temp);
        }
        p = *begin_list;
        while (p && p->next)
        {
            if (!cmp(p->next->data, data_ref))
            {
                temp = p->next;
                p->next = p->next->next;
                free(temp);
            }
            else
                p = p->next;
        }

}

/*

// DRIVE

#include <string.h>
#include <stdio.h>

void    ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)());
void    put_list(t_list *list);
t_list  *pp(int n, char **s);
t_list  *ce(void *d);

int     main(int argc, char **argv)
{
        t_list      *list;
        char        *word;
        
        list = pp(argc, argv);
        word = "64";
        printf("\nOriginal list : \n\n");
        put_list(list);
        printf("\nNow remove : %s\n\n", word);
        printf("\nAfter removal : \n\n");
        ft_list_remove_if(&list, word, &strcmp);
        put_list(list);
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

void    put_list(t_list *list)
{
        t_list      *p;

        p = list;
        while (p)
        {
            printf("%s\n", (char*)p->data);
            p = p->next;
        }
        printf("\n");
}

*/
