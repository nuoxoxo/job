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

void    ft_lstprint(t_list *lst)
{
        int     i;

        i = 0;
        while (lst)
        {
            ft_putstr("node no. ");
            ft_putnbr(i);
            ft_putendl("");
            ft_putstr("content: ");
            ft_putendl((char *) lst->content);
            ft_putstr("size   : ");
            ft_putnbr((int) lst->content_size);
            ft_putendl("\n-");
            lst = lst->next;
            i++;
        }
}

/*

//      DRIVE

#include "ft_putnbr.c"
#include "ft_lstnew.c"
#include "ft_strlen.c"
#include "ft_putstr.c"
#include "ft_putendl.c"
#include <stdio.h>

int     main(void)
{
        while (1)
        {
            int     max = 32;
            char    s1[max], s2[max], s3[max];
            t_list  *p;

            ft_putendl("(Create a 3-item linked list)");
            ft_putstr("Enter s1 : ");
            fgets(s1, max, stdin);
            ft_putstr("Enter s2 : ");
            fgets(s2, max, stdin);
            ft_putstr("Enter s3 : ");
            fgets(s3, max, stdin);
            s1[(ft_strlen(s1) - 1)] = 0;
            s2[(ft_strlen(s2) - 1)] = 0;
            s3[(ft_strlen(s3) - 1)] = 0;
            p = ft_lstnew(s1, max);
            p->next = ft_lstnew(s2, max);
            p->next->next = ft_lstnew(s3, max);
            ft_lstprint(p);
            fflush(stdin);
        }
        return (0);
}

*/
