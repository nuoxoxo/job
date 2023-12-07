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
#include "ft_strlen.c"

void    ft_striter(char *s, void (*f)(char *))
{
        if (!s || !f)
            return ;
        while (*s)
            f(s++);
}

/*

//  DRIVE

//#include "ft_tolower.c"   //  don't know how tha5 works
//#include "ft_toupper.c"
#include "ft_putendl.c"
#include "ft_putstr.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()
#define OPT3    optionx3()

void    lower(char *c);
void    upper(char *c);
void    rot13(char *c);
void    optionx3(void);
void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 64, i;
            char    src[max];

            ft_putstr("enter your string : ");
            fgets(src, max, stdin);
            OPT3;
            fflush(stdin);
            do
            {
                ft_putstr("\nchoose a function (1, 2 or 3) : ");
                scanf("%i", &i);
            }
            while (i < 1 || i > 3);
            LOAD;
            ft_putstr("source : ");
            ft_putstr(src);
            if (i == 1) ft_striter(src, &lower);
            if (i == 2) ft_striter(src, &upper);
            if (i == 3) ft_striter(src, &rot13);
            ft_putstr("result : ");
            ft_putstr(src);
            fflush(stdin);
            OUT;
        }

        return (0);
}


//      helpers

void    rot13(char *c)
{
        if ((*c < 123 && *c > 96) || (*c < 91 && *c > 64))
        {
            if (*c > 109 || (*c > 77 && *c < 91))
                *c -= 13;
            else
                *c += 13;
        }
}

void    upper(char *c)
{
        if (*c < 123 && *c > 96)
            *c -= 32;
}

void    lower(char *c)
{
	if (*c >= 65 && *c <= 90)
            *c += 32;
}

//

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
