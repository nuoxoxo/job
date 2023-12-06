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

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
        t_list      *p;

        p = begin_list;
        while (p)
        {
            f(p->data);
            p = p->next;
        }
}

/*

// DRIVE

#include <stdio.h>

t_list  *pp(int n, char **s);
t_list  *ce(void *d);
void    pf(void *s);

int     main(int argc, char **argv)
{
        t_list          *list;
        list = pp(argc, argv);
        printf("\nApply printf in foreach :\n\n");
        ft_list_foreach(list, &pf); printf("\n");
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

void    pf(void *s)
{
        printf("%s\n", (char*)s);
}

*/
