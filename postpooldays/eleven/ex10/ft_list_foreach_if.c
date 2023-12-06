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

void    ft_list_foreach_if \
        (t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)())
{
        t_list      *p;

        p = begin_list;
        while (p)
        {
            if (cmp(p->data, data_ref) == 0)
                f(p->data);
            p = p->next;
        }
}

/*

// DRIVE

#include <string.h>
#include <stdio.h>

t_list  *pp(int n, char **s);
t_list  *ce(void *d);
void    pf(void *s);
void    ft_list_foreach_if \
        (t_list *begin_list, void (*f)(void *), void *data_ref, int (*cmp)());

int     main(int argc, char **argv)
{
        t_list      *list;
        char        *str;

        str = "abc";
        list = pp(argc, argv);
        printf("\nApply &strcmp in foreach_if :\n\n");
        ft_list_foreach_if(list, &pf, str, &strcmp);
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

void    pf(void *s)
{
        printf("%s\n", (char*)s);
}

*/
