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

t_list  *ft_lstmap(t_list *lst, t_list *(*f)(t_list *))
{
        t_list  *head;
        t_list  *ptr;

        if (!lst || !f)
            return (NULL);
        head = f(lst);
        ptr = head;
        while (lst)
        {
            if (ptr->next)
                ptr->next = f(lst->next);
            ptr = ptr->next;
            lst = lst->next;
        }
        return (head);
}

/*

//      DRIVE

#include "ft_lstpushback.c"
#include "ft_lstprint.c"
#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_lstnew.c"
#include "ft_putnbr.c"
#include "ft_strlen.c"
#include "ft_strclr.c"
#include "stdio.h"

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define OPT3    optionx3()
#define LOAD    loading()

void    apply_lstmap(t_list *lst, int option);
t_list  *lower(t_list *lst);
t_list  *upper(t_list *lst);
t_list  *rot13(t_list *lst);
void    optionx3(void);
void    loading(void);

int     main(void)
{
        t_list      **head, *p;
        int         max = 32, i;
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
            ft_lstprint(*head);
            ft_putstr("Add new list_item : ");
            fgets(s, max, stdin);
            s[ft_strlen(s) - 1] = 0;
            ft_lstpushback(head, ft_lstnew(s, max));
            OPT3;
            do
            {
                fflush(stdin);
                ft_putstr("\nchoose a function (1, 2 or 3) : ");
                scanf("%i", &i);
            }   while (i < 1 || i > 3);
            ENDL;
            apply_lstmap(*head, i);
        }
        return (0);
}

void    apply_lstmap(t_list *lst, int i)
{
        if (i == 1) ft_lstmap(lst, &lower);
        if (i == 2) ft_lstmap(lst, &upper);
        if (i == 3) ft_lstmap(lst, &rot13);
}

t_list  *rot13(t_list *lst)
{
        char    *c;

        c = (char *) lst->content;
        while (*c)
        {
            if ((*c < 123 && *c > 96) || (*c < 91 && *c > 64))
            {
                if (*c > 109 || (*c < 91 && *c > 77))   *c -= 13;
                else                                    *c += 13;
            }
            c++;
        }
        return (lst);
}

t_list  *upper(t_list *lst)
{
        char    *c;

        c = (char *) lst->content;
        while (*c)
        {
            if (*c < 123 && *c > 96)    *c -= 32;
            c++;
        }
        return (lst);
}

t_list  *lower(t_list *lst)
{
        char    *c;

        c = (char *) lst->content;
        while (*c)
        {
            if (*c >= 65 && *c <= 90)   *c += 32;
            c++;
        }
        return (lst);
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

void    optionx3(void)
{
        ft_putendl("\n1. tolower");
        ft_putendl("2. toupper");
        ft_putendl("3. rot13");
}

*/
