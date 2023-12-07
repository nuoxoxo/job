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

t_list  *ft_lstnew(void const *content, size_t content_size)
{
        t_list  *lst;

        lst = (t_list *) malloc(sizeof(t_list));
        if (!lst)
            return (NULL);
        lst->content = (void *) malloc(content_size + 1);
        if (!(lst->content))
        {
            free(lst);
            return (NULL);
        }
        if (!content_size || !content)
        {
            lst->content_size = 0;
            lst->content = NULL;
            lst->next = NULL;
            return (lst);
        }
        ft_memcpy(lst->content, content, content_size);
        lst->content_size = content_size;
        lst->next = NULL;
        return (lst);
}

/*

//      DRIVE

#include "ft_lstprint.c"
#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strclr.c"
#include "ft_strlen.c"
#include "ft_putnbr.c"
#include "ft_memcpy.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()

void    loading(void);

int     main(void)
{
        int     max = 32;
        char    s[ max ];

        while (1)
        {
            t_list  *lst;

            ft_putstr("Enter content : ");
            fgets(s, max, stdin);
            s[ ft_strlen(s) - 1 ] = 0;
            lst = ft_lstnew(s, max);
            LOAD;
            ft_lstprint(lst);
            ft_strclr(s);
            fflush(stdin);
            free(lst->content);
            free(lst);
            OUT;
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
