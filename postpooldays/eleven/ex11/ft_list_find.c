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

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
        t_list      *p;

        p = begin_list;
        while (p)
        {
            if (cmp(p->data, data_ref) == 0)
                return (p);
            p = p->next;
        }
        return (NULL);
}

/*

// DRIVE

#include <string.h>
#include <stdio.h>

t_list  *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
t_list  *pp(int n, char **s);
t_list  *ce(void *d);
void    put_ptr(void *p);

int     main(int argc, char **argv)
{
        t_list      *list;
        char        *word;

        list = pp(argc, argv);
        word = "good";
        printf("\nAddress of the first word \"%s\" :\n\n", word);
        put_ptr(ft_list_find(list, word, &strcmp)); printf("\n");
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

void    put_ptr(void *p)
{
        printf("%p\n", p);
}

*/
