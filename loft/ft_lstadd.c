/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ___ <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: ____/__/__ __:__:__ by nxu               #+#    #+#             */
/*   Updated: ____/__/__ __:__:__ by nxu              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_lstadd(t_list **lst, t_list *new)
{
        new->next = *lst;
        *lst = new;
}

/*

//      DRIVE

#include "ft_lstprint.c"
#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_lstnew.c"
#include "ft_putnbr.c"
#include "ft_strlen.c"
#include "ft_strclr.c"
#include "ft_memcpy.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        t_list      **head, *p;
        int         max = 32;
        char        s[ max ];

        head = (t_list **) malloc(sizeof(t_list));
        if (!head)
            return (1);
        ft_putstr("Enter content : ");
        fgets(s, max, stdin);
        s[ft_strlen(s) - 1] = 0;
        p = ft_lstnew(s, max);
        *head = p;
        while (1)
        {
            ft_strclr(s);
            fflush(stdin);
            LOAD;
            ft_lstprint(*head);
            OUT;
            ft_putstr("Add new list_item : ");
            fgets(s, max, stdin);
            s[ft_strlen(s) - 1] = 0;
            ft_lstadd(head, ft_lstnew(s, max));
        }
        return (0);
}

void    loading(void)
{
        int     rand;

        rand = 1000 * 32;
        ft_putstr("loading");
        for (int i = 12; i > 0; i--)
        {
            usleep(rand);
            ft_putstr(".");
        }
        ENDL;
}

*/
