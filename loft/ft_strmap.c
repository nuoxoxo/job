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

char    *ft_strmap(char const *s, char (*f)(char))
{
        char    *res;
        size_t  i;

        if (!s || !f)
            return (NULL);
        res = (char *) malloc(ft_strlen(s) + 1);
        if (!res)
            return (NULL);
        i = -1;
        while (s[++i])
            res[i] = f(s[i]);
        res[i] = 0;
        return (res);
}

/*

//  DRIVE

//#include "ft_tolower.c"   //  don't know how tha5 works
//#include "ft_toupper.c"
#include "ft_putendl.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include <stdio.h>

#define OUT     ft_putendl("\n(ctrl + c to quit)\n--\n")
#define ENDL    ft_putendl("\n")
#define LOAD    loading()
#define OPT3    optionx3()

char    lower(char c);
char    upper(char c);
char    rot13(char c);
void    optionx3(void);
void    loading(void);

int     main(void)
{
        while (1)
        {
            int     max = 64, i;
            char    src[max], *des;

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
            if (i == 1) des = ft_strmap(src, &lower);
            if (i == 2) des = ft_strmap(src, &upper);
            if (i == 3) des = ft_strmap(src, &rot13);
            LOAD;
            ft_putstr("source : ");
            ft_putstr(src);
            ft_putstr("result : ");
            ft_putstr(des);
            fflush(stdin);
            OUT;
        }

        return (0);
}


//      helpers

char    rot13(char c)
{
        if ((c < 123 && c > 96) || (c < 91 && c > 64))
        {
            if (c > 109 || (c > 77 && c < 91))  c -= 13;
            else                                c += 13;
        }
        return (c);
}

char    upper(char c)
{
        if (c < 123 && c > 96)  c -= 32;
	return (c);
}

char    lower(char c)
{
	if (c >= 65 && c <= 90) c += 32;
	return (c);
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
